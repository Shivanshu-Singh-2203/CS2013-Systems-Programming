#include "linkedlist.h"
/* 
 * Inserts an element at the head of the linked list and update the head.
 *
 * This operation can modify the head of the linked list. Hence the head is
 * passed by reference.
 * 
 * For example, if the list is
 *      10->2->3->NULL
 * with head point to 10. Suppose insert(&head, 12) is called. Then the new list
 * looks as follows with head pointing to 12.
 *      12->10->2->3->NULL
 *
 * @param **ref_to_head Pointer to the head o{
		ar[i] = temp->data;
		temp  = temp->next;
		i ++;
	}
	Node* final = *ref_to_head;
	for(int k = si; k >= 0; k --) {
		final->data = ar[k - 1];
		final = final->next;
	}
	f the linked list is passed by
 *        reference (to allow for modifying the head). 
 * @param num The data to be addedPointer to the head of the linked list. 
 */ 

void insert(Node** ref_to_head, int num){

  // TODO: Read the docstring above and complete the code
	Node* temp = malloc(sizeof(Node));
	temp->data = num;

	temp->next = *ref_to_head;
	*ref_to_head = temp;
}


/* 
 * Searches for an element starting from the head of the linked list and return
 * a pointer to the first occurrence.  If the element is not found, a NULL
 * pointer is returned.
 *
 * This operation does not modify the linked list. Hence the head is passed by
 * value.
 *
 * For example, if the list is
 *      10->2->3->NULL
 * with head point to 10. Suppose search(head, 3) is called. Then, a pointer to
 * the node 3 is returned.
 *
 * @param *head Pointer to the head of the linked list. It may be NULL.
 * @param num The data to be added
 * @return A pointer to the node (if found) and NULL otherwise
 */ 

Node* search(Node* head, int num){

  // TODO: Read the docstring above and complete the code
	if(head == NULL)
	{
		return NULL;
	}
	if(head->data != num){
		return search(head->next, num);
	}
	return head;
}


/* 
 * Searches for an element starting from the head of the linked list and
 * deletes the element if found and deallocates the memory. It should also
 * adjust the pointers around the deleted node correctly after the deletion. If
 * the element is not found, it does not modify the list.
 *
 * This operation can modify the linked list head. Hence the head is passed by
 * reference.
 *
 * For example, if the list is
 *      10->2->3->NULL
 * with head point to 10. Suppose delete(head, 3) is called. Then, the
 * outcome will be 
 *      10->2->NULL
 *
 * Another example, if the list is 
 *      10->NULL
 * with the head pointing to 10, calling delete(head, 10) will give
 *      NULL
 * with the head pointing to NULL.
 *
 * @param **ref_to_head Pointer to the head of the linked list passed by
 *        reference. 
 * @param num The data to be added
 * @return Returns 1 if the delete occured and returns 0 otherwise
 */ 

int delete(Node** ref_to_head, int num){
/*
  Node* prev = NULL;
  // TODO: Read the docstring above and complete the code
  Node* current = ref_to_head;
  while(current->data != num){
	  if(current == ref_to_head){
		  prev = ref_to_head;
		  current = current->next;
	  }
	  else {
		  prev = current;
		  current = current->next;
	  }
  }
  Node* temp;
  temp = current->next;
  prev */


	Node* temp = search(*ref_to_head, num);
	if(temp == NULL){
		return 0;
	}
	
	if(temp == *ref_to_head){
		temp = temp->next;
		*ref_to_head = temp;
		return 1;
	}
	Node* prev = NULL;
	Node* current = *ref_to_head;

	while(current != temp)
	{

		prev = current;	
		current = current->next;

	
	}

	Node* g;
	g = current->next;
	prev->next = g; 
	return 1;
}
	

/* 
 * Takes a linked list and reverses all the direction of the arrows and updates
 * the head appropriately. If the linked list is empty, it does nothing.
 *
 * This operation can modify the linked list head. Hence the head is passed by
 * reference.l{
		ar[i] = temp->data;
		temp  = temp->next;
		i ++;
	}
	Node* final = *ref_to_head;
	for(int k = si; k >= 0; k --) {
		final->data = ar[k - 1];
		final = final->next;
	}
	
 *
 * For example, if the list is
 *      10->2->3->NULL
 * with head point to 10. Then, calling reverse(head) will give a linked list
 *      3->2->10->NULL
 * with the head now pointing to 3.
 *
 * @param **ref_to_head Pointer to the head of the linked list passed by
 *        reference.
 */ 

void reverse(Node** ref_to_head){

	if((*ref_to_head == NULL) || ((*ref_to_head)->next == NULL)) {
		return;
	}
	Node* head = *ref_to_head;
	Node* c = head->next;
	reverse(&c);
	head->next->next = head;
	head->next = NULL;
	
	*ref_to_head = c;
}

/* 
 * Prints the linked list starting from the head. Prints -1 if the list is
 * empty
 *
 * For example, if the list is
 *      10->2->3->NULL
 * the output will be
 *      10 2 3
 *
 * @param *head Pointer to the head of the linked list. It may be NULL.
 */ 

void print(Node* head){
	Node* temp;
	temp = head;
	
	if(temp == NULL){
		printf("-1");
	}
	while(temp!= NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

}

void freeNode(Node* head){
	if(head == NULL){
		return;
	}
	free(head);
	return freeNode(head->next);
}


