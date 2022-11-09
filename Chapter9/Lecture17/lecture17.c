#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	char a;
	float b;
	double c;

	char* ptr_a = &a;
	float* ptr_b = &b;
	double* ptr_c = &c;

	printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c));  // 1바이트, 4바이트, 8바이트
	printf("%zd %zd %zd\n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));  // 메모리주소의 크기는 동일하다.
	printf("%zd %zd %zd\n", sizeof(&a), sizeof(&b), sizeof(&c));
	printf("%zd %zd %zd\n", sizeof(char*), sizeof(float*), sizeof(double*));
	/*32비트, 64비트에 따라 달라짐*/
	// 포인터 변수가 갖고 있는 메모리주소는 각 차지하는 공간에서 첫번째 바이트의 메모리주소
}


