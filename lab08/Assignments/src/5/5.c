#include <stdio.h>
//TODO: Include appropriate header file for dynamic memory allocation
#include <stdlib.h>
int main()
{
	long n;

	//Get the number of integers from the user
	scanf("%ld", &n);

	//Do not add/modify anything about this line
	//TODO: Complete the code

	int * arr = malloc(sizeof(int)*n);
	int *temp = arr;
	int * array = arr;
	for(int j = 0; j < n; j ++)
	{
		scanf("%d\n", array); 
		array ++;
	}

		
	while(temp < array)
	{
		printf("%d", *temp);
		temp ++;
	}



	//TODO: DO NOT FORGET TO FREE ANY MEMORY ALLOCATED USING malloc() using
	// free() 
	
	free(arr);
	
	//Do not add/modify anything below this line
	return 0;
}

