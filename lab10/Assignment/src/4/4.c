//TODO: Include appropriate header file as required
#include "bigint.h"

int main()
{
	Bigint * a = malloc(sizeof(Bigint));
	initialize(a);
	read(a);

	Bigint * b = malloc(sizeof(Bigint));
	initialize(b);
	read(b);

	// TODO: Complete the main function which adds a and b and prints the
	Bigint* sum = add(a, b);
	print(sum);	
	return 0;
}

