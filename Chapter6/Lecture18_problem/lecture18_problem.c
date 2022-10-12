#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compute_pow(int base, int exp);

int main()
{
	int base, exp;
	while(scanf("%d %d", &base, &exp) == 2);  // while문의 조건에 Scanf의 return 사용하기, 조건문을 빠져나오고 싶으면 숫자가 아닌 것을 1개 입력하기.
	{
		int result = 1;
	for (int i = 0; i < exp; i++)
	{
		result *= base;
	}
	printf("Result = %d\n", result);	
	}
	
	
	return 0;
}

//int compute_pow(int base, int exp)
//{
//
//
//}

/* 함수 사용은 아래부터 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compute_pow(int base, int exp);  // Proto type으로 분리하기. Linking을 활용 분리해서 컴파일하고 Linking 과정에서 연결해줍니다.

int main()
{
	int base, exp, result;
	while(scanf("%d %d", &base, &exp) == 2)  // while문의 조건에 Scanf의 return 사용하기, 조건문을 빠져나오고 싶으면 숫자가 아닌 것을 1개 입력하기.
	{
		result = compute_pow(base, exp);
		printf("Result = %d\n", result);	
	}
	
	
	return 0;
}

int compute_pow(int base, int exp) // return값 int로
{
	int result = 1;  // scope 개념, 함수의 지역변수
	for (int i = 0; i < exp; i++)
	{
		result *= base;
	}
	return result;
}
