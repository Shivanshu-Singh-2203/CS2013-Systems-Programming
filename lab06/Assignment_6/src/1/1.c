#include <stdio.h>

#define SIZE 10

int main()
{
	unsigned int input;

	/* The hex_str should finally look like "0xPQRS"
	 * where P,Q,R,S are one of {0,..,9,A,..,F}
	 */
	char hex_str [SIZE]; 

	scanf("%d", &input);


	unsigned int shift = 15;
	unsigned int hex3 = input & shift; 
	int hex2, hex4, hex5;
	hex_str[0] = '0';
	hex_str[1] = 'x';
	hex_str[6] = '\0';
	

	hex2 = (input & ( shift << 4)) >> 4;
	hex4 = (input & (shift << 8 )) >> 8;
	hex5 = ( input & (shift << 12 )) >> 12 ;
	
	hex_str[4] = ((hex2 >= 10) ? ('A' + hex2 - 10) : ('0' + hex2));
	hex_str[5] = ((hex3 >= 10) ? ('A' + hex3 - 10) : ('0' + hex3));
	hex_str[3] = ((hex4 >= 10) ? ('A' + hex4 - 10) : ('0' + hex4));
	hex_str[2] = (( hex5 >= 10) ? ('A' + hex5 - 10) : ('0' + hex5 ));

	printf("%s\n", hex_str);
	return 0;
}

