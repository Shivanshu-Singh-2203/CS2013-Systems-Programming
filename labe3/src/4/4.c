
// TODO: Include header files as necessary
#include <stdio.h>
#include <stdlib.h>
#define LEN 100

void areanagrams(char* first, char* second){
	int count[256] = {0};
	for(int i = 0 ; first[i] != '\0'; i ++){
		count[(int)first[i]] ++;
	}
	for(int i = 0 ; second[i] != '\0'; i ++){
		count[(int)second[i]] --;
	}

	for(int i = 0 ; first[i] != '\0'; i ++){
		if(count[(int)first[i]] != 0){
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
}


// Answer question 4 here.
int main()
{
	int count = 0 ; 

	scanf("%d", &count);
	
	for(int i = 0 ; i < count; i ++){
		char first[LEN], second[LEN];
		scanf("%s %s", first, second);
//		printf("%s %s\n", first, second);
		areanagrams(first, second);
	}
	
	
	
	
	
	//Do not add/modify anything below this line
   return 0;
}


