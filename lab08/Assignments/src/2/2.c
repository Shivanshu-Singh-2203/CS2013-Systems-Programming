#include <stdio.h>
#include <limits.h>
void factoral(unsigned int input, long fact)
{
	if(input == 0)	
	{
		printf("%ld", fact);
		return;
	}
	else {
		long nq = input*fact;
		if (nq < 0)
		{
		printf("TOO LARGE TO COMPUTE");
		
		return;
		}
		return factoral(input - 1, nq);}}




int main()
{
	unsigned long fact = 1;
        unsigned int input;

	scanf("%d", &input);
	// Do not modify anything above this line
	// TODO: Complete the code
	factoral(input, fact);
	//Do not add/modify anything below this line
	return 0;
}

