#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Fibonacci sequence
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
	ex) fibonacci(5) = 3 + 2 = fibonacci(4) + fibonacci(3)
	ex) fibonacci(6) = 8 = 5 + 3 = fibonacci(5) + fibonacci(4)
*/

int fibonacci(int number);

int main()
{
	for (int count = 1; count < 13; ++count)
		printf("%d\n", fibonacci(count));

	return 0;
}

int fibonacci(int number)
{

	if (number > 2) // stop condition
	{
		return fibonacci(number - 1) + fibonacci(number - 2); // double recursion, 
		/*디버그 해보면, 각각을 동시에 실행하지 않는 것을 확인할 수 있다.*/
	}
	else
	{
		return 1;
	}
}

/*
	Note: memory(in)efficiency, redundant computation
	단점은 stack에 변수가 많이 쌓이기 때문에 메모리를 많이 사용한다. 따라서 비효율적이다.
	중복 계산이 아주 많다.
*/

