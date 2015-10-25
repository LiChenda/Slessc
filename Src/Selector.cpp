#include "Selector.h"

Selector::Selector(std::string head) : m_head(head)
{
}

Selector::Selector()
{
}

Selector::~Selector()
{
}

void Selector::addToken(Token t)
{
	this->selector_stream.push_back(t);
}

void Selector::setTokenStream(std::vector<Token> tstream)
{
	this->selector_stream = std::vector<Token>(tstream);
}

std::vector<std::map<std::string, Token>*>& Selector::getValueTables()
{
	return valuetables;
}

std::string Selector::writeYourself()
{
    if (selector_stream.size() == 0) {
        // No attribute.
        return "";
    }

    // Read every token from `selector_stream`.
    while (readAttribute()) {}
    
    // Produce a string from `attributes`.
    // TODO
}

bool Selector::readAttribute() {
    Token first_token = selector_stream[pos];
    if (selector_stream[pos].getType() == Token::IDENTIIFER &&
        selector_stream[pos+1].getType() == Token::COLON) {
        
        pos += 2;
        attributes[first_token.getLexeme()] = readExpression();
        return true;
    }
    return false;
}

std::string Selector::readExpression() {
    return "";
}
std::string Selector::getHeadName()
{
	return this->m_head;
}
