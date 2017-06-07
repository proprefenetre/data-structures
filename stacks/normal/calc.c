/* a reverse polish notation calculator */

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 
#include <string.h> 

#include "stack.h"

#define ADD         '+'
#define MUL         '*'
#define SUB         '-'
#define DIV         '/'
#define POW         '^'
#define MOD         '%'
#define SIN         'sin'

#define NUM         '0'
#define CMD         '1'

#define STACK_SIZE  100

#define getch()     (getc(stdin))
#define ungetch(x)  (ungetc((x), stdin))

static int getop(char expr[]);
static void getcmd(Stack st, char expr[]);

int main(void)
{
    Stack operands = create_stack();
    double rhs, lhs, val; 
    int type;
    char expr[STACK_SIZE];

    while ((type = getop(expr)) != EOF) {
        switch (type) {
            case CMD:
                getcmd(operands, expr);
                break;
            case NUM:
                push(operands, atof(expr));
                break;
            case ADD:
                push(operands, pop(operands) + pop(operands));
                break;
            case MUL:
                push(operands, pop(operands) * pop(operands));
                break;
            case SUB:
                rhs = pop(operands);
                push(operands, pop(operands) - rhs);
                break;
            case DIV:
                rhs = pop(operands);
                if (rhs <= 0.0) {
                    printf("Error: division by zero.\n");
                } else {
                    push(operands, pop(operands) / rhs);
                }
                break;
            case POW:
                push(operands, pow(pop(operands), pop(operands)));
                break;
            case MOD:
                rhs = pop(operands);
                lhs = pop(operands);
                push(operands, fmod(lhs, rhs));
                break;
            case '\n':
                val = pop(operands);
                if (length(operands) == 0) {
                    printf("%.2f\n", val);
                }
                break;
            default:
                printf("Error: invalid expression (default).\n");
                exit(EXIT_FAILURE);
                break;

        }
    }
    destroy_stack(operands);
    return 0;
}

static int getop(char expr[])
{
    int i, c;

    // skip spaces and tabs
    while ((expr[0] = c = getc(stdin)) == ' ' || c == '\t') {
        ;
    }

    /* expr[0] contains the first char if it's a space or tab, 
     * it is then converted to a string by appending '\0'. */
    expr[1] = '\0'; 

    i = 0;
    if (!isdigit(c) && c != '.') {      // if c is not a number
        if (isalpha(c)) {
            while(isalpha(expr[++i] = c = getc(stdin))) {
                ;
            }
            expr[i] = '\0';
            return CMD;
        } else {
            return c;                   // c is an operator, return c
        }
    }

    if (isdigit(c)) {   // get all digits before the dot
        while (isdigit(expr[++i] = c = getc(stdin))) {
            ;
        }
    }

    if (c == '.') {     // get all digits after the dot
        while (isdigit(expr[++i] = c = getc(stdin))) {
            ;
        }
    }

    expr[i] = '\0';     // append '\0' to turn expr into a valid string

    if (c != EOF) { 

        /* als het laatst gelezen teken niet gelijk is aan EOF wordt het
         * teruggestopt in de input stream. I.e. op dit punt zijn alle getallen
         * gelezen. Het volgende teken is dus of whitespace of een operator.
         * Dit teken wordt gecheckt en daarna weer teruggezet in de stream
         * zodat het bij de volgende call naar getop() weer gelezen kan worden.
         */
        ungetc(c, stdin);
    }
    
    return NUM;
}

// k&r ex. 4-4/5. Could also turn this into a gigantic switch by using command
// macros (peek 10, show 20, ..., exp n);
static void getcmd(Stack st, char expr[])
{
    struct StackNode *current = st->top;
    int i = 0;

    if (strcmp(expr, "peek") == 0) {
        printf("1: %.2f\n", peek(st));
    } else if (strcmp(expr, "show") == 0) {
        while(current) {
            printf("%d: %.2f\n", ++i, current->data);
            current = current->next;
        }
    } else if (strcmp(expr, "clear") == 0) {
        clear(st);
        printf("Stack cleared.\n");
    } else if (strcmp(expr, "double") == 0) {
        push(st, peek(st));
        printf("Duplicated first value.\n");
    } else if (strcmp(expr, "swap") == 0) {
        swap_first(st);
        printf("Swapped first and second values.\n");
    } else if (strcmp(expr, "sin") == 0) {      // nope
        push(st, sin(pop(st)));
    } else if (strcmp(expr, "exp") == 0) {      // nope
        push(st, exp(pop(st)));
    }
    return;
}



