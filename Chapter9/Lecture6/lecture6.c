#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void my_func(int);

int main()
{
	my_func(1);
	return 0;
}

void my_func(int n)
{
	printf("Level %d, address of variable n = %p\n", n, &n);

	if (n <=4 ) // 종료조건
	{
			my_func(n + 1); // 재귀호출
	}

	printf("Level %d, address of variable n = %p\n", n, &n); // stack에서 돌아오는 경로 확인
}
