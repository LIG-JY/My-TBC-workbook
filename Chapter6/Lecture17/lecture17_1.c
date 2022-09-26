#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main()
{
	/* Motivation */
	//int i1 = 0;
	//int i2 = 1;
	//int i3 = 2;
	//// ...

	//printf("%d\n", i1);
	//printf("%d\n", i2);
	//printf("%d\n", i3);
	//// ... 

	int my_arr[SIZE];
	for (int i = 0; i < SIZE; ++i)
		{
			my_arr[i] = i;
			// dummy 1 + 2; 디버깅할 때 할당을 확인하기 쉽게 도와줍니다.
		}

	for (int i = 0; i < SIZE; ++i)
		{
			printf("%d ", my_arr[i]);
		}

	//TODO: try debugger

	return 0;
}
