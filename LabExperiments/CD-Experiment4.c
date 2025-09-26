#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RULES 10
#define MAX_LEN 100

void removeLeftRecursion(char nonTerminal, char productions[][MAX_LEN], int prodCount) {
    char alpha[MAX_RULES][MAX_LEN]; // left recursive parts
    int alphaCount = 0;
    char beta[MAX_RULES][MAX_LEN];  // non-left recursive parts
    int betaCount = 0;

    // Separate productions into left recursive and others
    for (int i = 0; i < prodCount; i++) {
        if (productions[i][0] == nonTerminal) {
            // left recursive: A -> A α, remove the leading A
            strcpy(alpha[alphaCount++], productions[i] + 1);
        } else {
            // non-left recursive: beta
            strcpy(beta[betaCount++], productions[i]);
        }
    }

    if (alphaCount == 0) {
        // No left recursion
        printf("%c -> ", nonTerminal);
        for (int i = 0; i < prodCount; i++) {
            printf("%s", productions[i]);
            if (i != prodCount - 1) printf(" | ");
        }
        printf("\n");
        return;
    }

    // Print new productions removing left recursion
    printf("%c -> ", nonTerminal);
    for (int i = 0; i < betaCount; i++) {
        printf("%s%c'", beta[i], nonTerminal);
        if (i != betaCount - 1) printf(" | ");
    }
    printf("\n");

    printf("%c' -> ", nonTerminal);
    for (int i = 0; i < alphaCount; i++) {
        printf("%s%c'", alpha[i], nonTerminal);
        if (i != alphaCount - 1) printf(" | ");
    }
    printf("ε\n");  // epsilon (empty string)
}

int main() {
    char nonTerminal;
    int prodCount;

    printf("Enter non-terminal (single character): ");
    scanf(" %c", &nonTerminal);

    printf("Enter number of productions for %c: ", nonTerminal);
    scanf("%d", &prodCount);

    char productions[MAX_RULES][MAX_LEN];
    printf("Enter productions (right-hand side only, no spaces, e.g. Aα or β):\n");
    for (int i = 0; i < prodCount; i++) {
        scanf("%s", productions[i]);
    }

    printf("\nAfter removing left recursion:\n");
    removeLeftRecursion(nonTerminal, productions, prodCount);

    return 0;
}
