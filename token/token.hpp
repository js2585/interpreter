#pragma once
#include <any>
#include <iostream>
#include "tokenType.hpp"

class Token
{
public:
    TokenType type;
    std::string lexeme;
    std::any literal;
    int line;
    Token(TokenType type, std::string lexeme, std::any literal, int line);
    friend std::ostream& operator<<(std::ostream& os, const Token& obj);
    std::string literalToString() const;
    std::string toString() const;
};