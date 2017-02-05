#include "stackADT.h"

struct Node {
    Item data;
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

Stack create(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) {
	terminate("Error -- create: stack could not be created.\n");
    }
    s->top = NULL;
    return s;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while (!is_empty(s)) {
        pop(s);
    }
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, Item i)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    if (new_node == NULL) {
        terminate("Error -- push: stack is full.\n");
    }
    
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

Item pop(Stack s)
{
    struct Node *old_top;
    Item i;

    if (is_empty(s)) {
	terminate("Error -- pop: stack is empty.\n");
    }

    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    return i;
}

