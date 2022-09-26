#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main()
{

	printf("Enter %d numbers : \n", SIZE);
	int my_arr[SIZE];
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &my_arr[i]);
		sum += my_arr[i];
	}



	//TODO: average

	printf("Sum = %d\n", sum);
	printf("Average = %d\n", sum/SIZE);

	return 0;
}
