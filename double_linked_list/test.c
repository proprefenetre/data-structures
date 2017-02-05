#include "doublelinkedlist.h"

int main(void)
{
    Linkdlst *list = new_lst();

    insert_front(list, "jan");
    insert_front(list, "piet");
    insert_front(list, "joris");

    insert_back(list, "jan");
    insert_back(list, "piet");
    insert_back(list, "joris");

    print_from_front(list);
    printf("\n");

    return 0;
}
