#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b;

	a = 123;

	int *a_ptr; // * : asterisk 포인터 변수를 선언할 때 사용합니다.

	a_ptr = &a; // & : address-of operator

	printf("%d %d %p\n", a, *a_ptr, a_ptr);  // 특히 3번째 주소의 경우 실행할 때 마다 달라질 수 있습니다.

	*a_ptr = 456;  // * : re-direction or de-referencing, a의 값이 바뀝니다.

	printf("%d %d %p\n", a, *a_ptr, a_ptr);  

	b = a_ptr;  /* int 자료형에 주소 값을 넣으려고 하면 경고가 뜨고 문제가 발생합니다. 
				주소를 int로 casting 할 수 있긴한데 일단 경고를 줘요*/

	b = *a_ptr;

	printf("%d %p\n", b, &b);

	*a_ptr = 789;

	printf("%d %p\n", b, &b);

	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	a = 1234;

	printf("%d \n", b);

	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	return 0;
}

