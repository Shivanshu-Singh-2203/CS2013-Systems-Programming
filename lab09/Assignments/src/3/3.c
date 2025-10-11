#include <stdio.h>

// TODO: Implement the binary tree, and the interactive traversal of the tree
/*
           2
         /   \
        7     9
       /     / \
      15    11  13
     /  \
    18  20
*/

   struct tree_node {
	int data;
	struct tree_node* left;
	struct tree_node* right;
//	/*struct tree_node* parent;
   };


typedef struct  tree_node Tree;

Tree* createNode(int val){
	Tree* temp = (Tree*)malloc(sizeof(Tree));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void buildTree(Tree** node){
	printf("Enter the choice : ");
	int choice;

}

void inOrderToTree(int* element, int start, int end, Tree* node){
	if(start > end){
		Node* temp = NULL;
		node = temp;
		return;
	}	
	int mid = (end - start)/2 + start;
	node->data = element[mid];
	Tree* leftChild = node->left;
	Tree* rightChild = node->right;
	inOrderToTree(element, start, mid - 1, leftChild);	
	inOrderToTree(element, mid + 1; end; rightChild);
}



