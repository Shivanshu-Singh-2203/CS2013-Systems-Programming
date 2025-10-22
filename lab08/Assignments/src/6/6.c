#include <stdio.h>
#include <math.h>

int main()
{
	float y, rad, value;
	scanf("%f", &y);
	rad =y*M_PI/180;
	value = pow(sin(rad), 3) + pow(cos(rad),3);
	printf("%.4f", value);
	return 0;
}

