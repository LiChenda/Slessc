#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <iostream>
#include "Tokenizer.h"
#include "Token.h"

class Tokenizer
{
public:
    Tokenizer ();
    Tokenizer (std::istream&in);
    virtual ~Tokenizer ();

    Token::Type readNextToken();

    Token &getToken();

private:
    /* data */
};

#endif
