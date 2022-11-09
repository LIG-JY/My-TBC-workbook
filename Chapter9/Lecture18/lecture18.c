#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int a, int b)
{
	/*printf("%p %p\n", &a, &b);*/  // 주소를 출력해보면 다른 것을 확인할 수 있습니다. 함수의 지역변수이기 때문입니다.
	// call by value 즉 a와 b의 값 123, 456이 복사가 되어 들어갔습니다.
	int temp;
	temp = a;
	a = b;
	b = temp;
	
	return; // c언어는 문법상 return 값이 1개입니다.
}

void swap_ptr(int* a, int* b) // pointer을 매개변수로, call by pointer
{
	//printf("%p %p\n", a, b);  // 포인터변수이기 때문에 주소&를 때고 출력할 수 있습니다.  
	int temp;
	temp = *a;  // indirection 포인터 a가 가리키는 주소의 변수 값을 가져옵니다.
	*a = *b;  // redirection 한 결과 값끼리 교환
	*b = temp;

	return; // c언어는 문법상 return 값이 1개입니다.
}

int main()
{
	int a = 123;
	int b = 456;

	//printf("%p %p\n", &a, &b); // 함수의 매개변수와 주소가 다릅니다.

	swap(a, b);  // swap이 일어나지 않는다. a와 b의 값이 swap 함수에 들어갔지, a와 b가 들어간 것은 아닙니다.
	printf("%d %d\n", a, b);

	swap_ptr(&a, &b);  // 포인터 변수에는 주소를 넣어주자
	printf("%d %d\n", a, b);
	return 0;
}
 
