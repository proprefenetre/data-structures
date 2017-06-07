#include <stdio.h> 
#include "stack.h"

int main(void)
{
    Stack st = create();
    int i;
    
    for (i = 10; i-- > 0; ) {
	push(st, i);
    }

    printf("Size: %d\n", length(st));
    printf("Top: %d\n", peek(st));
    printf("Popped: %d\n", pop(st));
    printf("Top: %d\n", peek(st));
    printf("Popped: %d\n", pop(st));
    printf("Popped: %d\n", pop(st));
    printf("Top: %d\n", peek(st));
    printf("Popped: %d\n", pop(st));
    printf("Popped: %d\n", pop(st));
    printf("Top: %d\n", peek(st));
    
    printf("Size: %d\n", length(st));

    destroy(st);

    return 0;
}


