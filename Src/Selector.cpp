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
	this->selectorStream.push_back(t);
}

std::vector<std::map<std::string, Token>&>& Selector::getValueTables()
{
	return valuetables;
}

std::string Selector::getHeadName()
{
	return this->m_head;
}
