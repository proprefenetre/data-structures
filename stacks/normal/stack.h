#ifndef STACK_ADT_H
#define STACK_ADT_H

#include <stdbool.h>

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);

float length(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);

void push(Stack s, float i);
float pop(Stack s);
float peek(Stack s);

#endif /* ifndef STACK_ADT_H */
