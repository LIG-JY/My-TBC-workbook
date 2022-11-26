#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define COLS 4

int sum_1d(int arr[], int n);
int sum_2d(int arr[][COLS], int rows); 

int main()
{
	int a = 1; // 1이 Literal 이 Literal의 값을 a라는 변수에 대입해주는 구조이다.
	3;		// Literals are constants that aren't symbolic
	3.14f;
	int b[2] = { 3, 4 };  // 3과 4가 묶여있다.compound
	(int[2]) {
		3, 4
	};		// compound literal, 이름(symbolic)이 없는 literal

	int arr1[2] = { 1, 2 };
	int arr2[2][COLS] = { {1, 2, 3}, { 4, 5, 6 } };

	printf("%d \n", sum_1d(arr1, 2));
	printf("%d \n", sum_2d(arr2, 2));  // 배열의 이름을 선언하고, 배열의 이름을 포인터처럼 파라매터로 넣는다.
	printf("\n");

	printf("%d \n", sum_1d((int[2]) { 1, 2 }, 2));
	printf("%d \n", sum_2d((int[2][COLS]) { {1, 2, 3}, { 4, 5, 6 }}, 2));  // parameter에 Literal로 바로 넣습니다.
	printf("\n");

	int* ptr1;  // int형 자료 1개에 대한 포인터(주소를 담는 변수)
	int(*ptr2)[COLS];  // int형 자료 COLS개를 원소로 갖는 배열에 대한 포인터

	ptr1 = (int[2]) { 1, 2 };
	ptr2 = (int[2][COLS]){ {1, 2, 3}, { 4, 5, 6 } };

	printf("%d \n", sum_1d((ptr1),2));
	printf("%d \n", sum_2d((ptr2),2));  // parameter에 Literal로 바로 넣습니다.
	printf("\n");


	return 0;
}

int sum_1d(int arr[], int n)
{
	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		total += arr[i];
	}
	return total;
}


int sum_2d(int arr[][COLS], int rows)
{
	int total = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < COLS; ++j)
			total += arr[i][j];
	}
	return total;
}
