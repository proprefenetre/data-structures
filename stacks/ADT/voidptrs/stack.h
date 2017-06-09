/* stack adt using void* */
#ifndef STACK_VOID_H
#define STACK_VOID_H

typedef struct stack_t *Stack;

Stack Stack_create(void);
void Stack_destroy(Stack *stk);

int Stack_is_empty(Stack stk);

void Stack_push(Stack stk, void *p);
void *Stack_pop(Stack stk);

void Stack_clear(Stack stk);

#endif /* ifndef STACK_VOID_H

typedef struct stack_t *Stack;

Stack Stack_create(void);
void Stack_destroy(Stack *stk);

int Stack_is_empty(Stack stk);

void Stack_push(Stack stk, void *p);
void *Stack_pop(Stack stk);

void Stack_clear(Stack stk);
 */
