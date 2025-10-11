/**
 * determinant.c
 *
 * For computating determinant of an nxn integer matrix
 *
 */
#include <stdio.h>
#define SIZE 100
#include <stdlib.h>
/**
 * Computes the sign of an entry in determinant computation
 * @param i The index corresponding to row
 * @param j The index corresponding to column
 * @param size Order of the matrix
 * @return The value of the sign
 */

int sign(const int i, const int j, const int size){

	int result ;
	if((i+j)%2 == 0)
	{
		result = 1;
	}
	else {
		result = -1;
	}
	return result;
}

void makeSubmatrix(int** matrix, int** sub, int size, int k) {
	for(int rows = 1; rows  < size; rows ++) {
		int flag = 0;
		for(int col = 0; col < size; col ++) {
			if(col == k) {
				flag = 1;
				continue;
			}
			sub[rows - 1][col - flag] = matrix[rows][col];
		}
	}
}


/**
 * Computes the determinant of a matrix
 * @param matrix The input matrix
 * @param size Order of the matrix
 * @return The value of the sign
 */

long determinant(int** matrix, int size){

// TODO: Complete the code. Use recursion to compute the determinant.
// Use dynamic memory allocation for submatrix creation
// Do not forget to free the memory once the use is over

	if(size == 1)
	{
		return matrix[0][0];
	}
	if (size == 2){
		return matrix[1][1]*matrix[0][0] - matrix[1][0]*matrix[0][1];
		}

	long detVal = 0; 
	for(int j = 0; j < size; j ++) 
		{

			int** submatrix = malloc(sizeof(int*)*(size-1));
			for(int k = 0; k < size - 1; k ++ ) {
				submatrix[k] = malloc(sizeof(int)*(size-1));
			}

			makeSubmatrix(matrix, submatrix, size, j);
			
			long det_sub = determinant(submatrix, size- 1)*(matrix[0][j]);
			detVal += sign(0, j, size)*det_sub;
			for(int l = 0; l < size - 1; l ++) {
				free(submatrix[l]);
			}
			free(submatrix);
		}
	
	return detVal;
}

// Main procedure
int main(){
	
	int size = 0;
	long det;

	scanf("%d", &size);
			int** matrix = malloc(sizeof(int*)*(size));
			for(int k = 0; k < size ; k ++ ) {
				matrix[k] = malloc(sizeof(int)*(size));
			}
	// Read the matrix
	
	for(int i = 0 ; i< size; i++) {
		for(int j = 0; j < size; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	det = determinant(matrix,size);
	printf("%ld", det);
	return 0;
}
