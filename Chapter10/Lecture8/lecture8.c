#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double average(double*, double*);

int main()
{
	double arr1[5] = { 10, 13, 12, 7, 8};
	printf("%lf", average(arr1, arr1+5));  // 포인터 연산 더하기로 end를 구한다. while에서 start < end라서 5쥬 부.등.호 니깐!

	return 0;
}

double average(double* start, double* end)  // 배열의 첫 주소 , 마지막 주소 2포인터
{
	// int count = 0;
	int count = end - start;  // 포인터 연산을 통해서 몇 개를 건너뛰었는가? 즉 배열의 길이를 구할 수 있습니다.
	double avg = 0.0;
	while(start < end)
	{
		avg += *start++;  // start라는 포인터 dereferencing 해서 배열의 값을 찾고, 후위 연산자를 통해서 반복할 때 마다 다음 값으로 넘어간다.
		// start에서 결국 end 마지막 주소 전 까지 도달하면 while문이 종료됩니다.
		// count++;  int count = 0; 코드를 사용하면 count를 더해줘서 배열의 길이를 구해야합니다.
	}
	avg /= (double)count;
	
	return avg;
}
