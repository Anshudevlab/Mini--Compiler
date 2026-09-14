#include <iostream>
#include "lexer.h"

using namespace std;

string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::KEYWORD:
            return "KEYWORD";
        case TokenType::IDENTIFIER:
            return "IDENTIFIER";
        case TokenType::NUMBER:
            return "NUMBER";
        case TokenType::OPERATOR:
            return "OPERATOR";
        case TokenType::SEPARATOR:
            return "SEPARATOR";
        default:
            return "UNKNOWN";
    }
}

int main() {
 
   string code = "int age = 20; // user's age";
    vector<Token> tokens = tokenize(code);

    cout << "Mini Compiler - Lexer Output\n\n";

    for (const Token& token : tokens) {
        cout << tokenTypeToString(token.type)
             << " : " << token.value << endl;
    }

    return 0;
}