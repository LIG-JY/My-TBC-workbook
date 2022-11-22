#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
	Pointer operations
	- Assignment
	- Value finding (deferencing)
	- Taking a pointer address
	- Adding an integer to a pointer
	- Incrementing a pointer
	- Subtracting an integer from a pointer
	- Decrementing a pointer
	- Differencing
	- Comparisons
	*/

	int arr[5] = { 100, 200, 300, 400, 500 };
	int* ptr1, * ptr2, * ptr3;

	// Assignment
	ptr1 = arr;  
	/*포인터 변수 초기화, 배열의 이름의 경우 일반적인 변수와 다르게 주소의 기능을 해서 포인터 변수에 할당가능*/

	// dereferencing
	printf("%p %d %p\n", ptr1, *ptr1, &ptr1);  
	/* 값이 나타내는 메모리 주소로 가서 값을 가져옵니다.
	포인터 변수도 변수에 속한다. 즉 메모리 주소를 가지고 있다. 포인터 변수의 주소를 가져오는 것이 3번째 출력*/

	// Address of operator & 
	ptr2 = &arr[2];
	printf("%p %d %p\n", ptr2, *ptr2, &ptr2);
	/*배열의 인덱스 3번째의 값의 주소를 포인터 변수에 assignment*/

	// Adding an integer to a pointer
	ptr3 = ptr1 + 4;
	printf("%p %d %p\n", ptr3, *ptr3, &ptr3);
	/*ptr1과 ptr3 모두 int에 대한 주소를 가리키고 있다. 따라서 4바이트가 4개 저장되는 공간만큼 주소를 더한다.
	따라서 인덱스로 치면 4칸 이동하는 것이고 배열의 5번째 값을 가리키겠죠?*/

	// Differencing
	printf("%td\n", ptr3 - ptr1);  
	/* format specifier t -> 포인터의 차이를 출력할 때 사용한다.
	결과값 == 4, 37줄에서 더한 값과 동일하다. 즉 포인터의 차이는 배열의 인덱스가 단위라고 생각합시다*/

	// Subtracing an integer from a pointer
	ptr3 = ptr3 - 4;
	printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

	// Incrementing a pointer, Decrementing a pointer (증감 연산자 사용)
	ptr1++;
	ptr1--;
	++ptr1;
	--ptr1;
	/*후위 전위는 일반적인 변수와 동일하게 적용된다. 연산 결과값의 개념*/
	

	// Comparisons
	if (ptr1 == ptr3)
		printf("Same\n");
	else
		printf("Different\n");

	/*이렇게 포인터가 가리키는 값의 자료형이 같은 경우가 일반적인 포인터의 비교
	위에서 ptr3 - 4를 해서 ptr1과 ptr1은 같은 주소를 가리키는 포인터입니다.*/
	double d = 3.14;
	double* ptr_d = &d;
	if (ptr1 == ptr_d)
		printf("Same\n");
	else
		printf("Different\n");
	/*근데 다른 자료형의 포인터를 비교하면 Warning이 뜹니다.
	warning C4133 : '==' : 'double *'과(와) 'int *' 사이의 형식이 호환되지 않습니다.
	어쨌든 포인터의 사이즈는 int이던 double이던 동일하다.(이 포인터의 사이즈는 32비트, 64비트 운영체제에 따라 달라짐)
	따라서 비교할 수 는 있다. 근데 프로그래머의 실수로 인식한다.
	이렇게 헷갈리게 쓰면 안 됩니다.*/
	
	return 0;
}
