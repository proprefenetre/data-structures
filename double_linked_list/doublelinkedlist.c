
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublelinkedlist.h"

static void mem_check(void *p)
{
    if (p == NULL) {
	printf("Error: out of memory");
	exit(EXIT_FAILURE);
    }
}

Linkdlst *new_lst(void) {
    Linkdlst *new = malloc(sizeof(Linkdlst));
    mem_check(new);

    new->head = NULL;
    new->tail = NULL;
    new->size = 0;

    return new;
}

void insert_front(Linkdlst *lst_ptr, char *str)
{
    struct Node *head_ptr = lst_ptr->head;
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->next = new_node->prev = NULL;

    mem_check(new_node);
    
    strcpy(new_node->str, str);
    
    if (is_empty(lst_ptr)) {
	lst_ptr->head = lst_ptr->tail = new_node;
	return;
    }

    head_ptr->prev = new_node;
    new_node->next = head_ptr;
    
    lst_ptr->head = new_node;
}

void insert_back(Linkdlst *lst, char *str)
{
    struct Node *tail = lst->tail;
    struct Node *new_node = malloc(sizeof(struct Node));
    mem_check(new_node);
    
    strcpy(new_node->str, str);
    
    if (is_empty(lst)) {
	lst->head = lst->tail = new_node;
	return;
    }

    tail->next = new_node;
    new_node->prev = tail;
    
    lst->tail = new_node;
}

void print_from_front(Linkdlst *lst)
{
    struct Node *cur = lst->head;
    while (cur) {
	printf("%s\n", cur->str);
	cur = cur->next;
    }
}

/*
void print_from_back(Linkdlst *lst);
*/

bool is_empty(Linkdlst *list)
{
    return list->head == NULL;
}


