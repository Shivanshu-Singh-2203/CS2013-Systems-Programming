#include <stdio.h>
int main()
{
	int value = 0;
	printf("Enter a positive number: ");
	scanf("%d", &value);

	if(value & 1 == 0)
		printf("The number was even\n");
	else
		printf("The number was odd\n");
	return 0;
}

