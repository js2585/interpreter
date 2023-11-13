#include <iostream>
#include "lexer/lexer.hpp"
#include "token/token.hpp"
#include "main.hpp"

bool hadError = false;

void run(std::string source)
{
    Lexer lexer = Lexer(source);
    std::vector<Token> tokens = lexer.scanTokens();

    for (const Token& token : tokens)
    {
        std::cout << token << "\n";
    }
    if (hadError)
    {
        exit(1);
    }
};

void error(int line, std::string message)
{
    report(line, "", message);
};

void report(int line, std::string where, std::string message)
{
    std::cout << "Error on line " << line << " " << where << ": " << message << "\n";
    hadError = true;
};

int main()
{
    run("if (i > 3) { print(\"Hello\")}");
    return 0;
};