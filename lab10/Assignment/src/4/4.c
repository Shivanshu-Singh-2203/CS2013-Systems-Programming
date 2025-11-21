#include "bigint.h"

int main()
{
	Bigint * a = malloc(sizeof(Bigint));
	read(a);

	Bigint * b = malloc(sizeof(Bigint));
	read(b);

	Bigint* sum = add(a, b);
	print(sum);	

        freeBigint(a);
        freeBigint(b);
        freeBigint(sum);
        return 0;
}

