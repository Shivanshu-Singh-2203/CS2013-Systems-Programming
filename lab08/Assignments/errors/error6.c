#include <stdio.h>

/*
 * String manipulation can look powerfull in C when you see a
 * compilable program like this one. Executing the programm is much
 * less funny than compiling it, however...
 */

int main() {
  char * hello = "hello, world!";
  char * charstring = "hello, world!";


  printf("hello=%s, charstring=%s.\n", hello, charstring);
  return 0;
}

