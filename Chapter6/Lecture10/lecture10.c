#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
		+=, -=, *=, /=, %=
	*/

	//  assignment는 가장 나중에 일어나는게 합리적이다. 그래서 굉장히 연산자 우선순위가 낮습니다.

	int i = 1024;

	i = i * (1 + 2);
	i *= 1 + 2;  // 괄호가 없어도 대입연산자의 우선순위가 낮다. *= 도 대입연산자에 포함됩니다. assignment!!
	i *= (1 + 2);

	return 0;
}
