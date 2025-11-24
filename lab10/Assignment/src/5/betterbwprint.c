#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 5

struct RBG {
    int r;
    int g;
    int b;
};

typedef struct RBG Pixel;

int allowed[SIZE] = {0, 64, 128, 192, 255};

int clamp(int value) {
    if (value < 0) return 0;
    if (value > 255) return 255;
    return value;
}

Pixel find_closest_palette_color(Pixel p, int *array) {
    Pixel best = {0,0,0};
    long bestDist = LONG_MAX;

    for (int r = 0; r < SIZE; r++) {
        for (int g = 0; g < SIZE; g++) {
            for (int b = 0; b < SIZE; b++) {

                long dr = p.r - array[r];
                long dg = p.g - array[g];
                long db = p.b - array[b];

                long dist = dr*dr + dg*dg + db*db;

                if (dist < bestDist) {
                    bestDist = dist;
                    best.r = array[r];
                    best.g = array[g];
                    best.b = array[b];
                }
            }
        }
    }
    return best;
}

Pixel quant(Pixel orig, Pixel pal) {
    Pixel e;
    e.r = orig.r - pal.r;
    e.g = orig.g - pal.g;
    e.b = orig.b - pal.b;
    return e;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Invalid command line entries.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Unable to open ppm file.\n");
        return 1;
    }

    FILE *winto = fopen(argv[2], "w");
    if (winto == NULL) {
        printf("Unable to open out file.\n");
        fclose(file);
        return 1;
    }

    char magic[10];
    fgets(magic, sizeof(magic), file);
    fprintf(winto, "%s", magic);

    int cols, rows;
    fscanf(file, "%d %d", &cols, &rows);
    fprintf(winto, "%d %d\n", cols, rows);

    int max;
    fscanf(file, "%d", &max);
    fprintf(winto, "%d\n", max);

    Pixel **matrix = malloc(rows * sizeof(Pixel *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(Pixel));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Pixel t;
            fscanf(file, "%d %d %d", &t.r, &t.g, &t.b);
            matrix[i][j] = t;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            Pixel old = matrix[i][j];
            Pixel newc = find_closest_palette_color(old, allowed);
            Pixel err = quant(old, newc);

            matrix[i][j] = newc;

            if (j + 1 < cols) {
                matrix[i][j+1].r = clamp(matrix[i][j+1].r + err.r * 7 / 16);
                matrix[i][j+1].g = clamp(matrix[i][j+1].g + err.g * 7 / 16);
                matrix[i][j+1].b = clamp(matrix[i][j+1].b + err.b * 7 / 16);
            }

            if (i + 1 < rows && j > 0) {
                matrix[i+1][j-1].r = clamp(matrix[i+1][j-1].r + err.r * 3 / 16);
                matrix[i+1][j-1].g = clamp(matrix[i+1][j-1].g + err.g * 3 / 16);
                matrix[i+1][j-1].b = clamp(matrix[i+1][j-1].b + err.b * 3 / 16);
            }

            if (i + 1 < rows) {
                matrix[i+1][j].r = clamp(matrix[i+1][j].r + err.r * 5 / 16);
                matrix[i+1][j].g = clamp(matrix[i+1][j].g + err.g * 5 / 16);
                matrix[i+1][j].b = clamp(matrix[i+1][j].b + err.b * 5 / 16);
            }

            if (i + 1 < rows && j + 1 < cols) {
                matrix[i+1][j+1].r = clamp(matrix[i+1][j+1].r + err.r * 1 / 16);
                matrix[i+1][j+1].g = clamp(matrix[i+1][j+1].g + err.g * 1 / 16);
                matrix[i+1][j+1].b = clamp(matrix[i+1][j+1].b + err.b * 1 / 16);
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Pixel p = matrix[i][j];
            fprintf(winto, "%d %d %d\n", p.r, p.g, p.b);
        }
    }

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    fclose(file);
    fclose(winto);

    return 0;
}

