#include <stdio.h>
#include <ctype.h>

const char *input;
int pos = 0;

void skipWhitespace() {
    while (input[pos] == ' ' || input[pos] == '\t') pos++;
}

int parseExpr();

int parseNumber() {
    skipWhitespace();
    if (!isdigit(input[pos])) return 0;
    while (isdigit(input[pos])) pos++;
    return 1;
}

int parseFactor() {
    skipWhitespace();
    if (input[pos] == '(') {
        pos++; // consume '('
        if (!parseExpr()) return 0;
        skipWhitespace();
        if (input[pos] != ')') return 0;
        pos++; // consume ')'
        return 1;
    }
    return parseNumber();
}

int parseTerm() {
    if (!parseFactor()) return 0;
    skipWhitespace();
    while (input[pos] == '*' || input[pos] == '/') {
        pos++; // consume operator
        if (!parseFactor()) return 0;
        skipWhitespace();
    }
    return 1;
}

int parseExpr() {
    if (!parseTerm()) return 0;
    skipWhitespace();
    while (input[pos] == '+' || input[pos] == '-') {
        pos++; // consume operator
        if (!parseTerm()) return 0;
        skipWhitespace();
    }
    return 1;
}

int main() {
    char buffer[256];
    printf("Enter an arithmetic expression: ");
    fgets(buffer, sizeof(buffer), stdin);

    input = buffer;
    pos = 0;

    if (parseExpr() && input[pos] == '\0' || input[pos] == '\n') {
        printf("Valid expression\n");
    } else {
        printf("Invalid expression\n");
    }

    return 0;
}
