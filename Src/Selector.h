#pragma once
#ifndef __SELECTOR_H_
#define __SELECTOR_H_

#include <vector>
#include <map>

#include "Token.h"

class Selector
{
public:
	Selector(std::string head);
	Selector();
	~Selector();
	

	std::string writeYourself(); //return processed string 
	void addToken(Token t); //add tokens to selector streams;
	std::vector<std::map<std::string, Token>*>& getValueTables();
	std::string getHeadName();

private:
	std::vector<Token> selector_stream;
	std::vector<std::map<std::string, Token>*> valuetables;
	
	std::string m_head;
    size_t pos = 0;
	std::map<std::string, std::string> attributes;

    bool readAttribute();
    std::string readExpression();
};
#endif
