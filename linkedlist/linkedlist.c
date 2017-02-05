#include "linkedlist.h"

static void memcheck(void *p)
{ 
	if (p == NULL) {
		printf("Error: out of memory\n");
		exit(EXIT_FAILURE);
	}
}


Charlist *create_charlist()
{
	Charlist *new_list = malloc(sizeof(Charlist));
	memcheck(new_list);
		
	new_list->head = NULL;
	new_list->tail = NULL;

	return new_list;
}


void prepend(Charlist *list, char *str)
{
	struct Node* head_ptr = list->head;
	struct Node* new_node = malloc(sizeof(struct Node));
	memcheck(new_node);

	if (head_ptr == NULL) {
		head_ptr = new_node;
		return;
	}
	
	new_node->str = str;
	head_ptr->prev = new_node;
	new_node->next = head_ptr;

	list->head = new_node;

	/* why this?: */
	if (list->tail == NULL)
		list->tail = new_node;
}


void delete_node(Charlist *list, char *str)
{
	struct Node* cur = list->head;
	struct Node* prev = NULL;

	while (cur) {
		if (cur->str == str) {
			if (prev) {
				prev->next = cur->next;
			} else {
				list->head = cur->next;
			}
			if (cur->next == NULL) {
				list->tail = cur;
			}

			free(cur);
			break;
		}
		prev = cur;
		cur = cur->next;
	}
}
