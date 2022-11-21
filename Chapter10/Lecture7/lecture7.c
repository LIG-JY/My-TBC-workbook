#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double average(double [], int n);

int main()
{

	return 0;
}

double average(double arr[], int n)  // 배열 사이즈에 구애받지 않고 인자로 사용할 수 있다. arg1: 첫주소, arg2: 배열의 개수
{
	printf("Size = %zd in function average\n", sizeof(data_array));  // pointer의 사이즈가 결과

	double avg = 0.0;
	for (int i=0; i < n; ++i)
	{
		avg += arr[i];
	}
	avg /= (double)n;

	return avg;
}

/*
프로토타입 4가지, 여튼 * [] 나오면 배열을 인자로 받는다고 생각만 합시다.
double average(double *arr, int n);
double average(double *, int n);
double average(double arr[], int n);
double average(double [], int n);
*/
