#include <stdio.h> 

#include "queue.h" 

int main(void)
{
    Queue *q = create_queue(STR), *int_q = create_queue(INT);

    char *msg = "hallo wereld!";
    int j, k, i[5] = {0}, *intptr[5];

    push(q, msg, STR);

    for (j = 0; j < 5; j++) {
        i[j] = j;
        intptr[j] = &i[j];
        push(int_q, intptr[j], INT);
        push(q, intptr[j], INT);
    }

    printf("%s\n", (char *) pop(q));

    for (k = 0; k < 5; k++) {
        printf("%d\n", *(int *) pop(int_q));
    }

    destroy_queue(q);
    destroy_queue(int_q);

    return 0;
}


