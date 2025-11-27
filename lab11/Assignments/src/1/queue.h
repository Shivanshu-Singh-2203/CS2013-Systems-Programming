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
int front(Queue* q, int* dataptr);
int dequeue(Queue* q, int* dataptr);
int size(Queue* q);
void display(Queue* q);
void reverseQueue(Queue* q);
void search(Queue* q);
#endif
