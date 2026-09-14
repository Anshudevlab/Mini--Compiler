#include "lexer.h"
#include <cctype>
#include <string>

using namespace std;

vector<Token> tokenize(const string& code) {
    vector<Token> tokens;

    for (size_t i = 0; i < code.length();) {

        // Ignore spaces
if (isspace(code[i])) {
    i++;
    continue;
}

// Ignore single-line comments
if (code[i] == '/' && i + 1 < code.length() && code[i + 1] == '/') {
    i += 2;

    while (i < code.length() && code[i] != '\n') {
        i++;
    }

    continue;
}

        // Numbers and decimal numbers
        if (isdigit(code[i])) {
            string number;

            while (i < code.length() && isdigit(code[i])) {
                number += code[i];
                i++;
            }

            // Decimal point
            if (i < code.length() && code[i] == '.') {
                number += code[i];
                i++;

                while (i < code.length() && isdigit(code[i])) {
                    number += code[i];
                    i++;
                }
            }

            tokens.push_back({TokenType::NUMBER, number});
        }

        // Keywords and identifiers
        else if (isalpha(code[i])) {
            string word;

            while (i < code.length() && isalnum(code[i])) {
                word += code[i];
                i++;
            }

            if (word == "int" || word == "float" ||
                word == "char" || word == "double" ||
                word == "if" || word == "else" ||
                word == "while" || word == "for" ||
                word == "return") {

                tokens.push_back({TokenType::KEYWORD, word});

            } else {
                tokens.push_back({TokenType::IDENTIFIER, word});
            }
        }

        // Operators
        else if (code[i] == '+' || code[i] == '-' ||
                 code[i] == '*' || code[i] == '/' ||
                 code[i] == '=' || code[i] == '>' ||
                 code[i] == '<' || code[i] == '!') {

            string op;
            op += code[i];

            // Check for ==, >=, <=, !=
            if (i + 1 < code.length() && code[i + 1] == '=') {
                op += code[i + 1];
                i += 2;
            } else {
                i++;
            }

            tokens.push_back({TokenType::OPERATOR, op});
        }

        // Separators
        else if (code[i] == ';' || code[i] == '(' ||
                 code[i] == ')' || code[i] == '{' ||
                 code[i] == '}') {

            tokens.push_back({
                TokenType::SEPARATOR,
                string(1, code[i])
            });

            i++;
        }

        // Unknown characters
        else {
            tokens.push_back({
                TokenType::UNKNOWN,
                string(1, code[i])
            });

            i++;
        }
    }

    return tokens;
}