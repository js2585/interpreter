#include "token.hpp"
#include <iostream>

Token::Token(TokenType type, std::string lexeme, std::any literal, int line) :
    type(type), lexeme(lexeme), literal(literal), line(line)
{
};

std::ostream& operator<<(std::ostream& os, const Token& obj)
{
    // token type has no string form so idk how to print
    os << static_cast<int>(obj.type) << " " << obj.lexeme << " " << obj.literalToString();
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