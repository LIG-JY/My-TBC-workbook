#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int count = 0;

	while (1)
	{
		printf("Current count is %d. Continue? (Y/N)\n", count);

		int c = getchar();

		if (c == 'n' || c == 'N')
			break;

		else if (c == 'y' || c == 'Y')
		{
			count++;
		}

		else
		{
			printf("Please input y or n.\n");
		}
		while (getchar() != '\n')  // 첫번째 글자 만 남기고, 반복문에 의미가 없게 만드는 방법. 
			continue; //엔터를 누를 때 까지 반복문 돌아갑니다. 따라서 count가 증가하지 않겠네요.
	}
	return 0;
}
