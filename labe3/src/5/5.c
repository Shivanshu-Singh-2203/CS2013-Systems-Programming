// TODO: Include header files as necessary
// Answer question 5 here.
#include <stdio.h>
#include <math.h>

double getRoot(long number){
	double lasty = 1;
	double curr = number/lasty;
	double ans;
	while(1){
		double newy = (curr - lasty)/2 + lasty;
		double diff = newy - curr;
		if(fabs(diff) < 0.0001*lasty){
			ans = newy;
			break;
		}
		lasty = newy;
		curr = number/newy;
	}	
	return  ans;
}

int main()
{
	int inputs = 0;
	scanf("%d", &inputs);

	double arr[inputs];
	for(int i = 0 ; i < inputs; i ++){
		long val ;
		scanf("%ld", &val);
		double ans = getRoot(val);
		arr[i] = ans;
	}
	
	for(int i = 0 ; i < inputs; i ++){
		printf("%.11lf", arr[inputs-i-1]);
		printf("\n");
	}
	
	// Do not add/modify anything below this line
	return 0;
}


