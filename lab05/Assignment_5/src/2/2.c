#include <stdio.h>

int main()
{
	float a=0, b=0;
	float area, perimeter;

	//Get two floating point values from the user
	scanf("%f %f", &a, &b);

	//Do not add/modify anything about this line
	//TODO: Complete the code
	if ((a > 0) && (b > 0))
	{	
		area = a * b;
		perimeter = 2*(a + b);
                printf("%.3f %.3f",area, perimeter);                                                  
	}
	else {
		printf("Invalid Input");
	}
	//Do not add/modify anything below this line
	return 0;
}

