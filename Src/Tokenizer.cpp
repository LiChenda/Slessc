#include "Tokenizer.h"
#include "Token.h"
using namespace std;
Tokenizer::Tokenizer(istream &in) : in(&in)
{
    // Read first character.
    readChar();
}
Tokenizer::~Tokenizer()
{
}
void Tokenizer::readChar()
{
    // Read a char into this->last_char

    if (in == NULL) {
        return ;
    }

    in->get(last_char);

    // check for the end-of-file.
    if (in->eof()) {
        in = NULL;
    }
}
Token::Type Tokenizer::readNextToken()
{
    // Let tokenizer read next token to `current_token`

    if (in == NULL) {
        current_token.setType(Token::EOS);
        return Token::EOS;
    }

    // Drop all whitespaces.
    while (readWhitespace()) {}

    current_token.clear();

    string &lexeme = current_token.getLexeme();
    switch (last_char) {
        case '@':
            current_token.setType(Token::ATKEYWORD);
            lexeme.push_back(last_char);
            readChar();
            if (!readIdent()) {
                current_token.setType(Token::OTHER);
            }
            break;
        case '#':
            current_token.setType(Token::HASH);
            lexeme.push_back(last_char);
            readChar();
            if (!readName()) {
                current_token.setType(Token::OTHER);
            }
            break;
        case '-':
            lexeme.push_back(last_char);
            readChar();
            if (readNum(true)) {
                current_token.setType(Token::NUMBER);
                readNumSuffix();
            } else if (readIdent()) {
                current_token.setType(Token::IDENTIIFER);
            } else {
                current_token.setType(Token::SUB);
            }
            break;
        case '/':
            lexeme.push_back(last_char);
            readChar();
            if (readComment()) {
                // Set comment type in readComment()
                //current_token.setType(Token::COMMENT);               
            } else {
                current_token.setType(Token::DIV);
            }
            break;
        case ';':
            current_token.setType(Token::DELIMITER);
            lexeme.push_back(last_char);
            readChar();
            break;
        case ':':
            current_token.setType(Token::COLON);
            lexeme.push_back(last_char);
            readChar();
            break;
        case '{':
            current_token.setType(Token::BRACE_OPEN);
            lexeme.push_back(last_char);
            readChar();
            break;
        case '}':
            current_token.setType(Token::BRACE_CLOSED);
            lexeme.push_back(last_char);
            readChar();
            break;
        case '(':
            current_token.setType(Token::PAREN_OPEN);
            lexeme.push_back(last_char);
            readChar();
            break;
        case ')':
            current_token.setType(Token::PAREN_CLOSED);
            lexeme.push_back(last_char);
            readChar();
            break;
        case '[':
            current_token.setType(Token::BRACKET_OPEN);
            lexeme.push_back(last_char);
            readChar();
            break;
        case ']':
            current_token.setType(Token::BRACKET_CLOSED);
            lexeme.push_back(last_char);
            readChar();
            break;
        case '.':
            lexeme.push_back(last_char);
            readChar();
            if (readNum(false)) {
                current_token.setType(Token::NUMBER);
                readNumSuffix();
            } else if (readIdent()) {
                current_token.setType(Token::DOTTOKEN);
            }
            break;
        case '*':
            current_token.setType(Token::MUL);
            lexeme.push_back(last_char);
            readChar();
            break;
        case '+':
            current_token.setType(Token::ADD);
            lexeme.push_back(last_char);
            readChar();
            break;
        default:
            if (readString()) {
                current_token.setType(Token::STRING);
            } else if (readNum(true)) {
                current_token.setType(Token::NUMBER);
                readNumSuffix();
            } else if (readIdent()) {
                current_token.setType(Token::IDENTIIFER);
            } else if (readWhitespace()) {
                current_token.setType(Token::WHITESPACES);
                while (readWhitespace()) {};
            } else {
                lexeme.push_back(last_char);
                readChar();
            }
            break;
    }

    switch (current_token.getType())
    {
        case Token::WHITESPACES:
        case Token::LINE_COMMENT:
            return readNextToken();
        default:
            return current_token.getType();
    }
}

bool Tokenizer::readIdent()
{
    string &lexeme = current_token.getLexeme();
    if (lastReadEq('-')) {
        lexeme.push_back(last_char);
        readChar();
    }
    if (!readNMStart()) {
        return false;
    } else {
        while (readNMChar()) {}
    }
    return true;
}

bool Tokenizer::readName() 
{
    if (!readNMChar()) {
        return false;
    }

    while (readNMChar()) {}
    return true;
}

bool Tokenizer::readNMStart()
{
    string &lexeme = current_token.getLexeme();
    if (in == NULL) {
        return false;
    }

    if (lastReadEq('_') ||
            lastReadInRange('a', 'z') ||
            lastReadInRange('A', 'Z') ||
            lastReadEq('-')) {
        lexeme.push_back(last_char);
        readChar();
        return true;
    } else {
        return false;
    }
}

bool Tokenizer::readNMChar()
{
    string &lexeme = current_token.getLexeme();
    if (in == NULL) {
        return false;
    }

    if (lastReadEq('_') ||
            lastReadInRange('a', 'z') ||
            lastReadInRange('A', 'Z') ||
            lastReadIsDigit() ||
            lastReadEq('-')) {
        lexeme.push_back(last_char);
        readChar();
        return true;
    } else {
        return false;
    }
}

bool Tokenizer::readNum(bool readDecimals)
{
    string &lexeme = current_token.getLexeme();
    if (!lastReadIsDigit()) {
        return false;
    }
    while (lastReadIsDigit())
    {
        lexeme.push_back(last_char);
        readChar();
    }

    if (readDecimals && lastReadEq('.')) {
        lexeme.push_back(last_char);
        readChar();
        while (lastReadIsDigit())
        {
            lexeme.push_back(last_char);
            readChar();
        }
    }
    return true;
}

bool Tokenizer::readNumSuffix()
{
    string &lexeme = current_token.getLexeme();
    if (last_char == '%') {
        current_token.setType(Token::PERCENTAGE);
        lexeme.push_back(last_char);
        readChar();
        return true;
    }
    return false;
}

bool Tokenizer::readString()
{
    string &lexeme = current_token.getLexeme();
    if (!lastReadEq('"' && !lastReadEq('\''))) {
        return false;
    }
    char delim = last_char;

    lexeme.push_back(last_char);
    readChar();
    while (in != NULL)
    {
        if (lastReadEq(delim)) {
            lexeme.push_back(last_char);
            readChar();
            return true;
        } else {
            lexeme.push_back(last_char);
            readChar();
        }
    }
    return false;
}

bool Tokenizer::readWhitespace()
{
    string &lexeme = current_token.getLexeme();
    if (lastReadEq(' ') ||
            lastReadEq('\t') ||
            lastReadEq('\r') ||
            lastReadEq('\f') ||
            lastReadEq('\n')) {
        lexeme.push_back(last_char);
        readChar();
        return true;
    } else
        return false;
}

bool Tokenizer::readComment()
{
    string &lexeme = current_token.getLexeme();
    if (!lastReadEq('/')) {
        if (!lastReadEq('*')) {
            return false;
        }
        // Block comment
        current_token.setType(Token::COMMENT);
        lexeme.push_back(last_char);
        readChar();

        while (in != NULL) {
            if (lastReadEq('*')) {
                lexeme.push_back(last_char);
                readChar();
                if (lastReadEq('/')) {
                    lexeme.push_back(last_char);
                    readChar();
                    return true;
                }
                continue;
            }
            lexeme.push_back(last_char);
            readChar();
        }
        return false;
    } else {
        // Line-comment
        current_token.setType(Token::LINE_COMMENT);
        while (in != NULL && !lastReadEq('\n'))
        {
            lexeme.push_back(last_char);
            readChar();
        }
        return true;
    }
}

Token &Tokenizer::getToken() {
    return current_token;
}

bool Tokenizer::lastReadEq(char c) {
    return (in != NULL && last_char == c);
}

bool Tokenizer::lastReadInRange(char c1, char c2) {
    return (in != NULL && last_char >= c1 && last_char <= c2);
}

bool Tokenizer::lastReadIsDigit()
{
    return (in != NULL && lastReadInRange('0', '9'));
}

bool Tokenizer::lastReadIsHex() {
    return (in != NULL &&
            (lastReadIsDigit() || 
             lastReadInRange('a', 'f') ||
             lastReadInRange('A', 'F')));
}
