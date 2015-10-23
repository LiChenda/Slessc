#include "ParseNode.h"
#include <iostream>
using namespace std;


ParseNode::ParseNode(Token t)
{
	ParseNode();
	this->m_token = t;
}

ParseNode::ParseNode(Token t, ParseNode::NodeType nt)
{
	ParseNode(t);
	this->setNodeType(nt);
}

ParseNode::ParseNode()
{
	this->m_childs = vector<ParseNode*>();
	this->m_parent = nullptr;
	this->m_type = UNDEFINE;
}

ParseNode::~ParseNode()
{
	for (vector<ParseNode*>::iterator it; it != m_childs.end(); it++)
	{
		if (*it != nullptr)
		{
			delete(*it);
			*it = nullptr;
		}
	}
}

bool ParseNode::addChild(ParseNode * child)
{
	this->m_childs.push_back(child);
	child->setParent(this);
	return true;
}

bool ParseNode::setParent(ParseNode * parent)
{
	this->m_parent = parent;
	return true;
}

ParseNode * ParseNode::getParent()
{
	return this->m_parent;
}

ParseNode::NodeType ParseNode::getNodeType()
{
	return this->m_type;
}

void ParseNode::setNodeType(NodeType t)
{
	this->m_type = t;
}

Token::Type ParseNode::getTokenType()
{
	if (m_type == UNDEFINE)
	{
		cout << "WARN: Return Undefined Type" << endl;
	}
	return this->m_token.getType();
}

