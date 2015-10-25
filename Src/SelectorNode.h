#pragma once
#ifndef __SELECTORNODE_H_
#define __SELECTORNODE_H_

#include <vector>
#include "Token.h"
#include "Selector.h"

class SelectorNode
{
public:


	//create SelectorNode tree recursively in construct function
	SelectorNode(std::vector<Token> currentstream, 
				std::string selectorname,
		std::vector<std::map<std::string, Token>*> valuetables);
	SelectorNode();
	~SelectorNode();

	std::vector<SelectorNode*>& getChilds();
	std::string getSelectContent();
private:
	std::vector<Token> m_currentstream;
	Selector m_localselector;
	std::vector<SelectorNode*> m_childs;
	std::vector<std::map<std::string, Token>*> valuetables;
};



#endif