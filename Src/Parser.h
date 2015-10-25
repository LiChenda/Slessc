#pragma once
#ifndef __PARSER_H_
#define __PARSER_H_

#include "Token.h"
#include "Selector.h"
#include "Tokenizer.h"
#include "SelectorNode.h"

class Parser
{
public:
	Parser(Tokenizer& tokenizer);
	~Parser();

	//out put css file by traversing the selector tree
	void printTree(SelectorNode* rootnode);
	SelectorNode* getRootNode();
private:
	std::vector<Token> tokenstream;
	//
	SelectorNode* rootnode;

};




#endif