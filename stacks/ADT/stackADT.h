#ifndef STACK_ADT_H
#define STACK_ADT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char* Item;

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif /* ifndef STACK_ADT_H */
