#pragma once
#ifndef __TOKEN_H_
#define __TOKEN_H_
#include <string>


class Token
{
	enum type
	{
		IDENTIIFER,
		ATKEYWORD,
		STRING,
		NUMBER,       //  number
		HASH,         // '#'  
		PERCENTAGE,   // '%'
		COLON,        // ':'
		DELIMITER,    // ';'
		BRACKET_OPEN, // '['
		BRACKET_CLOSE,// ']'
		PAREN_OPEN,   // '('
		PAREN_CLOSED, // ')'
		BRACE_OPEN,   // '{'
		BRACE_CLOSED, // '}'
		COMMENT,
		DOTTOKEN      // '.'
	};
public:
	Token();
	~Token();
	type getType();

private:
	type m_type;
public:
	std::string str;

};

#endif