#include "Parser.h"
#include <list>

using namespace std;

Parser::Parser(Tokenizer& tokenizer)
{
	list<Token> tokenlist = list<Token>();
	//save tokens form tokenizer
	while (tokenizer.readNextToken() != Token::EOS)
	{
		tokenlist.push_back(tokenizer.getToken());
	}
	this->tokenstream = vector<Token>(tokenlist.begin(), tokenlist.end());
	
	//build selector tree by construct method of SelectorNode class
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

