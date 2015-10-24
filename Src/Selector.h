#pragma once
#ifndef __SELECTOR_H_
#define __SELECTOR_H_

#include <vector>
#include "Token.h"
#include <map>

class Selector
{
public:
	Selector(std::string head);
	Selector();
	~Selector();
	

	std::string writeYouself(); //return processed string 
	void addToken(Token t); //add tokens to selector streams;
	std::vector<std::map<std::string, Token>&>& Selector::getValueTables();
	std::string getHeadName();

private:
	std::vector<Token> selectorStream;
	std::vector<std::map<std::string, Token>&> valuetables; //
	
	std::string m_head;
	std::map<std::string, std::string> attributes;
};



#endif