#include <stdio.h>

#define TRUE  1
#define FALSE 0

int function_returning_false() {return FALSE;}

int main() {
        int val = function_returning_false();
        if (val) {
    printf("function returned true\n");
  }
        else {
    printf("function returned false\n");
}
return 0;


}

