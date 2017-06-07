#ifndef DOUBLELINKDLST_H
#define DOUBLELINKDLST_H

#include <stdbool.h>

#define MAX_STR_SIZE 20
struct Node {
    char str[MAX_STR_SIZE];
    struct Node *next;
    struct Node *prev;
};

typedef struct linkdlst {
    int size;
    struct Node *head;
    struct Node *tail;
} Linkdlst;


Linkdlst *new_lst(void);
void insert_front(Linkdlst *lst, char *str);
void insert_back(Linkdlst *lst, char *str);
void print_from_front(Linkdlst *list);
void print_from_back(Linkdlst *list);
bool is_empty(Linkdlst *list);
#endif /* ifndef DOUBLELINKDLST_H */
