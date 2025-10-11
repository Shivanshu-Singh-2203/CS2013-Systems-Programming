#include <stdio.h>
//TODO: Include appropriate header file for dynamic memory allocation
#include <stdlib.h>

int main()
{
	int n;
        int result = 1;

	//Get the order of the tensor from the user
	scanf("%d", &n);

	//Do not add/modify anything about this line
	//TODO: Complete the code
	int*** tensor = malloc(sizeof(int**)*n);
	for(int i = 0 ; i < n ; i ++){
		tensor[i] = malloc(sizeof(int*)*n);
		for(int j = 0; j < n; j ++){
			tensor[i][j] = malloc(sizeof(int)*n);
		}
	}

	for(int k = 0; k  < n; k ++){
		for(int i = 0 ; i < n; i ++){
			for(int l = 0; l < n ; l ++){
				scanf("%d", &tensor[k][i][l]);
			}
		}
	}
	for(int k = 0; k  < n; k ++){
		for(int i = 0 ; i < n; i ++){
			for(int l = 0; l < n ; l ++){
				result = ((result%101010)*(tensor[k][i][l]%101010))%101010;
			}
		}
	}

        printf("%d\n", result);

	//TODO: DO NOT FORGET TO FREE ANY MEMORY ALLOCATED USING malloc() using
	// free() 
	//
	//Do not add/modify anything below this line
	return 0;
}

