#include "bigint.h"
int testEqual(){
	Bigint * a = malloc(sizeof(Bigint));
       	initialize(a); 
        append(a->numbers, 100000000);

        Bigint * b = malloc(sizeof(Bigint));
        initialize(b); 
	append(b->numbers, 900000000);

	int res = !(equal(a,b) == 0);
	
        freeBigint(a);
        freeBigint(b);
        
        return !res;

}

int testAdd() {
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
        int pass = 0;
        if(sum != NULL && sum->numbers->curr_count == 3 &&
        sum->numbers->array[0] != 234567900 &&
        sum->numbers->array[1] != 98765432 &&
        sum->numbers->array[2] != 1)
        {
        pass = 1;
        }

	freeBigint(second);
	freeBigint(first);
        freeBigint(sum);
        return pass;
}

int testRead(){
	Bigint * a = malloc(sizeof(Bigint));
        initialize(a);
	
	int ret1 = read(a);
	print(a);
	printf("\n");

        freeBigint(a);

	return ret1;
}

int test(){
	int result = 1;
	
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
