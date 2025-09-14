#include <stdio.h>

#define SIZE 7

int main()
{
	char input [SIZE];
	int result;

	scanf("%s", input);

	result = 0;
	int base = 1;

	for(int i = SIZE -2 ; i >= 2; i --)
	{
		char c = input[i];
		int temp2;

		if(c >= 'a' && c <= 'f')
		{
			temp2 = c - 'a' + 10;
		}
		else if(c >= 'A' && c <= 'F' )
		{
			temp2 = c - 'A' + 10;
		}
		else if (c >= '0' && c <= '9') 
		{
			temp2 = c - '0';
		}

		else
		{
			temp2 = 0;
		}


		result += temp2*base;
		base *= 16;
	}
	
	printf("%d\n", result);
	return 0;
}

