#include "LessParser.h"
#include "Token.h"
#include <iostream>
LessParser::LessParser(Tokenizer * tokenizer)
{
	this->m_tokenizer = tokenizer;
}

LessParser::~LessParser()
{
	if (this->m_tokenizer != nullptr)
	{
		delete(this->m_tokenizer);
		this->m_tokenizer = nullptr;
	}

}

void LessParser::showTokens()
{
	while (m_tokenizer->readNextToken() != Token::EOS)
	{
		Token t = m_tokenizer->getToken();
		std::cout << t.getType() <<"  "<< t.getLexem() << std::endl;
	}
}
