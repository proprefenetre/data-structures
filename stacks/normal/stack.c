#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

#include "stack.h"

/*
struct stack_type {
    struct StackNode *top;
};
*/

static bool is_empty(const Stack s)
{
    return length(s) == 0;
}

static void stack_underflow(void)
{
    printf("Error: empty Stack\n");
}

static void null_check(const void *p)
{
    if (p == NULL) {
        printf("Error -- not enough memory.\n");
        exit(EXIT_FAILURE);
    }
}

int length(const Stack s)
{
    struct StackNode *current = s->top;
    int l = 0;
    
    while (current != NULL) {
        current = current->next;
        l++;
    }

    return l;
}

Stack create_stack(void)
{
    Stack new_stack = malloc(sizeof(Stack));
    null_check(new_stack);

    new_stack->top = NULL;

    return new_stack;
}

void destroy_stack(Stack s)
{
    clear(s);
    free(s);
}

void clear(Stack s) 
{
    while (!is_empty(s)) {
        pop(s);
    }
}

void push(Stack s, double value)
{
    struct StackNode *head = s->top;
    struct StackNode *new_node = malloc(sizeof(struct StackNode));

    null_check(new_node);

    new_node->next = NULL;
    new_node->data = value;

    new_node->next = head;
    s->top = new_node;
}

double pop(Stack s)
{
    double val;

    if (is_empty(s)) {
	stack_underflow();
        return 0.0;
    }
    struct StackNode *popped = s->top;
    val = popped->data;
    s->top = popped->next;
    free(popped);
    return val;
}

double peek(Stack s)
{
    if (is_empty(s)) {
	stack_underflow();
    } else {
        return s->top->data;
    }
}

void swap_first(Stack s)
{
    if (length(s) < 2) {
        printf("Error -- swap_first: not enough elements.\n");
        return;
    }

    struct StackNode *a = s->top, *b = s->top->next;
    double tmp;

    tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}
