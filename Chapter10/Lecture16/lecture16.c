#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ROWS 3  // 매크로, 기호적 상수(Symbolic constant)
#define COLS 4

int sum2d_1(int ar[ROWS][COLS]);  
int sum2d_2(int ar[][COLS], int row);  // 첫번째 []를 ROWS로 채워도 컴파일러에서는 무시한다. C문법이 이렇다. (설명 X)
//int sum2d_2(int [][COLS], int row);
//int sum2d_2(int (*ar)[COLS], int row);// ar is a SINGLE pointer to the array of COLS ints 
//(COLS개만큼의 int형 element를 가진 배열들을 원소로 가지는 배열에 대한 포인터
int sum2d_3(int* ar, int row, int col);
//int sum2d_3(int*, int, int); 변수의 이름은 생략해도 됩니다. ㅋㅋ

int main()
{
	//int a = 3;
	//int arr[a];

	int data[ROWS][COLS] = {
								{1, 2, 3, 4},
								{5, 6, 7, 8},
								{9, 0, 1, 2}
	};
	// data라는 배열은 컴파일할 때 total 사용하는 메모리가 결정된다. (동적 할당과 차이)
	printf("%d %p\n", data[2][3], &(data[2][3])); // 3행 4열의 2

	int* ptr = &data[0][0];  // int형의 자료의 주소를 담는 포인터 변수. 1의 주소를 담고있다.
	printf("%d %p\n", *(ptr + 3 + COLS * 2), ptr + 3 + COLS * 2);  // (ptr + 3 + COLS * 2) 포인터 연산
	// *(ptr + 3 + COLS * 2) indirection으로 int형의 데이터에 접근합니다. 3행 4열의 2 (주소도 동일함을 알 수 있습니다.)

	printf("Sum of all elements = %d\n", sum2d_1);
	printf("Sum of all elements = %d\n", sum2d_2(data, ROWS));
	printf("Sum of all elements = %d\n", sum2d_3(&data[0][0], ROWS, COLS));

	return 0;
}

int sum2d_1(int ar[ROWS][COLS])
{
	int r, c, tot = 0;
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			tot += ar[r][c];
		}
	}
	return tot;
}

int sum2d_2(int ar[][COLS], int row)
{
	int r, c, tot = 0;
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			tot += ar[r][c];
		}
	}
	return tot;
}

int sum2d_3(int* ar, int row, int col)  // ar은 큰 메모리덩어리 대표주소
{
	int r, c, tot = 0;
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			tot += *(ar + r * col + c);  // ar[r * col + c] 둘다 동일하다. 포인터 연산이 사실상 인덱스 subscribing
		}
	}

	return tot;
}

/*
	In higher dimensions,
	you may omit the value in the left-most bracket -> 가장 왼쪽 []는 비워도 됩니다. 위에서 언급했쥬?
	int my_function(int ar[][3][5][8], int rows);
	int my_function(int (*ar)[3][5][8], int rows);
*/
