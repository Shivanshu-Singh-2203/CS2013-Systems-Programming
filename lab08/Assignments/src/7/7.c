#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(void){
	unsigned int size;
	scanf("%u", &size);
	
	int * array = malloc(sizeof(int)*size);
	for(int i = 0; i < size; i ++){
		scanf("%d", &array[i]);
	}

	int max = INT_MIN;
	for(int i = 0; i < size; i ++ ){
		max = max > array[i] ? max : array[i];
	}
	printf("%d", max);
	return 0;
}
