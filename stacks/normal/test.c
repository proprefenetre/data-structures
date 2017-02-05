#include "stack.h"

int main(void)
{
    Stack st = create_stack();
    int i;
    
    for (i = 50; i-- > 0; ) {
	push(st, i);
    }

    printf("%d\n", peek(st)->data);
    pop(st);
    printf("%d\n", peek(st)->data);
    pop(st);
    pop(st);
    printf("%d\n", peek(st)->data);
    pop(st);
    pop(st);
    pop(st);
    printf("%d\n", peek(st)->data);

    return 0;
}


