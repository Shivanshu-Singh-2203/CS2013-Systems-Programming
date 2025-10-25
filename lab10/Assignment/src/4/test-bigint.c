/*
 * Unit testing for the list library
 *
 */

// TODO: Add appropriate header files

#include "bigint.h"
int testEqual(){
	Bigint * a = malloc(sizeof(Bigint));
       	a->numbers= malloc(sizeof(List)); 
        append(a->numbers, 100000000);

        Bigint * b = malloc(sizeof(Bigint));
        
       	b->numbers= malloc(sizeof(List)); 
		append(b->numbers, 900000000);

	int res = !(equal(a,b) == 0);
	return !res;

}

int testAdd() {
    // Test 1: Same length, no carry
   	Bigint* first;
	first = malloc(sizeof(Bigint));
	first->numbers = malloc(sizeof(List));
    append(first->numbers, 123456789);
    append(first->numbers, 987654321);

   	Bigint *second;
	second = malloc(sizeof(Bigint));
	second->numbers = malloc(sizeof(List));
    append(second->numbers, 111111111);
    append(second->numbers, 111111111);

    Bigint *sum = add(first,second);

    // Expected sum: block 0 = 234,567,900, block1 = 1,098,765,432?  
    // Actually sum by blocks:
    // block 0: 123456789 + 111111111 = 234,567,900 (no carry)
    // block 1: 987654321 + 111111111 = 1,098,765,432 → store 98,765,432, carry 1
    // append carry → 1 → block2
    int pass = 0;
    if(sum != NULL && sum->numbers->curr_count == 3 &&
       sum->numbers->array[0] != 234567900 &&
       sum->numbers->array[1] != 98765432 &&
       sum->numbers->array[2] != 1)
    {
        pass = 1;
    }

	free_bigint(second);
	free_bigint(first);
    return pass;
}

int testRead(){
	Bigint * a = malloc(sizeof(Bigint));
        initialize(a);
	
	int ret1 = read(a);
	print(a);
	printf("\n");

	free_bigint(a);

	return ret1;
}

int testInitialize(){
	Bigint a;
	initialize(&a);
	if(a.numbers == NULL || a.numbers->array == NULL){
	        return 1;
	}
	append(a.numbers, 200);
	if (a.numbers == NULL || a.numbers->array[0] != 200){
		return 1;
	}
	return 0;
	// return pass;
} 

///////////////////////////////////////
// Do not modify the functions below //
//////////////////////////////////////

int test(){
	int result = 1;
	
/* 	if(testInitialize()){
		printf("Initialization failed\n");
		result = 0 ;
	}else {
		printf("test passed\n");
	}*/
 if(testAdd()){
		printf("\tadd() failed\n");
		result = 0;
	}else{
		printf("add() passed\n");
	}
	if(testEqual()){
		printf("\tequal() failed\n");
		result = 0;
	}else{
		printf("equal() passed\n");
	}

	if(testRead()){
		printf("\tread() failed\n");
		result = 0;
	}else{
		printf("read() passed\n");
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
