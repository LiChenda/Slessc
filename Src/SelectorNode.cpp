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
	this->valuetables.push_back(new map<string, Token>);
	for (vector<Token>::iterator itr = currentstream.begin(); itr != currentstream.end(); itr++)
	{
		switch (itr->getType())
		{
		case Token::ATKEYWORD:
			if ((itr+1)->getType == Token::COLON)
			{
				crrstate = ONVALUATION;
			}
			break;
		case Token::DELIMITER:
			if (crrstate == ONVALUATION)
			{
				crrstate = OTHERS;
			}
			break;
		case Token::COLON:
			if (crrstate == ONVALUATION)
			{
				(**(valuetables.end()))[(itr - 1)->getLexeme] = *(itr + 1);
			}
			break;
		case Token::DOTTOKEN:
		case Token::HASH:
		case Token::IDENTIIFER:
			if (crrstate == OTHERS)
			{
				subname = itr->getLexeme();
			}
			break;
		case Token::BRACE_OPEN:
			if (braceposet == 0 && (
				(itr-1)->getType == Token::DOTTOKEN ||
				(itr-1)->getType == Token::HASH ||
				(itr-1)->getType == Token::IDENTIIFER
				))
			{
				crrstate = INSELECTOR;
			}
			braceposet++;
			break;
		case Token::BRACE_CLOSED:
			braceposet--;
			if (braceposet == 0)
			{
				crrstate = OTHERS;
			}
			break;
		default:
			break;
		}
	}
}



SelectorNode::~SelectorNode()
{
}
