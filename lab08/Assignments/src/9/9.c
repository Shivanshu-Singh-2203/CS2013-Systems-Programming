#include <stdio.h>
//TODO: Include appropriate header file for dynamic memory allocation
#include <stdlib.h>

int main()
{
	long size = 0;
	char* str = NULL;

	scanf("%ld", &size);

	//Do not add/modify anything about this line
	//TODO: Complete the code
	
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
        //TODO: DO NOT FORGET TO FREE ANY MEMORY ALLOCATED USING malloc() using
        // free() 
	free(str);
	//Do not add/modify anything below this line
	return 0;
}

