#include <stdio.h>
#include <stdlib.h>

int main(){
        int size;
        scanf("%d", &size);

        int*** tensor = malloc(sizeof(int**)*size);

        for(int i = 0; i < size; i ++){
                tensor[i] = malloc(sizeof(int*)*size);
                for(int j = 0; j < size; j ++){
                        tensor[i][j] = malloc(sizeof(int*)*size);
                }
        }
        
        int  result = 1;
        for(int i = 0; i < size; i ++){
                for(int j = 0; j < size; j ++){
                        for(int  k = 0; k < size; k ++){
                                scanf("%d", &tensor[i][j][k]);
                        }
                }
        }

        for(int i = 0; i < size; i ++){
                for(int j = 0; j < size; j ++){
                        for(int  k = 0; k < size; k ++){
                                result = ((result % 101010)*(tensor[i][j][k] % 101010)) % 101010;
                        }
                }
        }


        for(int i = 0; i < size; i ++){
                for(int j = 0; j < size; j ++){
                        free(tensor[i][j]);
                        tensor[i][j] = NULL;
                        }
                free(tensor[i]);
                tensor[i] = NULL;
        } 
        printf("%d", result);
        return 0;
}
