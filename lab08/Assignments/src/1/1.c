#include <stdio.h>

struct complex { 
        double real;
        double imag;
};

typedef struct complex Complex ;

Complex add(Complex a, Complex b){
        Complex res;
        res.imag = a.imag + b.imag;
        res.real = a.real + b.real;
        return res;
}

Complex sub(Complex a, Complex b){
        Complex res;
        res.imag = a.imag - b.imag;
        res.real = a.real - b.real;
        return res;
}

Complex mul(Complex a, Complex b){
        Complex res;
        res.imag = a.imag*b.real + b.imag*a.real;
        res.real = a.real*b.real - a.imag*b.imag;
        return res;
}

float rationalizedenom(Complex a){
        double res = a.real*a.real + a.imag*a.imag;
        return res;
}

Complex div(Complex a, Complex b){
        Complex res;
        Complex temp;
        temp.imag = -b.imag;
        temp.real = b.real;
        Complex prod = mul(a, temp);
        res.real = prod.real/(rationalizedenom(b));
        res.imag = prod.imag/rationalizedenom(b);
        return res;
}

void print_complex(Complex c){
        printf("%.4lf+%.4lfj\n", c.real, c.imag);
}

int main()
{
	Complex x, y, result;

	scanf("%lf %lf %lf %lf", &x.real, &x.imag, &y.real, &y.imag);

	result = add(x,y);
	printf("Sum: ");
	print_complex(result);

	result = sub(x,y);
	printf("Difference: ");
	print_complex(result);

	result = mul(x,y);
	printf("Product: ");
	print_complex(result);

	result = div(x,y);
	printf("Division: ");
	print_complex(result);
	return 0;
}
