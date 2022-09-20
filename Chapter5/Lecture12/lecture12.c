#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void draw(int n);	// ANSI function prototype declaration

int main()
{

	int i = 5;
	char c = '#';
	float f = 7.1f;

	draw(i);
	draw(c); // parameter에 형변환이 일어납니다. char -> int로 promotion
	draw(f); // parameter에 형변환이 일어납니다


	/* Arguments vs. Parameters */
	// actual argument, actual parameter -> argument (values)
	// formal argument, formal parameter -> parameter (variables)

	return 0;
}

void draw(int n)
{
	while (n-- > 0)
		printf("*");
	printf("\n");


}
