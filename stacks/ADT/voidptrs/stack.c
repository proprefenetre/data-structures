#include <stdio.h> 
#include <stdlib.h> 

#include "stack.h"

struct stack_t {
    int size;
    struct elem {
        void *x;
        struct elem *next;
    } *head;
};

Stack Stack_create(void)
{
    Stack new_stk = malloc(sizeof(Stack));
    new_stk->size = 0;
    new_stk->head = NULL;

    return new_stk;
}

void Stack_destroy(Stack *stk)
{
    struct elem *t, *u;

    if (*stk == NULL) {
        exit(EXIT_FAILURE);
    }
    for (t = (*stk)->head; t; t = u) {
        u = t->next;
        free(t);
    }
    free(*stk);
}

int Stack_is_empty(Stack stk)
{
    if (stk  == NULL) {
        exit(EXIT_FAILURE);
    }
    return stk->size == 0;
}

void Stack_push(Stack stk, void *p)
{
    struct elem *n = malloc(sizeof(struct elem *));

    if (stk  == NULL) {
        free(n);
        exit(EXIT_FAILURE);
    }
    n->x = p;
    n->next = stk->head;
    stk->head = n;
    stk->size++;
}

void *Stack_pop(Stack stk) 
{
    void *x;
    struct elem *p;

    if ((stk  == NULL) || !(stk->size > 0)) {
        exit(EXIT_FAILURE);
    }
    p = stk->head;
    stk->head = p->next;
    stk->size--;
    x = p->x;
    free(p);

    return x;
}


void Stack_clear(Stack stk)
{
    void *x;
    if (stk  == NULL) {
        exit(EXIT_FAILURE);
    }
    while (!Stack_is_empty(stk)) {
        x = Stack_pop(stk);
        free(x);
    }
}

