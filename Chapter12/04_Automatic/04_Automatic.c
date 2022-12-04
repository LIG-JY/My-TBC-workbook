#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Automatic storage class
	- Automatic storage duration, block scope, no linkage
	- Any variable declared in a block or function header
*/

void func(int k);

int main()	//Note: main() is a function.
{
	auto int a;  // 문법적으로 가장 사용빈도가 적은 Keyword
	a = 512;  // 반드시 초기화

	int ii = 1024;

	for (int ii = 0; ii < 5; ii++)
		printf("%lld\n", (long long)&ii);

	// ii is not visible here
	printf("%lld\n", (long long)&ii);

	int k = 0;
	func(k);


	return 0;
}

void func(int k)
{
	// do something with i and k
	k++;
}
// 함수를 호출하면 Stack Frame 자체가 바뀌어버린다. 그리고 Frame 안에서 기존의 규칙이 적용된다.
