#include <stdio.h> 
#include <stdlib.h> 
#include "stack.h"

static void stack_underflow(void);

struct stack_type {
    int size;
    struct StackNode *head, *tail;
};

Stack create_stack(void)
{
    Stack new_stack = malloc(sizeof(Stack));
    if (new_stack == NULL) {
	printf("Error: not enough memory\n");
	exit(EXIT_FAILURE);
    }

    new_stack->head = NULL;
    new_stack->tail = NULL;
    new_stack->size = 0;

    return new_stack;
}

void destroy_stack(Stack s)
{
    while (!is_empty(s)) {
        free(pop(s));
    }

    free(s);
}

void push(Stack s, double value)
{
    struct StackNode *head = s->head;
    struct StackNode *new_node = malloc(sizeof(struct StackNode));

    if (new_node == NULL) {
	printf("Error: not enough memory\n");
	exit(EXIT_FAILURE);
    }

    new_node->next = NULL;
    new_node->data = value;

    if (head == NULL) {
	s->head = new_node;
	s->size++;
	return;
    }

    new_node->next = head;
    s->head = new_node;
    s->size++;
}

struct StackNode *pop(Stack s)
{
    if (is_empty(s)) {
	stack_underflow();
    }
    struct StackNode *popped = s->head;
    s->head = popped->next;
    s->size--;
    return popped;
}

struct StackNode *peek(Stack s)
{
    if (is_empty(s)) {
	stack_underflow();
    }
    return s->head;
}

bool is_empty(Stack s)
{
    return 0 == s->size;
}

static void stack_underflow(void)
{
    printf("Error: empty Stack\n");
    exit(EXIT_FAILURE);
}

