#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long get_long(void);

int main()
{
	long nubmer;
	while (1)
	{

		printf("Please input a number which is between 1 and 100.\n");
		nubmer = get_long(); // 사용자로 부터 롱타입 정수 1개를 입력받습니다.
		if (nubmer > 1 && nubmer < 100)
		{
			printf("OK! \n");
			break;
		}
		else
			printf("Wrong input! Please Try again.\n");
	}
	printf("OK! \n");
	return 0; 
}

long get_long(void) // 인자는 필요없습니다. long 타입의 값 1개를 return합니다.
{
	printf("Please input an integer and press enter.\n");

	long input;
	char c;

	while (scanf("%ld", &input) != 1)
		// scanf의 return은 제대로 된 입력값의 개수, 즉 ld형의 개수가 정확히 1개가 들어오면 -> 45 줄로 이동
	{
		printf("Your input - ");

		while ((c = getchar()) != '\n') // 버퍼에 있는 값들을 C에 할당하고, 출력하기 위함
		{
			putchar(c); // input left in buffer
		}

		printf(" - is not an integer. please try again.\n");
	}
	// while 문에 들어가지않고 아래를 출력합니다.
	printf("Your input %ld is an integer. Thank you. \n", input);

	return input;
}
