#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[2][3] = { { 1, 2, 3 },
					{4, 5, 6} };

	// int arr[2][3] = { 1, 2, 3, 4, 5, 6 };  -> 위의 2차원 배열 선언과 동일하게 작동합니다.
	// int arr[2][3] = {1, 2}  insufficient initializer -> 1차원 배열처럼 부족하면 나머지는 0으로 채워줍니다.

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			printf("%d ", arr[j][i]);  // 실제 메모리구조와 일치하게 하면 더 빠르다.
		}
		printf("\n");
	}

	int* ptr = &arr[0][0];  // pointer -> 첫 주소
	for (int k = 0; k < 6; ++k)
	{
		printf("%d", ptr[k]);  // 배열의 포인터 변수에 인덱스로 배열의 값에 접근 가능.. 
		/*동적할당 메모리를 다차원 배열처럼 사용하는 방법에 대한 강의를 참고하시면 도움이 될 것 같습니다.*/
		printf("%zd %zd\n", sizeof(arr), sizeoff(arr[0]));
	}
	

	return 0;
}

