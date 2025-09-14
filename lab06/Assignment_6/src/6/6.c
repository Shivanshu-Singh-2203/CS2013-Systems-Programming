#include <stdio.h>

int main()
{
	int a = 0, n;

	scanf("%d", &a);

	n = a/2  + 1;
	for(int i = n; i > 0; i --)
	{
		for(int j = 0; j < i; j ++)
		{
			printf("%d",j + i);
		}
		printf("\n");
	}
	return 0;
}

