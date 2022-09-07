#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc()

struct MyStruct // structure 구조체
{
	int i;  // 4bytes
	float f; // 4bytes
};

int main()
{
	/* 1. sizeof basic types */
	int a = 0;
	unsigned int int_size1 = sizeof a;  // sizedof 변수명, 이 방식이 FM입니다.
	unsigned int int_size2 = sizeof(int);  // sizedof(자료형) 함수와 유사해보이지만, "연산자"가 정확합니다.
	unsigned int int_size3 = sizeof(a);  // sizedof(변수명) 함수와 유사해보이지만, "연산자"가 정확합니다.

	size_t int_size4 = sizeof(a); // 일 할 때 어떤 사람은 portalbe type만을 써라고 약속하기도 합니다.
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes. \n", int_size1);
	printf("Size of int type is %zu bytes. \n", int_size4);
	printf("Size of float type is %zu bytes. \n", float_size); // portalbe type의 format specifier은 %zu입니다.

	/* 2. sizeof arrays */
	int int_arr[30]; // int_arr 이라는 배열을 초기화합니다. int_arr은 배열을 대표하는 주소입니다. 선언을 할 때 메모리공간을 할당합니다. 컴파일러가 컴파일 하면서 바로 메모리 크기를 알 수 있습니다.
	int *int_ptr = NULL; // pointer 주소를 적을 수 있는 종이를 들고있습니다. 일단 선언을 먼저하고 다음줄에서 메모리 공간을 할당합니다. 컴파일러는 int_ptr이 대표하는 메모리 크기를 모릅니다. (동적할당, 런타임에 결정됩니다.)
	int_ptr = (int*)malloc(sizeof(int) * 30); // malloc: mameroy allocation, 120바이트짜리 메모리공간을 할당하고 그 메모리 공간을 대표하는 첫번째 주소를 ptr에 적는다.

	printf("Size of array = %zu bytes \n", sizeof(int_arr));
	printf("Size of Pointer = %zu bytes \n", sizeof(int_ptr));

	/* 3. sizeof character array */
	char c = 'a'; // 문자 1개 저장, 1바이트, 내부적으로는 int(97)
	char string[10]; // 문자를 10개저장할 수 있는 공간이 sting에 저장되어 있다. C언어에서는 문자열을 저장할 때 마지막에 Null character을 꼭 저장합니다.
	/* maximally 9 character + '\0' (null character) */

	size_t char_size = sizeof(char);
	size_t str_size = sizeof(string);

	printf("size of char type is %zu bytes.\n", char_size);
	printf("size of string type is %zu bytes.\n", str_size);

	/* 4. sizeof structure */

	printf("size of MyStruct is %zu\n", sizeof(struct MyStruct)); // 구조체 안의 자료형이 차지하는 메모리 공간의 합

	return 0;
}
