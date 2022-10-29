#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int int_max(int i, int j)
{
	int m;
	m = i > j ? i : j; 
	// ternary operator(삼항연산자) (condition) ? true value : false value
	// i > j 가 True면 i, False면 j
	return m;
}

int main()
{
	int a;
	a = int_max(1, 2);
	{
		int b;
		b = int_max(4, 5);
		{
			int b = 123;
		}

		{
			int c = 456;
		}
	}
	return 0;
}

