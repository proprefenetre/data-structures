#include <stdio.h> 
#include "stack.h" 

int main(void)
{
    Stack st = create_stack();

    for (double i = 0; i <= 10.0; i++) {
        push(st, i);
    }

    while (length(st) > 0) {
        printf("%.2f\n", pop(st));
    }

    return 0;
}
