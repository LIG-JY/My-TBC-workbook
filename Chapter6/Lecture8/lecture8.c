#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// Indefinite loop vs. Counting loop
	while (1)
	{
		// do something, 'indefinite' while안에서 무슨 일이 일어날지 모릅니다.
	}



	/*
		while문에서 counting loop 사용하는법?
		Counting Loop
		1. Counter initialization 변수 초기화
		2. Counter check 변수 조건문에서 확인
		3. Counter change 변수 변화(증감)
	*/
	int i;
	 // for (int i = 1; i <= 10; i++) 이렇게 선언하고 초기화를 동시에 해도 괜찮습니다.
	for (i = 1; i <= 10; i++)  // 초기화, 조건, 변수변화 3가지를 모두 한꺼번에!
	{
		print("%d", i);
	}

	// 디버거를 이용하면 가장 왼쪽의 i = 1 expression은 반복문 전체에서 1번 실행됩니다.


	return 0;
}
