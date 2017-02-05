#include "linkedlist.h"

int main(void)
{
	Charlist *list = create_charlist();
	struct Node *current;

	char *jan = "jan", *joris = "joris", *piet = "piet", *corneel = "corneel";

	prepend(list, jan);
	prepend(list, piet);
	prepend(list, joris);
	prepend(list, corneel);

	current = list->tail;
	printf("\n");
	while (current->prev) {
		printf("%s\n", current->str);
		current = current->prev;
	}
	printf("\n");
	
	return 0;
}

