#include "token.hpp"
#include <iostream>

Token::Token(TokenType type, std::string lexeme, std::any literal, int line) :
    type(type), lexeme(lexeme), literal(literal), line(line)
{
};

std::ostream& operator<<(std::ostream& os, const Token& obj)
{
    os << obj.toString();
    return os;
};

std::string Token::literalToString() const
{
    switch (type)
    {
    case TokenType::STRING:
        return std::any_cast<std::string>(literal);
    case TokenType::NUMBER:
        return std::to_string(std::any_cast<double>(literal));
    default:
        return "";
    }
}

std::string Token::toString() const
{
    return std::to_string(static_cast<int>(type)) + " " + lexeme + " " + literalToString();
}