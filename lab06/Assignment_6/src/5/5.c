#include <stdio.h>

int main()
{
	long a,b,tmp;

	scanf("%ld %ld", &a, &b);
	if(b != 0)
	{
	
	while(a % b != 0)
	{
		tmp = a%b;
		a = b;
		b = tmp;
	}
		
		printf("%ld", b);
	}
	else {
		printf("%ld", a);}

	return 0;
}

