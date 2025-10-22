#include <stdio.h>
#include <limits.h>

void factorial(unsigned int input, long fact){
	if(input == 0){
		printf("%ld\n", fact);
		return ;
	}
	else {
		long n= fact*input;
		if(n < 0 ){
			printf("TOO LARGE TO COMPUTE\n");
			return;
		}
		return factorial(input - 1, n); 
	}
}

int main()
{
	unsigned long fact = 1;
        unsigned int input;

	scanf("%d", &input);
	// Do not modify anything above this line
	// TODO: Complete the code
	factorial(input, fact);
	//Do not add/modify anything below this line
	return 0;
}
