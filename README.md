# arithmo
This is a small interpreter project written in C, because I like C and I like writing interpreters and my nephew is learning about recursive descent parsers and I thought this would be a simple expample for me to explain it to him.

# BNF

```
<expr>   ::= <term> | <expr> "+" <term> | <expr> "-" <term>
<term>   ::= <factor> | <term> "*" <factor> | <term> "/" <factor>
<factor> ::= "(" <expr> ")" | <number>
<number> ::= <digit>+ [ "." <digit>+ ]
<digit>  ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
```