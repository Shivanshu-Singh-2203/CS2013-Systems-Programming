#include <stdio.h>

int main()
{
	int a = 0;

	//Get an integer from the user
	scanf("%d", &a);

	//Do not add/modify anything about this line
	//TODO: Complete the code
	int current = 1;
	if(a == 0)
	{                        printf("Not power of 3\n");
	}
	while( current < a) 
	{
		if (a%(current) != 0)
		{
			printf("Not power of 3\n");
			break;
		}
		current  = current * 3;
	}
	if (current == a)
	{
		printf("Power of 3\n");
	}
	//Do not add/modify anything below this line
	return 0;
}

