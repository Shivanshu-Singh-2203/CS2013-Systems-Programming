#include <stdio.h>

struct complex
{
	double real;
	double imag;
};

typedef struct complex mycomplex;

mycomplex add(mycomplex first, mycomplex second){
	mycomplex sum;
	sum.imag = first.imag + second.imag;
	sum.real = first.real + second.real;
	return sum;
}

void print_complex(mycomplex nums){
	printf("%.4lf+%.4lfj\n", nums.real, nums.imag);
}

mycomplex subtract(mycomplex first, mycomplex second){
	mycomplex temp;
	temp.imag = first.imag - second.imag;
	temp.real = first.real - second.real;
	return temp;
}

mycomplex multiply(mycomplex first, mycomplex second){
	mycomplex temp;
	temp.imag = first.real*second.imag + first.imag*second.real;
	temp.real = first.real * second.real - first.imag*second.imag;
	return temp;
}

mycomplex divide(mycomplex first, mycomplex second){
	mycomplex temp;
	double abs = second.real*second.real + second.imag*second.imag;
	mycomplex ct;
	ct.real = second.real;
	ct.imag = -second.imag;
	temp = multiply(ct, first);
	temp.real /= abs;
	temp.imag /= abs;
	return temp;
}

int main()
{
	mycomplex x, y, result;

	scanf("%lf %lf %lf %lf", &x.real, &x.imag, &y.real, &y.imag);

	result = add(x,y);
	printf("Sum: ");
	print_complex(result);

	result = subtract(x,y);
	printf("Difference: ");
	print_complex(result);

	result = multiply(x,y);
	printf("Product: ");
	print_complex(result);

	result = divide(x,y);
	printf("Division: ");
	print_complex(result);

	// END	
	//Do not add/modify anything below this line
	//Print the answer
	return 0;
}

