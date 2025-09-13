#include <stdio.h>

int main()
{
	int a=0, b=0, c=0;

	//Get three integers from the user
	scanf("%d %d %d", &a, &b, &c);

	//Do not add/modify anything about this line
	//TODO: Complete the code
	if (b*b < 4*a*c)
	{
		printf("Complex");
	}
	else{
		printf("Real");
	}



	//Do not add/modify anything below this line
	return 0;
}

