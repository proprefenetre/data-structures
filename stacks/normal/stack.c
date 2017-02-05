#include "stack.h"

static void stack_underflow(void);


struct stack_type {
    int size;
    struct Node *head, *tail;
};

Stack create_stack(void)
{
    Stack new_stack = malloc(sizeof(Stack));
    if (new_stack == NULL) {
	printf("Error: not enough memory\n");
	exit(EXIT_FAILURE);
    }

    new_stack->head = NULL;
    new_stack->tail = NULL;
    new_stack->size = 0;

    return new_stack;
}

/* void push(Stack list, char *str) */
void push(Stack list, int value)
{
    struct Node *head = list->head;
    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->next = NULL;
    new_node->idx = list->size;

    if (new_node == NULL) {
	printf("Error: not enough memory\n");
	exit(EXIT_FAILURE);
    }

    /* strcpy(new_node->data, str); */
    new_node->data = value;

    if (head == NULL) {
	list->head = new_node;
	list->size++;
	return;
    }

    new_node->next = head;
    list->head = new_node;
    list->size++;
}

struct Node *pop(Stack list)
{
    if (is_empty(list)) {
	stack_underflow();
    }
    struct Node *popped = list->head;
    list->head = popped->next;
    list->size--;
    return popped;
}

struct Node *peek(Stack list)
{
    if (is_empty(list)) {
	stack_underflow();
    }
    return list->head;
}

bool is_empty(Stack list)
{
    return 0 == list->size;
}

static void stack_underflow(void)
{
    printf("Error: empty Stack\n");
    exit(EXIT_FAILURE);
}

/*
char *read_name(void)
{
    char *name = malloc(sizeof(char *)), *name_ptr = name, ch;

    while ((ch = getchar()) != '\n') {
	*name_ptr++ = ch;
    }
    *name_ptr = '\0';

    return name;
}
*/

