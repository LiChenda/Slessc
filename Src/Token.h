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
		HASH,         // '#{IDENTIFIER}'
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
        WHITESPACES,
        LINE_COMMENT,
		DOTTOKEN,      // '.{IDENTIFIER}'
        EOS,           // 'end of source file'
        OTHER,
		ADD,
		SUB,
		MUL,
		DIV,
	};

	Token();
    Token(const std::string &, Type);
	~Token();
    std::string &getLexeme() { return lexeme; }
	Type getType() { return m_type; }
    void setType(Type type) { m_type = type; }
    void clear() { lexeme.clear(); m_type = OTHER; }
	
private:
	Type m_type;
	std::string lexeme;
};

#endif
