#include "Parser.h"
#include <list>

using namespace std;

Parser::Parser(Tokenizer& tokenizer)
{
	list<Token> tokenlist = list<Token>();
	while (tokenizer.readNextToken() != Token::EOS)
	{
		tokenlist.push_back(tokenizer.getToken());
	}
	this->tokenstream = vector<Token>(tokenlist.begin(), tokenlist.end());
	vector<map<string, Token>*> valuetables = vector<map<string, Token>*>();
	this->rootnode = new SelectorNode(tokenstream, "", valuetables);
}

Parser::~Parser()
{
}

void Parser::printTree(SelectorNode * rootnode)
{
	for (auto child : rootnode->getChilds()) 
	{
		cout << child->getSelectContent() << endl;
		printTree(child);
	}
}

SelectorNode * Parser::getRootNode()
{
	return this->rootnode;
}

void Parser::generateSelector(vector<Token> currntstream)
{
	for (vector<Token>::iterator itr = currntstream.begin(); itr != currntstream.end(); itr++)
	{
		switch (itr->getType())
		{
		case Token::ATKEYWORD:
			break;
		case Token::HASH:
		case Token::DOTTOKEN:
			if ((itr+1)->getType() == Token::BRACE_OPEN)
			{
			}
			break;
		case Token::BRACE_OPEN:
			break;
		case Token::BRACKET_CLOSED:
			break;
		default:
			break;
		}
	}
}
