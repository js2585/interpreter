#include<iostream>
#include "token.hpp"

Token::Token(TokenType type, std::string lexeme, std::string literal, int line) :
    type{ type }, lexeme{ lexeme }, literal{ literal }, line{ line }
{
};

std::ostream& operator<<(std::ostream& os, const Token& obj)
{
    // token type has no string form so idk how to print
    os << static_cast<int>(obj.type) << " " << obj.lexeme << " " << obj.literal;
    return os;
};