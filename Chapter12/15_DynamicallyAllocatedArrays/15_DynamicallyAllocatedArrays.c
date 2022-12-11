#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
		One variable
	*/
	// int형 변수 하나를 다뤄봅니다.

	int* ptr = NULL;
	ptr = (int*)malloc(sizeof(int) * 1);
	if (!ptr) exit(1); // !은 not연산자

	*ptr = 123;
	printf("%d\n", *ptr);  // indirection 해서 값을 바꿔줍니다,

	free(ptr);
	ptr = NULL;
	

	/*
		1D array
	*/

	//int n = 3;
	//int* ptr_1d = NULL;
	//ptr_1d = (int*)malloc(sizeof(int) * n);
	//if (!ptr_1d) exit(1); // !은 not연산자

	//ptr_1d[0] = 123;
	//*(ptr_1d + 1) = 456;
	//*(ptr_1d + 2) = 789;
	//printf("%d\n", *ptr_1d);  // indirection 해서 값을 바꿔줍니다,

	//free(ptr_1d);
	//ptr = NULL;

	/*
		2D array
	*/

	/*int row = 3, col = 2;
	int* ptr_2d[2] = (int(*)[2])malloc(sizeof(int) * row * col);*/
	// col값을 하드코딩 해야하기 때문에 동적할당의 의미가 많이 퇴색된다.
	// 

	/*
		Using 1D arrays as 2D arrays
		row = 3, col = 2
		(r, c)
		2D
		(0, 0) (0, 1)
		(1, 0) (1, 1)
		(2, 0) (2, 1)
		1D
		(0, 0) (0, 1) (1, 0) (1, 1) (2, 0) (2, 1)
		0      1      2      3      4      5      = c + col개수 * r

	*/
	int row = 3, col = 2;
	int* ptr_prac = (int*)malloc(sizeof(int) * row * col);
	if (!ptr_prac) exit(1);

	for (int r = 0; r < row; ++r)
		for (int c = 0; c < col; ++c)
		{
			ptr_prac[c + col * r] = c + col * r;  // 포인터를 배열처럼
		}

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			printf("%d ", *(ptr_prac + c + col * r));  // 포인터 연산
		}
		printf("\n");  // row 바뀔 때 마다 줄바꿈하게
	}
		

	/*
		Using 1D arrays as 3D arrays
		row = 3, col = 2, depth = 2
		(r, c, d)
		3D
		-------------------
		(0, 0, 0) (0, 1, 0)
		(1, 0, 0) (1, 1, 0)
		(2, 0, 0) (2, 1, 0)
		-------------------
		(0, 0, 1) (0, 1, 1)
		(1, 0, 1) (1, 1, 1)
		(2, 0, 1) (2, 1, 1)
		-------------------
		1D
		(0, 0, 0) (0, 1, 0) (1, 0, 0) (1, 1, 0) (2, 0, 0) (2, 1, 0) (0, 0, 1) (0, 1, 1)	(1, 0, 1) (1, 1, 1) (2, 0, 1) (2, 1, 1)
		0         1         2         3         4         5         6         7         8         9         10        11
		= c + col개수 * r + (col개수*row개수) * d
		= 1 + 2 * 1 + (3*2) * 1 = 1 + 2 + 6 = 9
		3D
		row, col, depth, height
		(r, c, d, h)
		index = c + col * r + (col*row) * d + (row * col * depth) * h
	*/

	return 0;
}
