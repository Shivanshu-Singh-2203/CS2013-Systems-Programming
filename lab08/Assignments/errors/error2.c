/** 
 * This program is supposed to compute the factorial
 *
 * Figure out what is the issue and fix it using GDB 
 *
 **/


#include <stdio.h>
long factorial(int n);

int main(void)
{
    int n = 0;
    scanf("%d",&n);
    long val=factorial(n);
    printf("%ld\n",val);
    return 0;
}
      
long factorial(int n)
{
    long result= 1;
    while(n != 1)
    {
        result*=n;
	n --; 
    }
    return result;
}
