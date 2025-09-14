/* Following code has an error. Find the error and fix it. */

#include <stdio.h>
int main()
{
	int a = 23, b = 19, ans;

	//checks if ‘a’ is divisible by ‘b’
	if (a%b != 0) {
		ans = 1;
	}else{
		ans = 0;
	}
	if(!ans)	{
		printf (" a is divisible by b");
	}else{
		printf ("a is not divisible by b");
	}
	return 0;
}
