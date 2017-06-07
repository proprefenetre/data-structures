#ifndef STACK_H
#define STACK_H

typedef struct stack_type *Stack;

Stack create_stack(void);
void destroy_stack(Stack s);

int length(Stack s);

void push(Stack s, float i);
float pop(Stack s);
float peek(Stack s);

#endif /* ifndef STACK_H */
