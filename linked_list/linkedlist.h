/* a linked list */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h> 

struct node {
    int val;
    struct node *next;
};

typedef struct list {
    int size;
    struct node *head;
} List;

List *init_list(void);
void prepend(List *l, const int val);
void append(List *l, const int val);
void print_list(const List *l);
bool is_empty(const List *l);

#endif /* ifndef LINKEDLIST_H */
