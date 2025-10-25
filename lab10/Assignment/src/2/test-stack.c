/*
 * Unit testing for the stack library
 *
 */

#include <stdio.h>
#include "stack.h"

// Test cases for push is written below
// TODO: Add two more test cases and modify the code appropriately
int testPush(){

	int ret1 = push(1);
	int ret2 = push(2);
	int head;
	int ret3 = stack_head(&head);
	int check3 = !(head == 2);

	return (ret1 || ret2 || ret3|| check3) ;
}

// TODO: Write test cases for pop
int testPop() {
    int val;

    int el1 = push(3);
    int el2 = push(4);
    int ret1 = pop(&val);
    int check1 = !(val == 4); // last pushed (LIFO)

    int ret2 = pop(&val);
    int check2 = !(val == 3);

    int ret3 = pop(&val);
    int check3 = !(val == 2);

    int ret4 = pop(&val);
    int check4 = !(val == 1);

    // stack now empty
    int ret5 = pop(&val); // should fail
    int check5 = !(ret5 == 1);

    return (ret1 || el1 | el2 || check1 || ret2 || check2 || ret3 || check3 || ret4 || check4 || check5);
}
// TODO: Write test cases for stack_head
int testHead() {
    int head;

    // After popping everything, push one new element
    push(42);

    int ret1 = stack_head(&head);
    int check1 = !(head == 42);

    int ret2 = pop(&head);
    int ret3 = stack_head(&head); // stack now empty → should fail
    int check3 = !(ret3 == 1);

    return (ret1 || check1 || ret2 || check3);
}

int test(){
	int result = 1;

	if(testPush()){
		printf("\tpush() failed\n");
		result = 0;
	}else{
		printf("push() passed\n");
	}

	if(testPop()){
		printf("\tpop() failed\n");
		result = 0;
	}else{
		printf("pop() passed\n");
	}

	if(testHead()){
		printf("\tstach_head() failed\n");
		result = 0;
	}else{
		printf("stack_head() passed\n");
	}

	return result;
}



int main(){

	printf("Running all test cases\n\n");
	if(test()){
		printf("\nAll test cases passed\n");
	}else{
		printf("\nSome test cases did not pass\n");
	}

	return 0;
}
