#include <stdio.h>
#include <stdlib.h>

int  main(int argc, char *argv[])
{
        if(argc != 2){
                printf("Not enough number of arguments\n");
                return EXIT_FAILURE;
        }

        FILE* inputfile;

        inputfile = fopen("shivam.txt","r");
        
        if(inputfile == NULL){
                printf("Input file opening failed.\n");
                return EXIT_FAILURE;
        }
        
        char c = fgetc(inputfile);
        while (c != EOF){
                printf("%c", c);
                c = fgetc(inputfile);
        }
        return EXIT_SUCCESS;
}
