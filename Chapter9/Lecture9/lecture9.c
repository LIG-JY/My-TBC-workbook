#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	10
	10 / 2 = 5, remainder = 0
	5 / 2 = 2, remainder = 1
	2 / 2 = 1, remainder = 0
	1 / 2 = 0, remainder = 1
*/

void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{

	print_binary(10);
	printf("\n");
	print_binary_loop(10);
	
	return 0;
}

//Note: printing order is reversed!
void print_binary_loop(unsigned long num)
{	
	while (1)
	{
		int quotient = num / 2; // 정수로 형변환 해서 소수점 이하를 버린다.
		int remainder = num % 2;

		printf("%d", remainder); // remainder is 0 or 1

		num = quotient;  // 출력 순서를 바꾸기 위해서는? 배열이 필요합니다.

		if (num == 0)
		{
			break;
		}
	}
	printf("\n");
}

void print_binary(unsigned long num)
{
	int quotient = num / 2;
	if (quotient > 0)
	{
		print_binary(quotient); // print만 하면 되기 때문에, return이 필요없는 것을 생각합시당.
	}
	printf("%d", num % 2); // stack 개념
	return;
}
