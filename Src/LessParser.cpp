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
	createValueTables();
	for (vector<Token>::iterator it = tokenstream.begin(); it != tokenstream.end(); it++)
	{
		cout <<it->getLexeme() << endl;
	}
	
}

void LessParser::parse()
{

}

void LessParser::createValueTables()
{
	stack<vector<vector<Token>::iterator>> vartoreplacestack;
	vartoreplacestack.push(vector<vector<Token>::iterator>());
	for (vector<Token>::iterator it = tokenstream.begin(); it != tokenstream.end(); it++)
	{
		stack<std::map<std::string, Token>> temp;
		switch (it->getType())
		{
		case Token::ATKEYWORD:
			if ((it+1)->getType() == Token::COLON)
			{
				valuetablestack.top().insert(pair<string, Token>(it->getLexeme(), *(it + 2)));
			}
			else if ((it + 1)->getType() == Token::DELIMITER)
			{
				vartoreplacestack.top().push_back(it);
			}

			break;
		case Token::DOTTOKEN:
		case Token::HASH:

			break;
		case Token::BRACE_OPEN:
			this->valuetablestack.push(map<string, Token>());
			vartoreplacestack.push(vector<vector<Token>::iterator>());
			break;
		case Token::BRACE_CLOSED:
			//valuetablestack.pop();
			temp = stack<std::map<std::string, Token>>(this->valuetablestack);
			for (vector<vector<Token>::iterator>::iterator
				itr = vartoreplacestack.top().begin(); itr != vartoreplacestack.top().end(); itr++)
			{
				string atkey =  (*itr)->getLexeme();
				std::map<std::string, Token>::iterator findkey;
				
				while (true)
				{
					findkey = temp.top().find(atkey);
					if (findkey == temp.top().end())
					{
						temp.pop();
					}
					else
					{
						break;
					}
					

				}
			

				**itr = findkey->second;
				
			}
			vartoreplacestack.pop();
			this->valuetablestack.pop();
			break;
		default:
			break;
		}
	}
}
