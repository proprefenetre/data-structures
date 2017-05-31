/* reverse polish notation calculator -- somewhat experimental */

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h> 
#include <string.h> 

#include "stack.h"

static float evaluate(char *expr);

int main(void)
{
    char ch, expression[100], *p_expr;
    bool t = true;

    p_expr = expression;

    while (t) {
	printf("Enter an RPN expression: ");
	while ((ch = getchar()) != '\n') {
            if (isalpha(ch)) {
                t = false;
                break;
            }
            *p_expr++ = ch;
	}
        *p_expr = '\0';

        printf("result: %.2f\n", evaluate(expression));
        memset(expression, 0, sizeof expression);
        p_expr = expression;
    }
    return 0;
}

static float evaluate(char *expr)
{
    Stack rpn_stack = create();
    const char *sep = " ";
    char *ch, *tokens;
    float lhs, rhs, val;

    tokens = strtok(expr, sep);
    while (tokens != NULL) {
        ch = tokens;
        tokens = strtok(NULL, sep);
        if (strcmp(ch, "*") == 0) { 
            rhs = pop(rpn_stack);
            lhs = pop(rpn_stack);
            printf("%.2f %s %.2f\n", lhs, ch, rhs);
            push(rpn_stack, lhs * rhs);
        } else if (strcmp(ch, "/") == 0) {
            rhs = pop(rpn_stack);
            lhs = pop(rpn_stack);
            printf("%.2f %s %.2f\n", lhs, ch, rhs);
            push(rpn_stack, (int) lhs / rhs);
        } else if (strcmp(ch, "+") == 0) {
            rhs = pop(rpn_stack);
            lhs = pop(rpn_stack);
            printf("%.2f %s %.2f\n", lhs, ch, rhs);
            push(rpn_stack, lhs + rhs);
        } else if (strcmp(ch, "-") == 0) {
            rhs = pop(rpn_stack);
            lhs = pop(rpn_stack);
            printf("%.2f %s %.2f\n", lhs, ch, rhs);
            push(rpn_stack, lhs - rhs);
        } else if (strcmp(ch, "^") == 0) {
            rhs = pop(rpn_stack);
            printf("%.2f ^2 \n", rhs);
            push(rpn_stack, rhs * rhs);
        } else if (strcmp(ch, "=") == 0) {
            val = pop(rpn_stack);
            if (is_empty(rpn_stack))
                return val;
        } else {
            push(rpn_stack, atoi(ch));
        }
    }    
    val = pop(rpn_stack);
    destroy(rpn_stack);
    return val;
}
