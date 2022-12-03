#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Variable scopes (visibility)
	- block, function, function prototype, file.
*/

void f1(int hello, double world);  
// 프로토타입을 선언할 때 hello, world와 같은 지역변수의 scope는 프로토타입이 끝이다.
// 따라서 사실 안 써도 된다. ->  f1(int, double);  
// 하지만 읽기 좋은 코드를 위해서 써주는게 좋다.

/*  예외  */
//void vla_param(int n, int m, double ar[n][m])
//{
//  vla -> Variable length Array 즉 array의 길이를 변수로 받는 경우, 프로토타입에서 지역변수를 생략할 수 없다.
//}


double func_block(double d)
{
	double p = 0.0;

	for (int i = 0; i < 10; i++)
	{
		// 이 Block 에서 i는 계속 사용할 수 있다.
	}

	return p;
}

int main()
{
	func_block(1.0);
}

void f1(int hello, double world)
{
}


