#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 10;

	int* ptr = NULL;

	ptr = (int*)calloc(n, sizeof(int));  // contiguous allocation
	
	if (!ptr)
	{
		exit(1);
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%p ", ptr + i);  // 주소
		printf("%d ", *(ptr + i));  // 주소에 대입된 값
		printf("%d \n", ptr[i]);  // 주소에 대입된 값
	}
	printf("\n");


	/*
		realloc() KNK p. 422
		- doesn't initialize the bytes added (새로추가된 부분 초기화 X) -> 쓰레기 값이 나올 수 있다.
		- returns NULL if can't enlarge the memory block
		- 첫번째 인자는 memory 블럭 즉 포인터이다. 두번째 인자에는 메모리의 양
		- If first argument is NULL, it behaves like malloc()
		- if second argument is 0, it "frees" the memory block. (다 쓰고 사용하면 된다.)
		- 재할당받고 싶을 때 사용하는 함수
	*/

	n = 20;
	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int));

	printf("%p %p ", ptr, ptr2);

	if (!ptr2)
	{
		exit(1);
	}
	else
	{
		ptr = NULL;
	}


	for (int i = 0; i < n; ++i)
	{
		printf("%p ", ptr2 + i);  // 주소
		printf("%d ", *(ptr2 + i));  // 주소에 대입된 값
		printf("%d \n", ptr2[i]);  // 주소에 대입된 값
	}

	free(ptr2);
	return 0;
}
