#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* Two of 1D arrays */
	int arr0[3] = { 1, 2, 3 };
	int arr1[3] = { 4, 5, 6 };
	int* parr[2] = { arr0, arr1 };  // 포인터를 원소로가지는 배열, 포인터의 배열

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			printf("%d(==%d, %d, %d) ", parr[j][i], *(parr[j] + i), *(*(parr + j) + i), (*(parr + j))[i]);
			// parr[j] = arr1 이나 arr0 , 근데 arr1이나 arr0도 배열의 이름이다. 배열의 이름은 포인터다.
			// 따라서 포인터 연산을 할 수 있다.
			// 포인터의 연산은 인덱스의 이동이다.
			// (*(parr + j))[i] 여기서 괄호 빼먹으면 안 됩니다. 연산자 우선순위가 []가 더 높아서 *을 먼저해줘야함
		}
		printf("\n");
	}
	printf("\n");


	/* 2D arrays are arrays of 1D arrays */
	int arr_2d[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

	int* parr0 = arr_2d[0];
	int* parr1 = arr_2d[1];
	// 포인터 변수에 배열을 할당하면 배열의 이름과 동일하게 사용할 수 있다. 배열의 0번째 원소를 가리키는 포인터가 된다.
	for (int i = 0; i < 3; ++i)
	{
		printf("%d \t%d \n", parr0[i], parr1[i]);
	}

	/* arrays of pointers works like a 2D array */
	int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	
	int* parrr[2];  // 선언, 포인터를 담는 8바이트 메모리 공간의 첫번째 주소를 가리킨다.
	parrr[0] = arr[0];  // 각각은 4바이트 짜리 포인터, 초기화를 해주면 포인터가 arr[0] 즉 {1, 2, 3}의 첫번째 원소인 1의 주소를 가리킨다.
	parrr[1] = arr[1];

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			printf("%d(==%d, %d, %d) ", parrr[j][i], *(parrr[j] + i), *(*(parrr + j) + i), (*(parrr + j))[i]);
			// parrr[j] = arr1 이나 arr0 , 근데 arr[0]이나 arr[1]도 포인터이다. 포인터는 배열의 이름과 같은 역할을 한다.
			// 따라서 포인터 연산을 할 수 있다.
			// 포인터의 연산은 인덱스의 이동이다.
			// (*(parrr + j))[i] 여기서 괄호 빼먹으면 안 됩니다.
		}
		printf("\n");
	}
	printf("\n");

	/*
		Notes
		- parrr[0] and parrr[1] do not point valid memory by default
		- &parrr[0] != &arr[0]
	  - &parrr[0] != parrr[0] but &arr[0] == arr
	*/

	printf("%p\n", &parrr[0]);  // arr[0]이라는 포인터를 가리키는 포인터의 주소
	printf("%p\n", parrr[0]);  // arr[0]이라는 포인터의 주소/ {1, 2, 3}을 가리키는데, 첫번째 원소인 1의 첫번째 메모리를 가리킨다.
	printf("%p\n", arr);  // arr이라는 배열의 이름, 포인터와 같은 역할을 하고, arr[0]의 첫번째 원소인 1의 첫번째 메모리를 가리킨다.
	printf("%p\n", &arr[0]);  // arr[0]이라는 포인터의 주소/ {1, 2, 3}을 가리키는데, 첫번째 원소인 1의 첫번째 메모리를 가리킨다.
	printf("%p\n", arr[0]);  // {1, 2, 3}을 가리키는 포인터. 첫번째 원소인 1의 첫번째 메모리를 가리킨다.
	printf("%p\n", &arr[0][0]);  // arr[0]의 첫번째 원소arr[0][0]인 1의 첫번째 메모리를 가리킨다.

	/* Array of string of diverse lengths example */

	char* name[] = { "son", "don" , "kon" , "mon" };  // 포인터의 배열, 배열 앞의 자료형이 포인터로 선언했죠?
	// 각각의 원소들은 null char까지 char[4]입니다. 즉 원소가 4개인 char배열

	const int n = sizeof(name) / sizeof(char*);  // 그래서 sizeof도 각 element는 포인터의 크기로 계산하죠?

	for (int i = 0; i < n; ++i)
	{
		printf("%s at %u\n", name[i], (unsigned)name[i]); // use ull(unsigned long) in x64 build
	}
	printf("\n");

	char aname[][15] = {"son", "don", "kon" , "mon"};  // 문자열의 배열 

	const int m = sizeof(aname) / sizeof(char[15]);  // 하지만 각각은 char[15]로 크기가 미리 정해져있습니다.

	for (int i = 0; i < m; ++i)
	{
		printf("%s at %u\n", aname[i], (unsigned)&aname[i]); // use ull(unsigned long) in x64 build
	}
	printf("\n");

	return 0;
}
