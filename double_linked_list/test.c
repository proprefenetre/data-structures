#include <stdio.h> 
#include "doublelinkedlist.h"

int main(void)
{
    Linkdlst *list = new_lst();

    insert_back(list, "jan");
    insert_back(list, "piet");
    insert_back(list, "joris");

    insert_front(list, "korneel");

    print_from_front(list);
    printf("\n");

    return 0;
}
