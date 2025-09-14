#include <stdio.h>

#include <stdio.h>

int main() {
    int a, octal = 0, place = 1;

    scanf("%d", &a);

    while (a > 0) {
        octal += (a % 8) * place;
        a /= 8;
        place *= 10;
    }

    printf("%d\n", octal);
    return 0;
}

