#include "bigint.h"
#define POWNINE 1000000000
void initialize(Bigint* newptr){
	newPtr = malloc(sizeof(Bigint));
	if(newPtr == NULL){
		return ;
	}

	newPtr->numbers = malloc(sizeof(List));
	if(newPtr->numbers ==  NULL){
		return ;
	}

	newPtr->numbers->array = malloc(sizeof(int));
	if(newPtr->numbers->array ==  NULL){
		return ;
	}
	newPtr->sign = 1;
	newPtr->numbers->max_count = 0;
	newPtr->numbers->curr_count = 0;
	return ;
}

void free_bigint(Bigint* bi_ptr){
	if(bi_ptr == NULL){
		return;
	}

	if(bi_ptr->numbers != NULL)
	{
		if(bi_ptr->numbers->array != NULL){
			free(bi_ptr->numbers->array);
		}
		free(bi_ptr->numbers);		
	}
	free(bi_ptr);
}

Bigint* add(Bigint* first, Bigint* second){
	if(second == NULL){
		return first;
	}

	if(first == NULL){
		return second;
	}

	Bigint* temp = malloc(sizeof(Bigint));
	temp->numbers = malloc(sizeof(List));

	int maxSize;
	int aCount = first->numbers->curr_count;
	int bCount = second->numbers->curr_count;
	if(aCount < bCount){
		maxSize = bCount;
	} else {
		maxSize = aCount;
	}
	long carry = 0;
	for (int j = 0; j < maxSize ; j ++){
		long fval = j > aCount ? 0 : first->numbers->array[j];
		long sval = j > bCount ? 0 : second->numbers->array[j];

		long sum = carry + fval + sval;
		append(temp->numbers, sum%POWNINE);
		carry = sum/POWNINE;
	}

	if (carry > 0){
		append(temp->numbers, carry);
	}
	return temp;

}

void print (Bigint* num_ptr){
	if(num_ptr == NULL || num_ptr->numbers == NULL){
		return;
	}

	int count = num_ptr->numbers->curr_count ;
	for(int  i = count - 1; i >= 0; i --){
		i == count - 1 ? printf("%d ", num_ptr->numbers->array[i]) : printf("%09d ", num_ptr->numbers->array[i]);
	}
printf("\n");
	
}

int equal (Bigint* a, Bigint* b){
	if(a->sign != b ->sign){
		return 1;
	}

	if(a->numbers-> curr_count != b->numbers->curr_count){
		return 1;
	}

	int count = a->numbers->curr_count ;
	for(int i = 0 ; i < count ; i ++ ){
		if(a->numbers->array[i] != b->numbers->array[i])
		{
			return 1;
		}
	}
	return 0;

}

int read(Bigint* num){
	if(num == NULL){
		Bigint *nnum = realloc(num, sizeof(Bigint));
		if(nnum == NULL) {
			return 1;
		}
		num = nnum;
	}

	char op;
	int number;
	int pass  = 1;
	while(pass){

		scanf("%d",&number);
		append(num->numbers, number);
		scanf("%c", &op);
		if(op == '\n'){
			pass = 0;	
		}
	}
	return 0;
}
