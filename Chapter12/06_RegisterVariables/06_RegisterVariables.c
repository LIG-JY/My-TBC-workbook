#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void temp(register int r)
{
	// do something with r
}

int main()
{
	register int r;
	r = 123;

	int* ptr = &r;  // error 오류 C2103 레지스터 변수에 '&'이(가) 있습니다.

	return 0;
}
