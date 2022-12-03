#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Storage duration: 메모리의 지속기간을 의미한다.
	- static storage duration (프로그램이 시작될 때 부터 끝날 때 까지 계속)
	(Note: 'static' keyword indicates the linkage type, not the storage duration)
	- automatic storage duration (보통 지역변수를 의미한다.) (메모리 레이아웃에서 STACK)
	- allocated storage duration (동적할당)
	- thread storage duration (멀티 스레딩)
*/

void count()
{
	int ct = 0;  // Block이 끝나면 사라지는 ct
	printf("count = %d\n", ct);
	ct++;
}

void static_count()
{
	static int ct = 0;  // static 선언을 하면, 프로그램이 시작될 때 메모리에 들어오고 끝날 때까지 계속 유지가 된다.
	printf("count = %d\n", ct);
	ct++;
}

int main()
{
	count();
	count();
	static_count();
	static_count();

	return 0;
}
