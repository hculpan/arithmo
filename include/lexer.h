#ifndef _lexer_h_
#define _lexer_h_

// Define the different token types.
typedef enum
{
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_EOF,
    TOKEN_ERROR
} TokenType;

// Structure to represent a token.
typedef struct
{
    TokenType type;
    char *text;   // The lexeme (dynamically allocated)
    double value; // Only used for number tokens
} Token;

extern Token *lex(const char *input, int *token_count);
extern void free_tokens(Token *tokens, int token_count);

#endif
