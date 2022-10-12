#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>  // float가 가질 수 있는 가장 큰 값과 작은 값을 가져오기 위해서

int main()
{
	double min = FLT_MAX; // 가장 큰 값으로 초기화
	double max = -FLT_MAX; // 가장 작은 값으로 초기화
	double avg;
	double sum = 0.0f;
	double input;
	int n = 0;

	while (1)
	{
		
		if (scanf("%lf", &input) != 1)
		{
			break;
		}
		if (input > 100.0f || input < 0.0f)
		{
			continue;
		}
		if (input > max) // if 조건문 활용
		{
			max = input;
		}
		min = (input < min)? input : min; // 조건연산자 활용
		sum += input;
		n += 1;
	}
	avg = sum / n;
	
	if (n > 0)
		{
			printf("min = %lf, max = %lf, avg = %lf\n", min, max, avg);
		}
	else
	{
		printf("no input!\n");
	}

	return 0;
}
