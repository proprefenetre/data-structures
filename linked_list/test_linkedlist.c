#include <stdio.h> 
#include "linkedlist.h"

int main(void)
{
    List *l = init_list();

    for (int i = 0; i < 10; i++) {
        prepend(l, i);
        append(l, i);
        print_list(l);
        printf("\n");
    }

    printf("%d\n", l->size);
    
    return 0;
}

