#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h> 

typedef enum {INT, STR} Ntype;
typedef struct queue_t Queue;

struct queueNode;

/* create a new queue */
Queue *create_queue(Ntype t);
/* destroy the queue */
void destroy_queue(Queue *q);
/* clear the queue */
void clear_queue(Queue *q);

/* test whether the queue is empty */
bool is_empty(Queue *q);

/* append a value at the back of the queue */
void push(Queue *q, void *i, Ntype t);
/* return the first value in the queue (and remove it) */ 
void * pop(Queue *q);
/* return the first value without removing it */
void * peek_first(Queue *q);
/*return the last value in the queue without removing it */
void * peek_last(Queue *q);
/* return the length of the queue */
int length(Queue *q);

#endif
