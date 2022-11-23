#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_array(const int arr[], const int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("% d", arr[i]);
	}
	printf("\n");
}

void add_value(int arr[], const int n, const int val)  // 배열의 모든값에 val을 더해줍니다.
// 여기는 배열에 const를 붙이면 안 되겠죠? 값을 변하게 해야하니
{
	int i;
	for (i = 0; i < n; ++i)
	{
		arr[i] += val;
	}
}

int sum(const int ar[], const int n)  
// const를 붙여주는 이유, 배열의 각 원소 값들을 더할 때, 배열의 값이 변하게 코딩 실수 방지
{

	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += ar[i];
	}

	return total;
}

int main()
{

	int arr[] = { 1, 2, 3, 4, 5 };
	const int n = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, n);
	add_value(arr,n, 100);
	print_array(arr, n);

	int s = sum(arr, n);
	printf("sum is %d\n", s);

 	return 0;
}
