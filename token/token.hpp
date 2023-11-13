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
    // no Object type in c++ so literal is std::string now...
    Token(TokenType type, std::string lexeme, std::any literal, int line);
    friend std::ostream& operator<<(std::ostream& os, const Token& obj);
    std::string literalToString() const;
};