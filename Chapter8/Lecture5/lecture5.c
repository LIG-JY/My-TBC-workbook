#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char cr, int lines, int width);

int main()
{
	char c;
	int rows, cols;

	printf("Input one character and two integers\n");
	while ((c = getchar()) != '\n')  // 프로그램 반복을 종료하려면 엔터 아니면 문자가 입력
	{
		scanf("%d %d", &rows, &cols);
		while (getchar() != '\n')  // buffer에 있는 엔터 지우기, 입력을 할 때 1 3 이렇게 2글자까지 입력되고 나머지는 버퍼에 있다.
		{
			continue;  // 이 반복문을 통해서 버퍼에 있는 입력을 받아 버퍼를 정리합니다.
		}
		display(c, rows, cols);  // 문자 , 숫자, 숫자 입력
		printf("Input another character and other integers:\n");
		printf("Press enter to quit.\n");
	}
	

	
	return 0;
}

void display(char cr, int lines, int width)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%c", cr);
		}
		printf("\n");
	}
}
