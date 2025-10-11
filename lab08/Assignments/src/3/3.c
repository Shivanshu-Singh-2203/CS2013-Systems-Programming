#include <stdio.h>
#define ROWS 2
#define COLS 2




int main()
{
	int matrix[ROWS][COLS];

	//Get an integer from the user
	scanf("%d %d %d %d", &matrix[0][0], &matrix[0][1], &matrix[1][0], &matrix[1][1]);

	//Do not add/modify anything above this line
	//TODO: Complete the code
	float determinant = matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];


	if(determinant == 0)
	{
		printf("NOT INVERTIBLE\n");
	}
	else {

	float inverse[ROWS][COLS];

	inverse[1][1] = (float) matrix[0][0]/determinant;
	inverse[0][0] = (float) matrix[1][1]/determinant;
	inverse[0][1] = (float) -matrix[0][1]/determinant;
	inverse[1][0] = (float) -matrix[1][0]/determinant;

	printf("%.4f %.4f\n",inverse[0][0], inverse[0][1]);
	printf("%.4f %.4f\n",inverse[1][0], inverse[1][1]);
	
	}	
	//Do not add/modify anything below this line
	return 0;
}

