#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 5
// TODO Include appopriate headers for dynamic memory allocation
struct RBG {
	int r;
	int b;
	int g;
};

int allowed[SIZE] = {0, 64, 128, 192, 256};

typedef struct RBG Pixel;

int clamp(int nums){
	if(nums > 255 || nums < 0){
		return 0;
	}
	return nums;
}
Pixel find_closest_palette_color(Pixel first, int* array){
	Pixel temp;
	long mindist = LONG_MAX ;
	for(int i = 0; i < SIZE; i ++){
		for(int j = 0; j < SIZE; j ++ ){
			for(int k = 0; k < SIZE; k ++){
				double distance = (first.r - array[i])*(first.r - array[i])  + (first.b - array[j])*(first.b - array[j]) + (first.g - array[k])*(first.g - array[k]);

				if(distance < mindist){
					temp.r = array[i];
					temp.b = array[j];
					temp.g = array[k];
					mindist = distance;
				}
			}
		}
	}

	return temp;
}

Pixel quant(Pixel first, Pixel second){
	Pixel temp;
	temp.r = first.r - second.r;
	temp.g = first.g - second.g;
	temp.b = first.b - second.b; 
	return temp;
}

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
	fprintf(winto, "%s", method);
	int columns, rows;
	fscanf(file, "%d %d", &columns, &rows);
	fprintf(winto, "%d %d\n", columns ,rows);
	
	int max;
	fscanf(file, "%d", &max);
	fprintf(winto, "%d\n", max);
	
	Pixel** matrix = malloc(sizeof(Pixel*)*columns);
	for(int i = 0; i < columns; i ++){
		matrix[i] = malloc(sizeof(Pixel)* rows);
	}
	for(int i = 0; i < rows; i ++){
		for(int j = 0; j < columns; j ++){
				Pixel temp;
				Pixel new ;
				fscanf(file, "%d", &temp.r );
				fscanf(file, "%d", &temp.b);
				fscanf(file, "%d", &temp.g);
				new = find_closest_palette_color(temp, allowed);
				matrix[j][i] = new;
				Pixel err = quant(temp, new);
				if(j + 1 < columns){
					matrix[j + 1][i].r = clamp(matrix[j + 1][i].r + err.r*7/16);
					matrix[j + 1][i].g = clamp(matrix[j + 1][i].g + err.g*7/16);
					matrix[j + 1][i].b = clamp(matrix[j + 1][i].b + err.b*7/16);
				}

				if (j > 0){
					if(j - 1 < columns && i + 1 < rows){
						matrix[j - 1][i + 1].r = clamp(matrix[j - 1][i + 1].r + err.r*3/16);
						matrix[j - 1][i + 1].g = clamp(matrix[j - 1][i + 1].g + err.g*3/16);
						matrix[j - 1][i + 1].b = clamp(matrix[j - 1][i + 1].b + err.b*3/16);
					}
				}

				if(i + 1 < rows){
					matrix[j][i + 1].r = clamp(matrix[j][i + 1].r + err.r*5/16);
					matrix[j][i + 1].g = clamp(matrix[j][i + 1].g + err.g*5/16);
					matrix[j][i + 1].b = clamp(matrix[j][i + 1].b + err.b*5/16);					
				}

				if (j + 1 < columns && i + 1 < rows){
					matrix[j + 1][i + 1].r = clamp(matrix[j + 1][i + 1].r + err.r*1/16);
					matrix[j + 1][i + 1].g = clamp(matrix[j + 1][i + 1].g + err.g*1/16);
					matrix[j + 1][i + 1].b = clamp(matrix[j + 1][i + 1].b + err.b*1/16);
				}
				fprintf(winto, "%d %d %d\n", new.r, new.b, new.g);
		}
	}
	free(winto);
	free(file);
	return 0;
}


