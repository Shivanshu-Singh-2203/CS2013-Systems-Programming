// Include macros to avoid multiple inclusions
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//TODO Include necessary header files
#include <stdio.h>
#include <stdlib.h>
// TODO: Define the struct node appropriately
struct node {
	int data;
	struct node* next;
};


// Avoids the need to type `struct node` each time
typedef struct node Node;
void freeNode(Node* head);
void insert(Node**, int);
Node* search(Node*, int);
int delete(Node**, int);
void reverse(Node**);
void print(Node*);
// Function declarations 
//TODO: Complete the code


#endif
// TODO: Handle end of #ifndef macro
