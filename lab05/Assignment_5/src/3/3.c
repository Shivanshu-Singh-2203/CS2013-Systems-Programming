#include <stdio.h>

int main()
{
	int a;

	//Get an integer from the user
	scanf("%d", &a);

	//Do not add/modify anything about this line
	//TODO: Complete the code
	if(a > 0)
	{
		printf("Positive");
	}
	else if(a < 0)
	{
		printf("Negative");
	}
	else 
	{
		printf("Zero");
	}
	
	//Do not add/modify anything below this line
	return 0;
}

