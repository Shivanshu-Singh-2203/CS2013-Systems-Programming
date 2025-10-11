#include <stdio.h>

int main(int argc, char* argv[]){
	FILE *fp;
	fp = fopen(argv[1], "r");

	if(fp == NULL){
		printf("Failed\n");
		return 1;
	}

	char curr = fgetc(fp);
	while (curr != EOF){
		printf("%c", curr);
		curr = fgetc(fp);
	}
	fclose(fp);
	return 0;
}
