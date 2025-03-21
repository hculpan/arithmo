#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h" // Include this if you have one. Otherwise, declare the functions below.

// If you don't have a lexer.h, you can declare the prototypes as follows:

int main(void)
{
    int token_count = 0;
    Token *tokens = NULL;

    // Test 1: Single number.
    tokens = lex("42", &token_count);
    // Expected tokens: [TOKEN_NUMBER ("42"), TOKEN_EOF]
    assert(token_count == 2);
    assert(tokens[0].type == TOKEN_NUMBER);
    assert(strcmp(tokens[0].text, "42") == 0);
    assert(tokens[0].value == 42);
    assert(tokens[1].type == TOKEN_EOF);
    free_tokens(tokens, token_count);

    // Test 2: Simple expression with a float and an operator.
    tokens = lex("3.14 + 2.71", &token_count);
    // Expected tokens: [TOKEN_NUMBER ("3.14"), TOKEN_PLUS ("+"),
    //                   TOKEN_NUMBER ("2.71"), TOKEN_EOF]
    assert(token_count == 4);
    assert(tokens[0].type == TOKEN_NUMBER);
    assert(strcmp(tokens[0].text, "3.14") == 0);
    assert(tokens[0].value == 3.14);
    assert(tokens[1].type == TOKEN_PLUS);
    assert(strcmp(tokens[1].text, "+") == 0);
    assert(tokens[2].type == TOKEN_NUMBER);
    assert(strcmp(tokens[2].text, "2.71") == 0);
    assert(tokens[2].value == 2.71);
    assert(tokens[3].type == TOKEN_EOF);
    free_tokens(tokens, token_count);

    // Test 3: Expression with parentheses and multiple operators.
    tokens = lex("(1+2)*3", &token_count);
    // Expected tokens: [TOKEN_LPAREN ("("), TOKEN_NUMBER ("1"),
    //                   TOKEN_PLUS ("+"), TOKEN_NUMBER ("2"),
    //                   TOKEN_RPAREN (")"), TOKEN_STAR ("*"),
    //                   TOKEN_NUMBER ("3"), TOKEN_EOF]
    assert(token_count == 8);
    assert(tokens[0].type == TOKEN_LPAREN);
    assert(strcmp(tokens[0].text, "(") == 0);
    assert(tokens[1].type == TOKEN_NUMBER);
    assert(strcmp(tokens[1].text, "1") == 0);
    assert(tokens[2].type == TOKEN_PLUS);
    assert(strcmp(tokens[2].text, "+") == 0);
    assert(tokens[3].type == TOKEN_NUMBER);
    assert(strcmp(tokens[3].text, "2") == 0);
    assert(tokens[4].type == TOKEN_RPAREN);
    assert(strcmp(tokens[4].text, ")") == 0);
    assert(tokens[5].type == TOKEN_STAR);
    assert(strcmp(tokens[5].text, "*") == 0);
    assert(tokens[6].type == TOKEN_NUMBER);
    assert(strcmp(tokens[6].text, "3") == 0);
    assert(tokens[7].type == TOKEN_EOF);
    free_tokens(tokens, token_count);

    printf("All lexer tests passed.\n");
    return 0;
}