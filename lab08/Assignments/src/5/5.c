#include <stdio.h>
#include <stdlib.h>

int main(void){
	unsigned int size;
	scanf("%u", &size);
	int* array = malloc(sizeof(int)* size);
	for(int i = 0; i < size; i ++){
		scanf("%d", &array[i]);
	}

	for(int i = 0; i < size; i ++ ){
		printf("%d", array[i]);
	}
	printf("\n");

	free(array);
	return 0;
}

