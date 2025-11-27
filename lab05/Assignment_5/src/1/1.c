#include <stdio.h>

int main()
{
	int a=0, b=0 ;
	char op ;
	int result;

	scanf("%d %d %c", &a, &b, &op);

	if(op == '+')
	{
		result = a + b;
	}
	
	else if(op == '-')
	{
		result = a - b;
	}

	else if (op == '*')
	{
		result = a * b;
	}

	else
	{
		result = a / b;
	}	
	
	printf("%d\n", result);
	return 0;
}

