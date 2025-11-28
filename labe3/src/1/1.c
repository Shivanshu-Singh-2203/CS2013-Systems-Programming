//TODO: Answer question 1 here.
//TODO: Complete the code

#include <stdio.h>

int countOcc(char* str, char* charac, int len){
	int count = 0;
	for(int i = 0; i < len ; i ++){
		if(str[i] == charac[0] && str[i+1] == charac[1]){
			count ++;
		}
	}
	return count;

}

int main(){
	char charac[3];
	scanf("%s", charac);
	int len;
	scanf("%d", &len);
	char str[1000000]  ;
	scanf("%s", str);
	int val = countOcc(str, charac , len);
	printf("%d\n", val);
	return 0;
}
