#ifndef MY_STACK_H
#define MY_STACK_H

struct StackNode {
    double data;
    struct StackNode *next;
};

typedef struct stack_type {
    struct StackNode *top;
} *Stack;

Stack create_stack(void);
void destroy_stack(Stack s);
void clear(Stack s);

int length(Stack s);

void push(Stack s, double value);
double pop(Stack s);
double peek(Stack s);
// swap the values of the first 2 elements (k&r ex. 4-3)
void swap_first(Stack s);

#endif /* ifndef MY_STACK_H */
