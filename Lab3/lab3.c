#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 32

const char *keywords[MAX_KEYWORDS] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
    "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while"
};

int isKeyword(const char *str) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1; //keyword
        }
    }
    return 0; //not a keyword
}

int main() {
    char filename[20]; // Assuming maximum filename length is 20 characters

    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int numTokens = 0;
    char token[100]; // Assuming maximum token length is 100 characters

    int inside_comment = 0; // Flag to track if inside a comment

    while (1) {
        int c = fgetc(file);

        // End of file check
        if (c == EOF) {
            break;
        }

        // Handle comments
        if (inside_comment) {
            if (c == '*' && (c = fgetc(file)) == '/') {
                inside_comment = 0;
            }
            continue;
        } else if (c == '/' && (c = fgetc(file)) == '*') {
            inside_comment = 1;
            continue;
        }

        // Skip whitespaces, tab spaces, and newlines
        if (isspace(c)) {
            continue;
        }

        // Handle preprocessor directives
        if (c == '#') {
            while ((c = fgetc(file)) != '\n' && c != EOF); // Skip the rest of the line
            continue;
        }

        // Handle string literals
        if (c == '"') {
            putchar(c);
            while ((c = fgetc(file)) != '"' && c != EOF) {
                putchar(c);
            }
            putchar(c); // Print closing double quote
            continue;
        }

        // Handle single-line comments
        if (c == '/' && (c = fgetc(file)) == '/') {
            while ((c = fgetc(file)) != '\n' && c != EOF); // Skip the rest of the line
            continue;
        }

        // Handle special characters and operators
        if (ispunct(c)) {
            putchar(c);
            continue;
        }

        // Build and classify identifiers, keywords, and constants
        int token_length = 0;
        while (isalnum(c) || c == '_') {
            token[token_length++] = c;
            c = fgetc(file);
        }
        token[token_length] = '\0';

        if (strlen(token) > 0) {
            numTokens++;

            if (isKeyword(token)) {
                printf("Keyword: %s\n", token);
            } else if (isdigit(token[0])) {
                // Assume that constants start with a digit (simplified logic)
                printf("Constant: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
        }

        // Put back the non-alphanumeric character for the next iteration
        ungetc(c, file);
    }

    printf("Total number of tokens: %d\n", numTokens);

    fclose(file);
    return 0;
}