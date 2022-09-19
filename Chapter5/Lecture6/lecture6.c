#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int seconds = 0, minutes = 0, hours = 0;
	printf("Input seconds : "); 
	scanf("%d", &seconds); // 처음 loop에 사용할 값

	while (seconds >= 0)
	{
		

		minutes = seconds / 60;
		seconds = seconds % 60;

		hours = minutes / 60;
		minutes = minutes % 60;

		printf("%d hours. %d minutes, %d seconds", hours, minutes, seconds);

		printf("Input seconds : "); 
		scanf("%d", &seconds); // 다음loop에 사용할 값
	}
	
	printf("good bye\n");

	int div, mod;

	div = 11 / 5;
	mod = 11 % 5;
	printf("div = %d, mod =%d\n", div, mod);

	div = 11 / -5;
	mod = 11 % -5;
	printf("div = %d, mod =%d\n", div, mod);

	div = -11 / -5;
	mod = -11 % -5;
	printf("div = %d, mod =%d\n", div, mod); // first operand is negative

	div = -11 / 5;
	mod = -11 % 5;
	printf("div = %d, mod =%d\n", div, mod); // first operand is negative


	return 0;
}
