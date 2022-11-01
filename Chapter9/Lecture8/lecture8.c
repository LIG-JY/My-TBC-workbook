#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	loop vs recursion
	factorial : 3! = 3 * 2 * 1, 0! = 1
	5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!
*/

long loop_factorial(int n);
long recursive_factorial(int n);

int main()
{
	printf("%ld\n", loop_factorial(5));
	printf("%ld\n", recursive_factorial(5));
	return 0;
}

long loop_factorial(int n)
{
	long ans;
	ans = 1;
	while (n > 0)
	{
		ans *= n;
		n -= 1;
	}
	return ans;
}

long recursive_factorial(int n)
{
	if (n > 1)
	{
		return n * recursive_factorial(n - 1); // tail(end) recursion
	}
	else
		return 1;
}
