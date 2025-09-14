#include <stdio.h>

int main()
{
	int value, current;

	//Read an integer from the user
	scanf("%d", &value);

	//Do not add/modify anything about this line
	//TODO: Complete the cod
	int arr[value + 1];
	
	for(int i = 0; i < value; i ++)
	{
		arr[i] = 0;
	}

	for(int  i = 0; i <= value; i++)
	{
		arr[i] = i*(i+1)/2;
		if (arr[i] > value) break;
		else printf("%d ", arr[i]);

	}
	printf("\n");

	current =  2;
	while(current+arr[0] <= value)
	{
		for(int i = 0; i < value; i++)
		{
			arr[i] = i + current + arr[i];
		
		if (arr[i] > value ) break;
		else printf("%d", arr[i]);
		}

		printf("\n");
		current ++;
	}
	
	return 0;
}

