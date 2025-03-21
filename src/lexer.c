#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "lexer.h"

// Free all tokens and their associated strings.
void free_tokens(Token *tokens, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(tokens[i].text);
    }
    free(tokens);
}

// Lex function: takes an input string and returns a dynamic array of tokens.
Token *lex(const char *input, int *token_count)
{
    int capacity = 16;
    int count = 0;
    Token *tokens = malloc(capacity * sizeof(Token));
    if (!tokens)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    const char *p = input;
    while (*p != '\0')
    {
        // Skip whitespace.
        if (isspace(*p))
        {
            p++;
            continue;
        }

        // Ensure there is enough capacity.
        if (count >= capacity)
        {
            capacity *= 2;
            tokens = realloc(tokens, capacity * sizeof(Token));
            if (!tokens)
            {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
        }

        // If the character is a digit or a dot, parse a number.
        if (isdigit(*p) || *p == '.')
        {
            char *end;
            double num = strtod(p, &end);
            int len = end - p;
            char *num_str = malloc(len + 1);
            if (!num_str)
            {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            strncpy(num_str, p, len);
            num_str[len] = '\0';

            tokens[count].type = TOKEN_NUMBER;
            tokens[count].text = num_str;
            tokens[count].value = num;
            count++;
            p = end;
            continue;
        }

        // Otherwise, handle single-character tokens.
        Token token;
        token.value = 0;
        token.text = malloc(2); // Allocate space for one character plus null terminator.
        if (!token.text)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        token.text[0] = *p;
        token.text[1] = '\0';

        switch (*p)
        {
        case '+':
            token.type = TOKEN_PLUS;
            break;
        case '-':
            token.type = TOKEN_MINUS;
            break;
        case '*':
            token.type = TOKEN_STAR;
            break;
        case '/':
            token.type = TOKEN_SLASH;
            break;
        case '(':
            token.type = TOKEN_LPAREN;
            break;
        case ')':
            token.type = TOKEN_RPAREN;
            break;
        default:
            token.type = TOKEN_ERROR;
            break;
        }
        tokens[count++] = token;
        p++;
    }

    // Append an EOF token.
    if (count >= capacity)
    {
        capacity++;
        tokens = realloc(tokens, capacity * sizeof(Token));
        if (!tokens)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    tokens[count].type = TOKEN_EOF;
    tokens[count].text = strdup("EOF");
    tokens[count].value = 0;
    count++;

    *token_count = count;
    return tokens;
}

// Helper function to get token type names as strings.
const char *token_type_name(TokenType type)
{
    switch (type)
    {
    case TOKEN_NUMBER:
        return "NUMBER";
    case TOKEN_PLUS:
        return "PLUS";
    case TOKEN_MINUS:
        return "MINUS";
    case TOKEN_STAR:
        return "STAR";
    case TOKEN_SLASH:
        return "SLASH";
    case TOKEN_LPAREN:
        return "LPAREN";
    case TOKEN_RPAREN:
        return "RPAREN";
    case TOKEN_EOF:
        return "EOF";
    case TOKEN_ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

/*
// A simple main to demonstrate tokenization.
int main()
{
    const char *input = "3.14 + (2 * 5) - 7 / 2";
    int token_count = 0;
    Token *tokens = lex(input, &token_count);

    printf("Tokens for input: %s\n", input);
    for (int i = 0; i < token_count; i++)
    {
        if (tokens[i].type == TOKEN_NUMBER)
        {
            printf("%s: %s (value: %f)\n",
                   token_type_name(tokens[i].type),
                   tokens[i].text,
                   tokens[i].value);
        }
        else
        {
            printf("%s: %s\n",
                   token_type_name(tokens[i].type),
                   tokens[i].text);
        }
    }

    free_tokens(tokens, token_count);
    return 0;
}

*/
