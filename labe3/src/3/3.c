
// TODO: Add appropriate headers, if needed
#include <stdio.h>
#include <string.h>

long getNum(char* str){
	char* head = str;
	long current=0;
	int flag = 1;
	if(*head == '-'){
		head ++;
		flag = -1;
	}

	while(*head != '/'){
		int curr = *head - '0';
		current = current*10 + curr;
		head ++;
	}

	return flag*current;
}

long getDen(char* str){
	char* head = str;
	while(*head != '/'){
		head ++;

	}
	
	long current = 0;
	head ++;
	int flag = 1;
	if(*head == '-'){
		flag = -1;
	}
	
	while(*head != '\n'){
		current = current*10 + *head - '0';
		head ++;
	}
	
	
	return current*flag;
}



long gcd(long a, long b){

	
	if(b == 0){

		return a;
	}
	long temp = a % b;
	return gcd (b, temp);

}
// TODO: Answer question 3
int main()
{
	char str[1000];
	
	while(fgets(str, 1000, stdin) != NULL){
		long num = getNum(str);
		long den = getDen(str);
		if(den == 0){
			printf("Invalid\n");
		}
		else {
		long gc = gcd(num, den);
		long newDen, newNum;
		newDen = den/gc;
		newNum = num/gc;
//		printf("%ld/%ld", getNum(str), getDen(str));
		printf("%ld/%ld\n", newNum, newDen);

		}}
	
	return 0;
}

