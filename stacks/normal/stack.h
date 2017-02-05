#ifndef MY_STACK_H

#define MY_STACK_H

#include <stdio.h>
#include <stdlib.h>
/* #include <string.h> */
#include <stdbool.h>
/* #include <ctype.h> */

/* #define MAX_LEN 30 */

struct Node {
    int idx;
    int data;
    struct Node *next;
};

typedef struct stack_type *Stack;

Stack create_stack(void);
/* void push(Stack *list, char *str); */
void push(Stack list, int value);

struct Node *pop(Stack list);
struct Node *peek(Stack list);

bool is_empty(Stack list);
/* char *read_name(void); */


#endif /* ifndef MY_STACK_H */
