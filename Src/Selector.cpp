#include <stack>
#include "Selector.h"

Selector::Selector(std::string head) : m_head(head)
{
}

Selector::Selector()
{
}

Selector::~Selector()
{
}

void Selector::addToken(Token t)
{
	this->selector_stream.push_back(t);
}

void Selector::setTokenStream(std::vector<Token> tstream)
{
	this->selector_stream = std::vector<Token>(tstream);
}

std::vector<std::map<std::string, Token>*>& Selector::getValueTables()
{
	return valuetables;
}

std::string Selector::getHeadName()
{
	return this->m_head;
}

std::string Selector::writeYourself()
{
    if (selector_stream.size() == 0) {
        // No attribute.
        return "";
    }

    // Read every token from `selector_stream`.
    while (readAttribute()) {}
    
    // Produce a string from `attributes`.
    std::string output = "";
    output.append(m_head);
    output.append(" {\n");
    for (auto attribute : attributes) {
        output.append(attribute.first + ": " + attribute.second + ";\n");
    }
    output.append("}");
    return output;
}

bool Selector::readAttribute() {
    Token first_token = selector_stream[pos];
    if (selector_stream[pos].getType() == Token::IDENTIIFER &&
        selector_stream[pos+1].getType() == Token::COLON) {
        
        pos += 2;
        attributes[first_token.getLexeme()] = readExpression();
        return true;
    }
    return false;
}

std::string Selector::readExpression() {
    std::string expr = "";
    for (; selector_stream[pos].getType() != Token::COLON; pos++) {
        if (selector_stream[pos].getType() == Token::ATKEYWORD) {
            expr.append(getVar(selector_stream[pos].getLexeme()));
        } else {
            expr.append(selector_stream[pos].getLexeme());
        }
    }
    // Skip the semi-colon for next analysis.
    pos++;
    return expr;
}

std::string Selector::getVar(std::string var_name) {
    std::vector<std::map<std::string, Token> *>::iterator current_map = valuetables.end() - 1;
    for (; current_map != valuetables.begin()-1; current_map--) {
        std::map<std::string, Token>::iterator token_itr = (*current_map)->find(var_name);
        if (token_itr != (*current_map)->end()) {
            return token_itr->second.getLexeme();
        }
    }
    return "";
}
/*
std::string Selector::expr() {
    return term() + rest_expr();
}

std::string Selector::rest_expr() {
    if (pos == selector_stream.size()) {
        return "";
    }
    switch (selector_stream[pos].getType()) {
        case Token::ADD:
            // Read '+'
            pos ++;

            break;
        case Token::SUB:
            pos ++;
            return "-" + term();
            break;
        default:
            return "";
            break;
    }
}

std::string Selector::term() {

}

std::string Selector::rest_term() {
}

std::string Selector::factor() {
}
*/
