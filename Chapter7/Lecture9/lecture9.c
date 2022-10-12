#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int temp;
	temp = true ? 1024 : 7; // ternary
	printf("%d\n", temp);

	temp = false ? 1024 : 7;
	printf("%d\n", temp);

	int number;
	scanf("%d", &number);

	bool is_even; // flag

	// if (number % 2 == 0)
	// 	is_even = true;
	// else
	// 	is_even = false;

	const is_even = (number % 2 == 0) ? true : false;  // 조건연산자의 결과 값이 정해지고 바뀌지 않게 const까지 해주면 완벽
	
	if (is_even)
		printf("Even");
	else
		printf("Odd");

	return 0;
}
