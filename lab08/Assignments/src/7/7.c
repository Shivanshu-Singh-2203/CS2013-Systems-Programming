#include <stdio.h>
//TODO: Include appropriate header file for dynamic memory allocation
#include <stdlib.h>
#include <limits.h>

int Max(int a, int b)
{
	if(a > b )
	{
		return a;
	}
	else 
	{
		return b;}

}


int main()
{
	long n;
	int max;

	//Get the number of integers from the user
	scanf("%ld", &n);

	//Do not add/modify anything about this line
	//TODO: Complete the code
	int * arr = malloc(sizeof(int)*n);
	int *temp = arr;
	int * array = arr;
	for(int j = 0; j < n; j ++)
	{
		scanf("%d\n", temp); 
		temp ++;
	}


	max = INT_MIN;
	for(int j = 0; j < n ; j ++ )
	{
		max = Max(max, *array);
		array ++;
	}

	
        //TODO: DO NOT FORGET TO FREE ANY MEMORY ALLOCATED USING malloc() using
        // free()
	free(arr);
	
	//Do not add/modify anything below this line
	printf("%d\n", max);
	return 0;
}

