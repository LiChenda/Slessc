#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <iostream>
#include "Token.h"

#include "Tokenizer_fake.h"

class Tokenizer : public FakenizerForTest
{
public:
    Tokenizer ();

    Tokenizer (std::istream &in);
    virtual ~Tokenizer ();

    Token::Type readNextToken();

    Token &getToken();

private:
    /* data */
};

#endif
