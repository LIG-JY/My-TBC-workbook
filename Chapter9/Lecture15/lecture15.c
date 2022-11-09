#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 123;
	printf("%d\n", a);
	printf("%p\n", &a);

	 
	/*포인터 변수 선언, 포인터 변수도 메모리 공간을 가지고 있습니다.하지만 이렇게 하면 안 되죠
	일단 포인터 변수가 가리키는 주소가 없죠, redirection 불가능*/
	/*int* ptr = 1234;
	printf("%d\n", ptr);
	printf("%p\n", *ptr);*/

	int* safer_ptr = NULL; // 0이라고 해도 됩니다. 조건부로 포인터가 사용될 수 있기 때문에 설정해놓음

	if (a % 2 == 0)
	{
		safer_ptr = &a; // a가 홀수라도 NULL값을 가져서 확인할 수 있다.
	}
	
	if (safer_ptr != NULL)
	{
		printf("%p\n", safer_ptr);
		printf("%d\n", *safer_ptr); // indirection
	}
	return 0;
}
