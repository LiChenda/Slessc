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
    std::istream *in;
    Token current_token;
    char last_char;

    void readChar();

    bool readIdent();
    bool readName();
    bool readNMChar();
    bool readNMStart();
    bool readNum(bool readDecimals);
    bool readNumSuffix();
    bool readComment();
    bool readString();
    bool readWhitespace();
    bool lastReadEq(char c);
    bool lastReadInRange(char c1, char c2);
    bool lastReadIsHex();
    bool lastReadIsDigit();
};

#endif
