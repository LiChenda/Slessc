#pragma once
#ifndef __PARSER_H_
#define __PARSER_H_

#include "Token.h"
#include "Selector.h"
#include "Tokenizer.h"

class Parser
{
public:
	Parser(Tokenizer& tokenizer);
	~Parser();

private:
	std::vector<Token> tokenstream;
	
	void generateSelector(std::vector<Token> currntstream);

};


#endif