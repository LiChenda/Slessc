#pragma once
#ifndef __LESSPARSER_H_
#define __LESSPARSER_H_

#include <map>
#include <vector>
#include <list>
#include <stack>
#include "Tokenizer_fake.h"

class LessParser 
{
public:
	LessParser(Tokenizer* tokenizer);
	~LessParser();
	void showTokens(); //for test
private:
	Tokenizer* m_tokenizer;
	std::vector<Token> tokenstream;
	std::map<std::string, Token> valueTable;
	std::stack<std::map<std::string, Token>> valuetablestack;
private:
	void parse();
	void createValueTables();
};



#endif 