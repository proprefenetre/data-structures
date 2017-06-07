#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#include "stack.h"

struct Node {
    float data;
    struct Node *next;
};

struct stack_type {
    struct Node *top;
};

static void terminate(const char * message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

static bool is_empty(const Stack s) 
{
    return s->top == NULL;
}

static void make_empty(Stack s)
{
    while (!is_empty(s)) {
        pop(s);
    }
}

Stack create_stack(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) {
	terminate("Error -- create: not enough memory.\n");
    }

    s->top = NULL;
    return s;
}

void destroy_stack(Stack s)
{
    make_empty(s);
    free(s);
}

int length(Stack s)
{
    struct Node *current = s->top;
    int size = 0;

    while (current) {
        current = current->next;
        size++;
    }
    
    return size;
}

void push(Stack s, float i)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL) {
        terminate("Error -- push: out of memory.\n");
    }
    
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

float pop(Stack s)
{
    struct Node *old_top;
    float i;

    if (is_empty(s)) {
	terminate("Error -- not enough operands.\n");
    }

    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    return i;
}

float peek(Stack s)
{
    if (is_empty(s)) {
	terminate("Error -- pop: stack is empty.\n");
    }

    return s->top->data;
}
