#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>

struct queue{
	int* array;
	size_t head;
	size_t tail;
};

typedef struct queue Queue;

void enqueue(Queue* q, const int val);
int headElement(Queue* q);
void dequeue(Queue* q);

#endif
