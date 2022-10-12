#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	unsigned num;
	int isPrime = 1;// flag, try bool type (상태표시용 flag, C언어에서 보통 int로 사용합니다.)
	unsigned div;

	scanf("%u", &num);
	int i = 2;
	while (i++ < (num / 2))
	{
		if (num % i == 0)
		{
			isPrime = 0;
			break;
		}
	}
	
	// for (div = 2; (div * div) <= num; ++div)
	// {
	// 	if (num % div == 0)
	// 	{
	// 		isPrime = 0;

	// 		if (num == div * div)
	// 			printf("%u is divisible by %u.\n", num, div);
	// 		else
	// 			printf("%u is divisible by %u and %u.\n", num, div, num / div);
	// 	}
	// } // 수업 풀이, 약수 모두 출력

	if (isPrime)
	{
		printf("%u is a prime number.\n", num);
	}
	else
		printf("%u is not a prime number.\n", num);

	return 0;
}
