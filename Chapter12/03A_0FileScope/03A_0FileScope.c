#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Variable scopes (visibility) -> visibility는 그 영역 안에서만 볼 수 있다. 이런 의미입니다.  
	EX) Scope가 될 수 있는 것들: block, function, function prototype, file.
	특히 file scope의 경우 이 file 전역(global)에서 사용할 수 있다.
*/
int g_i = 123;  // initialized global varible
int g_not_initialized;  // uninitialized global varible


void func1()
{
	g_i++;  // 전역변수는 이 파일 어떤 Scope에서든 사용할 수 있다.
}

void func2()
{

	g_i += 2;  // 전역변수는 이 파일 어떤 Scope에서든 사용할 수 있다.
	//local = 456;	// Error
}

int main()
{
	int local = 1234;

	func1();
	func2();

	printf("%d\n", g_i);  // 전역변수 사용
	printf("%d\n", g_not_initialized);  // 초기화 되지 않은 전역변수 사용
	// 문제가 생길까 안 생길까? -> BSS segment 프로그램이 시작될 때 0으로 초기화.
	printf("%d\n", local);  // 전역변수 사용


	return 0;
}
