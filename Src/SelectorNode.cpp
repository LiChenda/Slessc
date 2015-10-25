#include "SelectorNode.h"
using namespace std;
SelectorNode::SelectorNode(vector<Token> currentstream, 
	string selectorname,
	vector<map<string, Token>*> valuetables)
{
	this->m_localselector = Selector(selectorname);
	this->m_currentstream = currentstream;
	this->valuetables = valuetables;
	this->m_childs = vector<SelectorNode*>();



	enum CurrentStatus
	{
		ONVALUATION,
		INSELECTOR,
		OTHERS,
	};

	CurrentStatus crrstate = OTHERS;
	int braceposet = 0;
	string subname = "";
	vector<Token> substream = vector<Token>();
	vector<Token> toprocess = vector<Token>();
	this->valuetables.push_back(new map<string, Token>());
	for (vector<Token>::iterator itr = currentstream.begin(); itr != currentstream.end(); itr++)
	{
		bool isselecthead = false;
		switch (itr->getType())
		{
		case Token::ATKEYWORD:
			if (crrstate != INSELECTOR && (itr+1)->getType() == Token::COLON)
			{
				crrstate = ONVALUATION;
			}
			break;
		case Token::DELIMITER:
			if (crrstate == ONVALUATION)
			{
				crrstate = OTHERS;
				continue;
			}
			break;
		case Token::COLON:
			if (crrstate == ONVALUATION)
			{
				//pair<string, Token> toinsert = pair<string, Token>((itr-1)->getLexeme(), *(itr+1));
				map<string, Token>* topmap = this->valuetables.at(this->valuetables.size() - 1);
				(*topmap)[(itr - 1)->getLexeme()] = *(itr + 1);
				//(*(this->valuetables.end()))->insert(toinsert);
				//(**(valuetables.end()))[(itr - 1)->getLexeme()] = *(itr + 1);
			}
			break;
		case Token::DOTTOKEN:
		case Token::HASH:
		//case Token::IDENTIIFER:
			if (crrstate == OTHERS)
			{
				subname = itr->getLexeme();
			}
			if (crrstate == OTHERS||(itr+1)->getType() == Token::BRACE_OPEN)
			{
				isselecthead = true;
			}
			break;
		case Token::BRACE_OPEN:
			if (braceposet == 0 && (
				(itr-1)->getType() == Token::DOTTOKEN ||
				(itr-1)->getType() == Token::HASH ||
				(itr-1)->getType() == Token::IDENTIIFER
				))
			{
				crrstate = INSELECTOR;
				itr++;
				//continue;
			}
			braceposet++;
			break;
		case Token::BRACE_CLOSED:
			braceposet--;
			if (braceposet == 0)
			{
				crrstate = OTHERS;
				this->m_childs.push_back(new SelectorNode(substream, 
					this->m_localselector.getHeadName() +" "+ subname,
					this->valuetables));
				substream.clear();
				continue;
				//this->valuetables.pop_back();
			}
			break;
		default:
			break;
		}
		if (crrstate == INSELECTOR)
		{
			substream.push_back(*itr);
		}
		else if (crrstate == OTHERS && ! isselecthead)
		{
			toprocess.push_back(*itr);
		}

	}
	this->m_localselector.setTokenStream(toprocess);
	this->m_localselector.getValueTables() = this->valuetables;
}

SelectorNode::SelectorNode()
{
}

SelectorNode::~SelectorNode()
{
}

std::vector<SelectorNode*>& SelectorNode::getChilds()
{
	return this->m_childs;
}

std::string SelectorNode::getSelectContent()
{
	return this->m_localselector.writeYourself();
}
