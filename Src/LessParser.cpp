#include "LessParser.h"
#include "Token.h"
#include <iostream>
using namespace std;
LessParser::LessParser(Tokenizer * tokenizer)
{
	this->m_tokenizer = tokenizer;
	this->valueTable = map<string, Token>();
	this->valuetablestack = stack<map<string, Token>>();
	this->valuetablestack.push(valueTable);


	//here choose list struct for faster add operation
	list<Token> tokenlist = list<Token>();
	while (m_tokenizer->readNextToken()!=Token::EOS)
	{
		tokenlist.push_back(tokenizer->getToken());
	}

	//copy list to vector for easer operation at behind
	this->tokenstream = vector<Token>(tokenlist.begin(), tokenlist.end());

}

LessParser::~LessParser()
{

}

void LessParser::showTokens()
{
	for (vector<Token>::iterator it = tokenstream.begin(); it != tokenstream.end(); it++)
	{
		cout << it->getLexem() << endl;
	}
	createValueTables();
}

void LessParser::parse()
{

}

void LessParser::createValueTables()
{
	stack<vector<Token>::iterator> akwdtrplc;
	for (vector<Token>::iterator it = tokenstream.begin(); it != tokenstream.end(); it++)
	{
		switch (it->getType())
		{
		case Token::ATKEYWORD:
			if ((it+1)->getType() == Token::COLON)
			{
				valuetablestack.top().insert(pair<string, Token>(it->getLexem(), *(it + 2)));
			}
			else if ((it + 1)->getType() == Token::DELIMITER)
			{
				akwdtrplc.push(it);
			}

			break;
		case Token::DOTTOKEN:
		case Token::HASH:

			break;
		case Token::BRACE_OPEN:
			this->valuetablestack.push(map<string, Token>());
			break;
		case Token::BRACE_CLOSED:


			//this->valuetablestack.pop();
			break;
		default:
			break;
		}
	}
}
