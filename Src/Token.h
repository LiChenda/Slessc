#pragma once
#ifndef __TOKEN_H_
#define __TOKEN_H_
#include <string>


class Token
{
public:
	Token();
	~Token();
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
	std::string str;

};

#endif