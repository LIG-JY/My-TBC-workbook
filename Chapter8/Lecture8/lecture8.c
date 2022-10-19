#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char get_choice(void);
char get_first_char(void);
int  get_integer(void);
void count(void);

int main()
{
	int user_choice;

	while ((user_choice = get_choice()) != 'q')
	{
		switch (user_choice)
		{
		case 'c':
			count();
			break;

		case 'a':
			printf("Avengers assemble\n");
			break;

		case 'b':
			printf("\a\n");
			break;

		default:
			printf("Error with %d.\n", user_choice);
			exit(1); // c프로그램 완전히 종료, 운영체제에서 1을 return
			break;
		}
	}
	return 0;
}

void count(void)

{
	int n;
	printf("Enter an integer!\n");
	n = get_integer();
	unsigned int start = 1;
	while (start <= n)
	{
		printf("%d\n", start); // 1 부터 오름차순으로 num 변수에 입력받은 값까지 출력
		start += 1;
	}
	while ((getchar()) != '\n') // buffer에 기존 입력 제거
	{
		continue;
	}
}
//
char get_choice(void)
{
	int user_input;

	printf("Enter the letter of your choice:\n");
	printf("a. avengers\t");
	printf("b. beep\n");
	printf("c. count\t");
	printf("q. quit\n");

	user_input = get_first_char();
	
	while ((user_input < 'a' || user_input > 'c') && user_input != 'q')
	{
		printf("Please try agian.\n"); // 입력 유효성 검증
		user_input = get_first_char();
	}

	return user_input;
}
//
char get_first_char(void)
{
	int ch;

	ch = getchar();
	while ((getchar()) != '\n') // buffer에 기존 입력 제거
	{
		continue;
	}
	return ch;
}
//
int get_integer(void)
{
	int input;
	char c;
	while ((scanf("%d", &input)) !=1) // scanf에 정수형이 1개 제대로 입력되지 않으면, 반복문으로 들어갑니다.
	{
		while ((c = getchar()) != '\n') 
		{
			putchar(c);
		}
		printf("is not an integer. \nPlease try again.\n"); 
	}

	return input;
}
