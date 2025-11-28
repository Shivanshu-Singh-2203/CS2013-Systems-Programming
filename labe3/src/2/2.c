#include <stdio.h>
#include <stdlib.h>

// TODO: Add appropriate headers

// THIS CODE DOES NOT COMPILE PROPERLY.
// ADD APPROPRIATE DECLARATIONS AND FIX 
// THE COMPILE ISSUES.


int**** getTesarect(int a ){
	int**** res = malloc(sizeof(int***)*a);
	for(int j = 0; j < a; j ++){
		res[j] = malloc(sizeof(int**)*a);
		for(int i = 0; i < a; i ++ ){
			res[j][i] = malloc(sizeof(int*)*a);
			for(int l = 0; l <a ; l ++){
				res[j][i][l] = malloc(sizeof(int)*a);
			}
		}
	}
	return res;
}

void fillTeseract(int**** tes, int** mat1, int** mat2, int a, int b){
	for(int i = 0; i < a; i ++){
		for(int j = 0; j < b; j ++){
			for(int k = 0; k < a; k ++){
				for(int l = 0 ; l < b; l ++){
					tes[i][j][k][l] = mat1[i][k]* mat2[j][l];
				}
			}
		}
	}

}

int** getMatrix(int a){
	int** mat = malloc(sizeof(int*)*a);
	for(int i = 0; i < a; i ++){
		mat[i] = malloc(sizeof(int)*a);
	}

	for(int i = 0; i < a; i ++){
		for(int j = 0; j < a; j ++){
			scanf("%d", &mat[i][j]);
		}
	}
	return mat;
}

void freeMatrix(int** mat, int a){
	for(int i = 0 ; i < a; i ++){
		free(mat[i]);
	}
	free(mat);
}

void freeTes(int**** tes, int a){
	for(int i = 0; i < a; i ++){
		for(int j = 0; j <a ; j ++){
			for(int k = 0; k < a; k ++){
				free(tes[i][j][k]);
			}
			free(tes[i][j]);
		}
		free(tes[i]);
	}
	free(tes);
}

int main()
{

        int a, b;
        // Add appropriate code

		scanf("%d", &a);
		int** first = getMatrix(a);

		scanf("%d", &b);
		int** second = getMatrix(b);

		int max = a > b ? a : b ;
		int**** Z = getTesarect(max);
		 fillTeseract(Z, first, second , a, b);

        //////////////////////////
        // DO NOT MODIFY CODE BELOW
        /////////////////////////
        
        // Printing the final result.
        for(int i = 0; i < a; i++)
          for(int p = 0; p < b; p++)
            for(int j = 0; j < a; j++)
              for(int q = 0; q < b; q++)
                printf("%d ", Z[i][p][j][q]);

        printf("\n");

        //////////////////////////
        // DO NOT MODIFY CODE ABOVE
        /////////////////////////
	
		freeMatrix(first, a);
		freeMatrix(second, b);
		freeTes(Z, max);

        // Do not modify any line below
	return 0;
}
