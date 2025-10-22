#include <stdio.h>
//TODO: Include appropriate header file for dynamic memory allocation
#include <stdlib.h>

int main()
{
	long size = 0;
	char* str = NULL;

	scanf("%ld", &size);


	str = malloc(sizeof(char)*(size + 1));
	scanf("%s", str);
	char* temp = str;
	while(*temp != '\0')
	{
		temp ++;
		
	}
	temp --;
	while(temp != str)
	{
		printf("%c",*temp);
		temp --;
	}
	printf("%c",*temp);
	free(str);
	return 0;
}

