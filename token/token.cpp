#include<iostream>
#include "token.hpp"

Token::Token(TokenType type, std::string lexeme, std::string literal, int line)
{
    this->type = type;
    this->lexeme = lexeme;
    this->literal = literal;
    this->line = line;
};

std::ostream& operator<<(std::ostream& os, const Token& obj)
{
    // token type has no string form so idk how to print
    os << obj.lexeme << " " << obj.literal;
    return os;
};