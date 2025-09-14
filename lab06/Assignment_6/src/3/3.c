#include <stdio.h>

int main()
{
	int a;

	scanf("%d", &a);

	long fib0 = 0, fib1 = 1, fib2 = fib0+fib1;

	printf("%ld\n", fib0);
	if(a != 0)
	{
		printf("%ld\n", fib1);
	}

	while(fib2 <= a)
	{

		printf("%ld\n", fib2);
		fib0 = fib1;
		fib1 = fib2;
		fib2 = fib1 + fib0;
	}

	return 0;
}

