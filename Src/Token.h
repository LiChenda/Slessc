#pragma once
#ifndef __TOKEN_H_
#define __TOKEN_H_
#include <string>


class Token
{

public:

	enum Type
	{
		IDENTIIFER,
		ATKEYWORD,
		STRING,
		NUMBER,       //  number
		COLORVAR,     //  color type var
		HASH,         // '#'  
		PERCENTAGE,   // '%'
		COLON,        // ':'
		DELIMITER,    // ';'
		BRACKET_OPEN, // '['
		BRACKET_CLOSED,// ']'
		PAREN_OPEN,   // '('
		PAREN_CLOSED, // ')'
		BRACE_OPEN,   // '{'
		BRACE_CLOSED, // '}'
		COMMENT,
		DOTTOKEN,      // '.'
        EOS,           // 'end of source file'
		ADD,
		SUB,
		MUL,
		DIV,
	};

	Token();
	~Token();
	Token(Type type, std::string str);
	Type getType();

	const std::string& getLexeme();
	void setLexem(std::string str);
	
private:
	Type m_type;
	std::string str;

};

#endif
