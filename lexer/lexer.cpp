#include "lexer.hpp"
#include "../main.hpp"
Lexer::Lexer(std::string source) : source{ source }
{
}

std::vector<Token> Lexer::scanTokens()
{
    while (!isAtEnd())
    {
        start = current;
        scanToken();
    }

    tokens.push_back(Token(TokenType::EF, "", "", line));
    return tokens;
}

void Lexer::scanToken()
{
    char c = advance();
    switch (c)
    {
    case '(':
        addToken(TokenType::LEFT_PAREN);
        break;
    case ')':
        addToken(TokenType::RIGHT_PAREN);
        break;
    case '{':
        addToken(TokenType::LEFT_BRACE);
        break;
    case '}':
        addToken(TokenType::RIGHT_BRACE);
        break;
    case ',':
        addToken(TokenType::COMMA);
        break;
    case '.':
        addToken(TokenType::DOT);
        break;
    case '-':
        addToken(TokenType::MINUS);
        break;
    case '+':
        addToken(TokenType::PLUS);
        break;
    case ';':
        addToken(TokenType::SEMICOLON);
        break;
    case '*':
        addToken(TokenType::STAR);
        break;
    case '!':
        addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
        break;
    case '=':
        addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
        break;
    case '<':
        addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
        break;
    case '>':
        addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
        break;
    case '/':
        if (match('/'))
        {
            while (peek() != '\n' && !isAtEnd())
            {
                advance();
            }
        }
        else
        {
            addToken(TokenType::SLASH);
        }
        break;
    case ' ':
    case '\r':
    case '\t':
        break;
    case '\n':
        line++;
        break;
    case '"':
        string();
        break;
    default:
        if (isDigit(c))
        {
            number();
        }
        else if (isAlpha(c))
        {
            identifier();
        }
        else
        {
            error(line, "Unexpected character.");

        }
        break;
    }

}

char Lexer::advance()
{
    return source.at(current++);
}

void Lexer::addToken(TokenType type)
{
    addToken(type, "");
}

void Lexer::addToken(TokenType type, std::any literal)
{
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token(type, text, literal, line));
}

bool Lexer::isAtEnd()
{
    return current >= source.length();
}

bool Lexer::match(char expected)
{
    if (isAtEnd() || source.at(current) != expected)
    {
        return false;
    }
    current++;
    return true;
}

char Lexer::peek()
{
    if (isAtEnd())
    {
        return '\0';
    }
    return source.at(current);
}

void Lexer::string()
{
    while (peek() != '"' && !isAtEnd())
    {
        if (peek() == '\n')
        {
            line++;
        }
        advance();
    }
    if (isAtEnd())
    {
        error(line, "Unterminated string.");
        return;
    }
    advance();
    addToken(TokenType::STRING, source.substr(start + 1, current - 1 - (start + 1)));
}

bool Lexer::isDigit(char c)
{
    return c >= '0' && c <= '9';
}

void Lexer::number()
{
    while (isDigit(peek()))
    {
        advance();
    }
    if (peek() == '.' && isDigit(peekNext()))
    {
        advance();
        while (isDigit(peek()))
        {
            advance();
        }
    }
    addToken(TokenType::NUMBER, std::stod(source.substr(start, current - start)));
}

char Lexer::peekNext()
{
    if (current + 1 >= source.length())
    {
        return '\0';
    }
    return source.at(current + 1);
}

void Lexer::identifier()
{
    while (isAlphaNumeric(peek()))
    {
        advance();
    }
    std::string text = source.substr(start, current - start);
    auto it = keywords.find(text);
    if (it != keywords.end())
    {
        addToken(it->second);
    }
    else
    {
        addToken(TokenType::IDENTIFIER);
    }
}

bool Lexer::isAlpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
}

bool Lexer::isAlphaNumeric(char c)
{
    return isAlpha(c) || isDigit(c);
}

