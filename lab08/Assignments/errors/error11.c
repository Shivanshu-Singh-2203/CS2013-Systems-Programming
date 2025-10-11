/**
 * Read the code below and understand what it is attempting to do
 *
 * Also fix all errors (compile, logical and runtime errors)
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE  100

void fill_array(int *array, int size) {

	srand(time(NULL));
	for(int i=0; i<size; i++)
        array[i] = rand()%10;
}

/* array[slot] = value */
void update_slot(int *array ,int slot, int value) {
    array[slot] = value;
    printf("Updated index %d to %d\n", slot, value);
}

void  process_array(int *array, int size) {
    long ii = 100000000;

    for(int i=0; i<size; i++) {
        /* If the value is even, change it to 1000000 */
        if(array[i] % 2 == 0) {
            update_slot(array, i, ii);
        }
    }
}

int main() {
    int *array = malloc(ARRAY_SIZE * sizeof(int));

    fill_array(array, ARRAY_SIZE);
    process_array(array, ARRAY_SIZE);

    free(array);
    return 0;
}
