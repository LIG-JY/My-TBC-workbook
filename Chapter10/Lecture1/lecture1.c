

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[4] = { 2, 5, 6, 10 };

	if (arr == &arr[0])
	{
		printf("True\n");
	}

	printf("%p %p", arr, &arr[0]);
}
 
