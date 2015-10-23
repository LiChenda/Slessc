#pragma once
#ifndef __PARSENODE_H_
#define __PARSENODE_H_
#include <vector>
#include "Token.h"

class ParseNode
{
public:
	enum NodeType
	{
		KEYPAIR,
		STATEMENT,
		EXPRESSION,
		TERM,
		FACTOR,
		VALUE,
		BLOCK,
		FUNCTION,
		ENDTOKEN,
		SELECTOR,
		UNDEFINE,
	};
	ParseNode(Token t);
	ParseNode(Token t, ParseNode::NodeType nt);
	ParseNode();
	~ParseNode();
public:
	bool addChild(ParseNode* child);
	bool setParent(ParseNode* parent);
	ParseNode* getParent();
	NodeType getNodeType();
	void setNodeType(NodeType t);
	Token::Type getTokenType();
private:
	std::vector<ParseNode*> m_childs;
	ParseNode* m_parent;
	Token m_token;
	NodeType m_type;
};


#endif