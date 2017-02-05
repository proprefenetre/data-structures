/* a linked list */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char *str;
	struct Node *next;
	struct Node *prev;
};

typedef struct charlist {
	struct Node *head;
	struct Node *tail;
} Charlist;

Charlist *create_charlist();

void prepend(Charlist *list, char *str);
void append(Charlist *list, char *str);

void delete_node(Charlist *list, char *str);

#endif /* ifndef LINKEDLIST_H */
