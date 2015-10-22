#include "Token.h"

Token::Token()
{
}

Token::~Token()
{
}

Token::Token(Type type, std::string str)
{
	this->m_type = type;
	this->str = str;
}

Token::Type Token::getType()
{
	return this->m_type;
}

const std::string & Token::getLexem()
{
	return this->str;
}

void Token::setLexem(std::string str)
{
	this->str = str;
}