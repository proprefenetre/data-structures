/* Implementation of a (generic) queue */

#include <assert.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <stdarg.h> 

#include "queue.h" 

#define allocation_check(x)     fallocation_check(x, __func__)
#define TYPE(x) (((x) == INT) ? "INT" : "STR")

struct queueNode {
    void * data;
    struct queueNode *next;
};

struct queue_t {
    Ntype type;
    struct queueNode *head;
    struct queueNode *tail;
    int length;
};

static void my_error(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    /* exit(EXIT_FAILURE); */
}

static void fallocation_check(void *p, const char *str)
{
    if (p == NULL) {
        my_error("Error in %s: failed to allocate memory. Exiting.\n", str);
    }
}

static void exists(Queue *q)
{
    if (q == NULL) {
        my_error("Error in %s: Queue does not exist. \n");
    }
}
/* static char * typename(Ntype t) */
/* { */
/*     if (t == INT) { */
/*         return "INT"; */
/*     } else if (t == STR) { */
/*         return "STR"; */
/*     } */
/* } */

Queue *create_queue(Ntype t) 
{
    Queue *new_queue = malloc(sizeof(Queue));
    allocation_check(new_queue);
    new_queue->type = t;
    new_queue->head = NULL;
    new_queue->tail = NULL;
    new_queue->length = 0;
    
    return new_queue;
}

void destroy_queue(Queue *q)
{
    clear_queue(q);
    free(q);
}

void clear_queue(Queue *q) 
{
    while (!is_empty(q)) {
        pop(q);
    }
}

bool is_empty(Queue *q) 
{
    exists(q);
    return q->length == 0;
}

void push(Queue *q, void * i, Ntype t)
{
    exists(q);
    struct queueNode *head = q->head;
    struct queueNode *prev = NULL;
    struct queueNode *new_node = malloc(sizeof(struct queueNode));
    allocation_check(new_node);

    new_node->data = i;
    if (t != q->type) {
        my_error("Error -- wrong type: queue accepts %s, received %s\n", TYPE(q->type), TYPE(t));
    }

    if (head == NULL) {
        q->head = new_node;
    } else {
        while (head) {
            prev = head;
            head = head->next;
        }
        prev->next = new_node;
    }
    q->tail = new_node;
    q->length++;
}

void * pop(Queue *q)
{
    void *d;
    struct queueNode *head = q->head;

    if (is_empty(q)) {
        my_error("Error in %s: queue is empty. exiting.\n", __func__);
    }

    d = head->data;
    q->head = head->next;
    q->length--;
    free(head);
    return d;
}

void * peek_first(Queue *q)
{
    if (is_empty(q)) {
        my_error("Error in %s: queue is empty. exiting.\n", __func__);
    }
    return q->head->data;
}

void * peek_last(Queue *q)
{
    struct queueNode *current = q->head;
    if (is_empty(q)) {
        my_error("Error in %s: queue is empty. exiting.\n", __func__);
    }

    while (current->next) {
        current = current->next;
    }
    return current->data;
}

int length(Queue *q)
{
    return q->length;
}
