#include <stdio.h>
#include <stdlib.h>
// TODO Include appopriate headers for dynamic memory allocation
struct RBG {
	int r;
	int b;
	int g;
};

typedef struct RBG Pixel;

int main(int argc, char** argv){
	if(argc != 3){
		printf("Invalid command line entries.\n");
		return 1;
	}
	
	FILE* file;
	file = fopen(argv[1], "r");
	if(file == NULL){
		printf("Unable to open ppm file.\n");
		return 1;
	}

	FILE * winto;
	winto = fopen(argv[2], "w");
	if(winto == NULL){
		printf("Unable to open out file.\n");
		return 1;
	}

	char method[32];
	fgets(method, 30, file);
//	printf("%s", method);
	fprintf(winto, "%s", method);
	int columns, rows;
	fscanf(file, "%d %d", &columns, &rows);
	fprintf(winto, "%d %d\n", columns ,rows);
	
	int max;
	fscanf(file, "%d", &max);
	fprintf(winto, "%d\n", max);

	for(int i = 0; i < rows; i ++){
		for(int j = 0; j < columns; j ++){
				Pixel temp;
				fscanf(file, "%d", &temp.r );
				fscanf(file, "%d", &temp.b);
				fscanf(file, "%d", &temp.g);
				fprintf(winto, "%d %d %d\n", temp.r, temp.b, temp.g);
		}
	}
	free(winto);
	free(file);
	return 0;
}


