
#include "stack.h"

#define MUL '*'
#define DIV '/'
#define ADD '+'
#define SUB '-'
#define EQS '='

#define STACK_SIZE 100

static int evaluate_RPN_expression(const char *expr);

Stack *rpn_stack;

int main(void)
{
    char ch, expression[STACK_SIZE], *expr_ptr;
    bool cont = true;

    rpn_stack = create_stack();


    while (cont) {
	    expr_ptr = expression;
	    printf("Enter an RPN expression: ");
	    while ((ch = getchar()) != '\n') {
		    if (isalpha(ch)) {
			    cont = false;
			    break;
		    } else if (!isspace(ch)) {
			    *expr_ptr++ = ch;
		    }
	    }
	    if (cont)
		    printf("Value of expression: %d\n",	evaluate_RPN_expression(expression));
    }

    return 0;
}

/* returns the value of the RPN contents pointed to by expr */
static int evaluate_RPN_expression(const char * expr)
{
    int lhs, rhs, val;
    int ch;

    while (true) {
	ch = *expr++;
	if (isdigit(ch))
	    push(rpn_stack, ch -= '0'); // ch is now int
	else
	    switch (ch) {
		case MUL:
		    rhs = pop(rpn_stack)->data;
		    lhs = pop(rpn_stack)->data;
		    push(rpn_stack, lhs * rhs);
		    break;
		case DIV:
		    rhs = pop(rpn_stack)->data;
		    lhs = pop(rpn_stack)->data;
		    push(rpn_stack, (int) lhs / rhs);
		    break;
		case ADD:
		    rhs = pop(rpn_stack)->data;
		    lhs = pop(rpn_stack)->data;
		    push(rpn_stack, lhs + rhs);
		    break;
		case SUB:
		    rhs = pop(rpn_stack)->data;
		    lhs = pop(rpn_stack)->data;
		    push(rpn_stack, lhs - rhs);
		    break;
		case EQS:
		    val = pop(rpn_stack)->data;
		    if (is_empty(rpn_stack))
		    return val;

		default:
			break;
	    }
    }
}
