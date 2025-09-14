#include <stdio.h>

#define SIZE 100

int main()
{
	char string [SIZE];
	char* ptr = NULL;
	char* head = NULL;

	scanf("%s", string);

        head = string;
	ptr = string;
	while(*ptr != '\0')
	{
		ptr ++;
	}
	ptr --;
	int flag = 1;
        while( head <= ptr)
        {
                if(*head != *ptr)
                {

                        printf("Not Palindrome\n");
			flag = 0;
			break;
                }
                head ++;
                ptr --;
        }
	if(flag)
	{
        printf("Palindrome\n");}
	return 0;
}

