#include <stdio.h>
#include <stdlib.h> 
#include "linkedlist.h"

static void check(const void *p)
{
    if (p == NULL) {
        fprintf(stderr, "Error: NULL pointer.\n");
        exit(EXIT_FAILURE);
    }
}

bool is_empty(const List *l)
{
    return l->head == NULL;
}

List *init_list(void)
{
    List *nl = malloc(sizeof(List));
    check(nl);

    nl->head = NULL;
    nl->size= 0;

    return nl;
}

void append(List *l, const int val)
{
    struct node *head = l->head;
    struct node *n = malloc(sizeof(struct node));
    check(n);
    n->val = val;
    n->next = NULL;

    if (head == NULL) {
        l->head = n;
        return;
    }

    while (head->next) {
        head = head->next;
    }
    head->next = n;
    l->size++;
}

void prepend(List *l, const int val)
{
    struct node *head = l->head;
    struct node *n = malloc(sizeof(struct node));
    check(n);
    n->val = val;
    n->next = NULL;

    n->next = head;
    l->head = n;
    l->size++;
}

void print_list(const List *l)
{
    struct node *cur = l->head;
    while (cur) {
        printf("%d\n", cur->val);
        cur = cur->next;
    }
}




