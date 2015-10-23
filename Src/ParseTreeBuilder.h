#pragma once
#ifndef __PARSETREEBUILDER_H_
#define __PARSETREEBUILDER_H_

#include "ParseNode.h"

class ParseTreeBuilder
{
public:
	ParseTreeBuilder(std::vector<Token> tokenstream);
	~ParseTreeBuilder();

private:
	void buildParseTree();
private:
	ParseNode* m_treeroot;
	ParseNode* currentNode;
	std::vector<Token> m_tokenstream;
};


#endif