#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num, sum = 0;

	printf("Enter an integer (q to quit) : ");
	// scanf에 q를 넣으면 format_specifier가 %d이기 때문에 입력을 받지 않습니다.
	/*따라서 0개를 입력받은 scanf의 retunr은 0이되고 0이라는 값이 status에 할당됩니다.
	반면 정수를 입력하면 1개를 입력받은 scanf의 return값은 1입니다.*/
	while (scanf("%d", &num) == 1) // 1개를 입력받았다면 loop를 반복합니다. 괄호로 묶인 expression의 값은 1입니다.
	{
		sum += num;
		printf("Enter next integer (q to quit) : ");

	}
	printf("Sum = %d\n", sum);

	return 0;
}

