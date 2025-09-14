#include <stdio.h>
#define SIZE 100

int main()
{
	char str1 [SIZE];
	char str2 [SIZE];
	char destination [2*SIZE];

	scanf("%s %s", str1, str2);

	char* ptr1 = str1;
	char* ptr2 = str2;
	char* dest = destination;
	while(*ptr1 != '\0')
	{
		*dest = *ptr1;
		ptr1 ++;
		dest ++;
		
	}
	while(*ptr2 != '\0')
	{

		*dest = *ptr2;
		ptr2 ++;
		dest ++;


	}
	*dest = *ptr2;
	printf("%s\n",destination);	
		
	return 0;
}

