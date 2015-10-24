#include "ParseTreeBuilder.h"
using namespace std;
ParseTreeBuilder::ParseTreeBuilder(std::vector<Token> tokenstream)
{
	this->m_tokenstream = vector<Token>(tokenstream);
	this->m_treeroot = new ParseNode(Token("root", Token::OTHER));
	this->currentNode = m_treeroot;
}

ParseTreeBuilder::~ParseTreeBuilder()
{
	if (m_treeroot != nullptr)
	{
		delete this->m_treeroot;
		this->m_treeroot = nullptr;
	}
}

void ParseTreeBuilder::buildParseTree()
{
	
}
