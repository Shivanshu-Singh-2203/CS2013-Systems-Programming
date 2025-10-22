#include <stdio.h>

unsigned int sum(unsigned int nums){
	if(nums / 10 == 0 ){
		return nums;
	}
		unsigned int temp = nums%10;
		unsigned int temp2 = nums/10;
		return sum(temp + temp2);
}

int main(void){
	unsigned int nums ;
	scanf("%u", &nums);
	printf("%u", sum(nums));
	return 0;
}
