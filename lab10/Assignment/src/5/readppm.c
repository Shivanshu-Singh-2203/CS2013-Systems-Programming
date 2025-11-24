#include <stdio.h>
#include <string.h>

struct pixel {
        int r;
        int g;
        int b;
};

typedef struct pixel Pixel;

int verifyPixel(Pixel a){
        if (a.r > 255 || a.b > 255 || a.g > 255){
                return 1;
        }
        else if (a.r < 0 || a.b <0 || a.g < 0){
                return 1;
        }
        return 0;
}



int main(int argc, char *argv[])
{
        if(argc != 2){
                printf("Not enough arguments given.\n");
                return 1;
        }

        FILE* file;
        file = fopen(argv[1], "r");
        if(file == NULL){
                printf("Unable to open the file.\n");
                return 1;
        }

        char format[3];
        fscanf(file, "%s", format);
        if(strcmp(format, "P3") !=0){
                printf("The file format is not valid.\n");
                return 1;
        }       

        int rows, cols;
        fscanf(file, "%d %d", &rows, &cols);

        int colors;
        fscanf(file, "%d", &colors);

        if(colors != 255)
        {
                printf("Invalid color count provided.\n");
                return 1;
        }

        FILE* out;
        out = fopen("out.ppm", "w");

        fprintf(out, "%s\n", format);
        fprintf(out, "%d %d\n", rows, cols);
        fprintf(out, "%d\n", colors);

        for (int i = 0; i < rows; i ++) {
                for(int j = 0; j < cols; j ++){
                        Pixel temp;
                        if (fscanf(file, "%d %d %d", &temp.r, &temp.g, &temp.b) != 3)
                        {
                                return 1;
                        };
                        if(verifyPixel(temp)){
                                printf("Invalid pixel data\n");
                                return 1;
                        }
                        fprintf(out, "%d %d %d\n", temp.r , temp.g, temp.b);
                }
        } 
        return 0;
}
