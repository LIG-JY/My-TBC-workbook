#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	double seed, target, interest;
	printf("input seed money : ");
	scanf_s("%lf", &seed); // double에 대응하는 %lf
	printf("input target money : ");
	scanf_s("%lf", &target);
	printf("input annual interset money (%%) : "); // %%로 %를 출력할 수 있습니다.
	scanf_s("%lf", &interest);

	int count = 0;
	
	while (seed < target)
	{
		seed = seed * (1 + interest / 100.0); // 나누는 대상 double로 표현합시다. "100.0"
		count += count; // count++; 증가연산자를 사용해도 됩니다.
		printf("Year: %d, Fund: %.5f\n", count, seed); // printf에서는 %f로 사용해도 어차피 double로 변환합니다.
	}
	printf("It takes %d years", count);
	return 0;
}
