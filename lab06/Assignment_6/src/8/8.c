#include <stdio.h>

#define ROWS 3
#define COLS 3

int main()
{
	int mat1[ROWS][COLS];
	int mat2[ROWS][COLS];
	int mat3[ROWS][COLS];
	int tmp;

	for(int i = 0; i < ROWS; i ++)
	{
		for(int j = 0; j < COLS; j ++)
		{
			scanf("%d", &mat1[i][j]);
		}
	}
	
	for(int i = 0; i < ROWS; i ++)
	{
		for(int j = 0; j < COLS; j ++)
		{
			scanf("%d", &mat2[i][j]);
		}
	}

	for(int i = 0; i < ROWS; i ++)
	{
		for(int j = 0; j < COLS ; j ++)
		{
			tmp = 0;
			for(int k = 0; k < 3; k ++)
			{
				tmp = tmp+  mat1[j][k]*mat2[k][i];
			}
			mat3[i][j] = tmp;
		}
	}

	for(int i = 0; i < ROWS ; i ++)
	{
		for(int  j = 0; j < COLS; j ++)
		{
			printf("%d ", mat3[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

