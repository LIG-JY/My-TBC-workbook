#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int* ptr = 0;  // int* ptr = NULL; 이 일반적이다.

	printf("%p %lld\n", ptr, (long long)ptr);

	ptr += 1;  // pointer의 값에 더한다는 것이 어떤 의미인지 알아야합니다. 자료형의 사이즈 만큼 더해줍니다.

	printf("%p %lld\n", ptr, (long long)ptr);

	void* ptr_ = 0;  // void pointer > 포인터 산술연산을 할 수 없다.

	/*ptr = +ptr;
	ptr = -ptr;*/ // not working, 포인터 연산에 +,- 연산 부호 바꾸는 연산은 불가능하다.

	int arr[5];  // 배열 선언
	int* ptr1 = &arr[2];
	int* ptr2 = &arr[4];

	/*ptr1 = ptr1 + ptr2;*/ // pointer 변수끼리 더하는 것은 안 됩니다. 즉 주소를 더하는 것이 말이 안 됩니다. 

	long i = ptr2 - ptr1;  
	/* 포인터끼리 뺄 수 는 있다. 주소의 차이를 확인할 수 있다. */
	/*주어진 자료형 사이즈에서 몇칸 건넜냐? -> 즉 결국 index차이*/

	printf("%d %d %ld", ptr2, ptr1, i);  // 주소가 수치로 10진수 8만큼 차이나는데 이것을 자료형 int의 사이즈 4로 나누면 2죠

	return 0;
}
