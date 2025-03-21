#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"

// Stub for arithmetic expression evaluation.
// Replace this with your lexing, parsing, and evaluation code.
double evaluate_expression(const char *expr)
{
    int lexeme_count = 0;

    Token *tokens = lex(expr, &lexeme_count);
    printf("Number of tokens: %d\n", lexeme_count);
    free_tokens(tokens, lexeme_count);

    // TODO: Implement arithmetic expression evaluation.
    return 0.0;
}

int main(void)
{
    char input[256];

    printf("arithmo Terminal Calculator\n");
    printf("Enter an expression, or type 'quit' or 'exit' to exit.\n");

    while (1)
    {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            // End-of-file (Ctrl-D on Unix, Ctrl-Z on Windows) reached.
            break;
        }

        // Remove the trailing newline character, if any.
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n')
        {
            input[len - 1] = '\0';
        }

        // Check for exit commands.
        if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0)
        {
            break;
        }

        // Evaluate the arithmetic expression.
        double result = evaluate_expression(input);

        // Display the result.
        printf("= %g\n", result);
    }

    printf("Exiting calculator. Goodbye!\n");
    return 0;
}
