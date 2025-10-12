#include "bigint.h"
#include "list.h"
#include <stdlib.h>

/*
 * Implementation of Big Integer using list in C. For details on implementation
 * of the functions, see the docstring in bigint.h.
 *
 */

//TODO: Add appropriate header files

// Number stored as a list with each storing 9 digits of the number
// Why 9 ? 9 = 32*log(2)/log(10)
#define POWNINE 1000000000


/*
 * Function to free memory used for a big integer
 */

void free_bigint(Bigint* bi_ptr){
        if(bi_ptr->numbers->array == NULL){
                 
        }

        if(bi_ptr->numbers != NULL){
                free(bi_ptr->numbers);
        }
        free(bi_ptr);
}

/*
 * Initializes a big integer
 *
 */
void initialize(Bigint* bi_ptr){
	// TODO: Complete the function
	Bigint* newBigInt = malloc(sizeof(Bigint));
	newBigInt->numbers = malloc(sizeof(List));
        newBigInt->numbers->array = NULL;
	newBigInt->sign = 1;
	bi_ptr = newBigInt;
}

/*
 * Check if two big integers are equal or not
 *
 */
int areEqualLists(List* first, List* second){

        
        if(first == NULL && second == NULL){
                return 0;
        }

        if(first == NULL || second == NULL){
                return 1;
        }

        if(first->curr_count != second->curr_count){
                return 1;
        }
        
        size_t curr = first->curr_count;
        for(int i = 0; i < curr; i ++){
                if(first->array[curr] != second->array[curr]){
                        return 1;
                }
        }
        return 0;
}

int equal(Bigint* a_ptr, Bigint* b_ptr){
        return !(areEqualLists(a_ptr->numbers, b_ptr->numbers) && (a_ptr->sign == b_ptr->sign));       	
}


/*
 * Adds two big integer numbers and returns a pointer to the resulting sum
 *
 */
Bigint* add(Bigint* a_ptr, Bigint* b_ptr)
{
        if(a_ptr == NULL && b_ptr == NULL){
                return NULL;
        }

        if (!a_ptr) {
                return b_ptr;
        }

        if(!b_ptr){
                return a_ptr;
        }

        Bigint* temp = malloc(sizeof(Bigint));
        temp->numbers = malloc(sizeof(List));
        long carry = 0;


        int maxSize = 0;
        if(a_ptr->numbers->curr_count > b_ptr->numbers->curr_count){
                maxSize = a_ptr->numbers->curr_count;
        }

        else {
                maxSize = b_ptr->numbers->curr_count;
        }

        int aCount = a_ptr->numbers->curr_count;
        int bCount = b_ptr->numbers->curr_count;

        for(int i = 0; i < maxSize; i ++){
                int aVal = i < aCount ? a_ptr->numbers->array[i] : 0;
                int bVal = i < bCount ? b_ptr->numbers->array[i] : 0;
                
                long sum = aVal + bVal + carry;
                carry = sum/POWNINE;
                append(temp->numbers, sum%POWNINE);
        
        }

        if(carry > 0){
                append(temp->numbers, carry);
        }
        return temp;
}
/*
 * Print a big integer passed as argument
 */

void print(Bigint* num_ptr){
        if(!num_ptr || !num_ptr->numbers || !num_ptr->numbers->array || !num_ptr->numbers->curr_count) printf("0\n");
        int maxIndex = num_ptr->numbers->curr_count-1;
        for(int i = maxIndex; i >= 0; i ++){
                if(i == maxIndex){
                        printf("%d",num_ptr->numbers->array[i]);
                }
        
                else {
                        printf("%09d", num_ptr->numbers->array[i]);
                }
        }
        printf("\n");
}

/*
 * Read a big integer
 *
 */

int read(Bigint *num){  
        if(num == NULL || num->numbers == NULL){
                return 1;
        }

        num->numbers->curr_count = 0;
        long number = 0;
        char c ;
        while(1){
                int ret = scanf("%ld%c", &number, &c);
                if(ret != 2){
                        return 1;
                }

                if(append(num->numbers, number)){
                        return 1;
                }
                
                if(c == ' '){
                        continue;
                }

                if(c == '\n'){
                        break;
                }
                return 1;
        }
        return 0; 
}
