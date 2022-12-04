#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// malloc(), free()

int main()
{
	/*float x;
	char str[] = "Dancing night away";

	int arr[100];*/


	/*
		malloc() returns a void type pointer.
		void* : generic pointer
		free() deallocates the memory
	*/

	double* ptr = NULL;

	ptr = (double*)malloc(30 * sizeof(double));  // 운영체제에게 Heap 공간에 240바이트 메모리 요청
	// malloc은 Pointer을 return한다. 근데 void 타입이다. 즉 운영체제 입장에서는 순수하게 주소다. 타입도 정해져 있지않다.
	// 따라서 쓰는 쪽에서 Casting이 필요하다.

	if (ptr == NULL)
	/*malloc 함수는 너한태 줄 메모리가 없다면 NULL 포인터를 리턴한다.*/
	{
		puts("Memory allocation failed.");  // 따라서 사용자에게 에러메세지 보내주고

		exit(EXIT_FAILURE);  // 메모리 할당이 실패한다면 아주 심각한 상황이다. 따라서 강제로 종료하는 코드.
		/*symbolic constant EXIT_FAILURE: 1이다. main()이 1을 return하는 것과 같다.
		synbolic constatn EXIT_SUCCESS: 0이다. main()이 0을 return하는 것과 같다.*/
	}

	free(ptr);  // 메모리 반납,  NULL pointer의 경우 아무런 일도 발생하지 않는다.
	ptr = NULL;  // 이사 후 주소가 남아있어서 NULL로 바꿔주면, 이제 진짜 사용 안 한다고 못 박을 수 있다.


	/* Dynamically Allocated Array */

	int n = 5;
	ptr = (double*)malloc(n * sizeof(double));  // n의 값이 runtime 중에 결정되도 사용할 수 있다. (강의 20분대 참조)

	if (ptr != NULL)
	{
		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);  // 배열처럼 사용 가능. 하지만 배열의 원소를 0으로 초기화 해주지는 않는다.
		printf("\n");

		for (int i = 0; i < n; ++i)
			*(ptr + i) = (double)i;  // double형 pointer 연산

		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);  // 배열처럼 사용 가능
		printf("\n");

	}


	/*
		Comparision to VLA
		VLA
		- not supported by VS compilers.
		- automatic duration, cannot be resized (STACK에 올라간다.)
		- limited by stack size (when compiler places VLA in stack segment)
	*/

	return 0;
}
