#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <iostream>
#include "Tokenizer.h"
#include "Token.h"

class Tokenizer
{
public:
    Tokenizer ();
    Tokenizer (istream &in);
    virtual ~Tokenizer ();

private:
    /* data */
};

#endif
