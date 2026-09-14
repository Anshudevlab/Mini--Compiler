#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    SEPARATOR,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> tokenize(const std::string& code);

#endif