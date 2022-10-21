#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// strlen()
#include <stdbool.h>

#define WIDTH	60
#define NAME	"Your name"
#define ADDRESS "City, Citizenship"
#define Aw "Yahoo"

void print_multiple_chars(char c, int n_stars, bool print_newline) // 정의(선언과 정의의 차이점 생각하기)
{
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);   // putchar(c);
	if (print_newline)
	{
		printf("\n");
	}
}


void print_centered_str(char str[])
{
	int n_blanks = 0;
	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks, false);
	printf("%s\n", str);
}

int main()
{
	print_multiple_chars('@', WIDTH, 1);
	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str(Aw);
	print_multiple_chars('@', WIDTH, 1);
	return 0;
}

