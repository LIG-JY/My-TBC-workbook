#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char get_choice(void);
char get_first_char(void);
int  get_integer(void);
void count(void);

int main()
{
	
	while (1)
	{
		printf("Enter the letter of your choice:\n");
		printf("a. avengers\t");
		printf("b. beep\n");
		printf("c. count\t");
		printf("q. quit\n");
		char c;
		c = getchar();
		if (c == 'c')
		{
			char temp;
			while ((temp = getchar()) != '\n') // buffer에 기존 입력 제거
			{
				continue;
			}
			count();
		}
		else if (c == 'a')
		{
			printf("Avengers assemble\n");
			char temp;
			while ((temp = getchar()) != '\n') // buffer에 기존 입력 제거
			{
				continue;
			}
		}
		else if (c == 'b')
		{
			printf("\a\n");
			char temp;
			while ((temp = getchar()) != '\n') // buffer에 기존 입력 제거
			{
				continue;
			}
		}
		else if (c == 'q')
		{
			break;
		}
	}
	return 0;
}

void count(void)

{
	printf("Enter an integer!\n");
	unsigned int start = 1;
	unsigned int num;
	scanf("%d", &num);
	while (start <= num)
	{
		printf("%d\n", start); // 1 부터 오름차순으로 num 변수에 입력받은 값까지 출력
		start += 1;
	}
	char temp;
	while ((temp = getchar()) != '\n') // buffer에 기존 입력 제거
	{
		continue;
	}
}
