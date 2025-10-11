#include "stack.h"

int stack[SIZE];

int head = -1;

int stack_head(int* data_ptr){
	if(head == -1){
		return 1;
	}
	*data_ptr = stack[head];
	return 0;
}

int push(int data){
	if(head >= SIZE){
		return 1;
	}
	stack[++head] = data;
	return 0;
}

int pop(int* data_ptr){
	if(head == -1){
		return 1;
	}
	*data_ptr = stack[head];
	head --;
	return 0;
}
