/*
Build a lexical analyzer in Python or C
that reads source code and separates it
into keywords, identifiers, numbers,
operators, and symbols like what code
editors do for highlighting.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// List of C keywords
const char* keywords[] = {
    "int", "float", "if", "else", "while", "for", "return",
    "char", "double", "void", "break", "continue", "struct",
    "switch", "case", "default", "do", "sizeof", "long", "short", "typedef",
    "static", "const", "enum", "union", "signed", "unsigned", "goto", "auto", "extern", "register", "volatile"
};

int isKeyword(const char* str) {
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
           ch == '%' || ch == '=' || ch == '<' || ch == '>' || ch == '!';
}

int isSymbol(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
           ch == '[' || ch == ']' || ch == ';' || ch == ',' || ch == '.';
}

void analyze(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file.\n");
        return;
    }

    char ch;
    char buffer[MAX_LEN];
    int i = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        } else {
            if (i > 0) {
                buffer[i] = '\0';
                if (isKeyword(buffer))
                    printf("[Keyword]     %s\n", buffer);
                else if (isdigit(buffer[0]))
                    printf("[Number]      %s\n", buffer);
                else
                    printf("[Identifier]  %s\n", buffer);
                i = 0;
            }

            if (isOperator(ch)) {
                char next = fgetc(file);
                if ((ch == '+' && next == '+') || (ch == '-' && next == '-') ||
                    (ch == '=' && next == '=') || (ch == '!' && next == '=') ||
                    (ch == '<' && next == '=') || (ch == '>' && next == '=')) {
                    printf("[Operator]    %c%c\n", ch, next);
                } else {
                    ungetc(next, file);
                    printf("[Operator]    %c\n", ch);
                }
            } else if (isSymbol(ch)) {
                printf("[Symbol]      %c\n", ch);
            } else if (isspace(ch)) {
                continue; // Skip spaces
            } else {
                printf("[Unknown]     %c\n", ch);
            }
        }
    }

    // Handle trailing word
    if (i > 0) {
        buffer[i] = '\0';
        if (isKeyword(buffer))
            printf("[Keyword]     %s\n", buffer);
        else if (isdigit(buffer[0]))
            printf("[Number]      %s\n", buffer);
        else
            printf("[Identifier]  %s\n", buffer);
    }

    fclose(file);
}

int main() {
    char filename[100];
    printf("Enter the source code filename: ");
    scanf("%s", filename);

    analyze(filename);

    return 0;
}
