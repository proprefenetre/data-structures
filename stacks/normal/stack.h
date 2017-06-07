#ifndef MY_STACK_H

#define MY_STACK_H

#include <stdbool.h>

struct StackNode {
    double data;
    struct StackNode *next;
};

typedef struct stack_type *Stack;

Stack create_stack(void);
void destroy_stack(Stack s);

void push(Stack s, double value);
struct StackNode *pop(Stack s);
struct StackNode *peek(Stack s);

bool is_empty(Stack s);

#endif /* ifndef MY_STACK_H */
