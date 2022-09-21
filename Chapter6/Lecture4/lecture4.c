#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	//fabs()

int main()
{
	/*
		Relational Operators
		<		is less than
		<=		is less than or equal to
		==		is equal to
		>=		is greater than or equal to
		>		is greater than
		!=		is not equal to
	*/

	int n = 0;
	while (n++ < 5) // relational expression (관계식)
	{
		printf("%d", n);
	}
	printf("\n");

	char c = 'A';
	while (c != 'Z')
		printf("%c", c++);


	const double PI = 3.1415926535897932384626433832795;
	double guess = 0.0;

	printf("Input pi : ");
	scanf("%lf", &guess);
	/*while (guess != PI)*/ // relational expression 에서 값 0인지 1인지 판단.
	/*실수 끼리 비교할 때 !=을 잘 사용하지 않습니다. bit로 변환해서 정확하게 같은지를 판단해야하는데
	정확하게 같은 값을 입력하기 쉽지 않습니다. 부동소수점 생각!
	정밀도 문제*/
	while (fabs(guess - PI) > 0.01) // 추측한 값과 원래 파이값의 차이의 절대값이 0.01보다 작다면..? 앱실론 느낌
	{
		printf("Fool Try again! \n");
		scanf("%lf", &guess);
	}
	printf("Good!");
	return 0;
}
