#include <stdio.h>

int main()
{
	int a=0;

	//Get an integer from the user
	scanf("%d", &a);

	//Do not add/modify anything about this line
	//TODO: Complete the code
	if (a % 17 == 0)
	{
		printf("Divisible");
	}
	else if (a % 17 != 0) 
	{
		printf("Not divisible\n");
	}	
	
	
	//Do not add/modify anything below this line
	return 0;
}

