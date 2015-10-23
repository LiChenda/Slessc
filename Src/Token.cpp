#include "Token.h"
using namespace std;

Token::Token() : m_type(OTHER)
{
}
Token::Token(const string &s, Type t) : m_type(t), lexeme(s)
{
}



Token::~Token(){}