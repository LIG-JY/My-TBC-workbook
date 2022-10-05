#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '.'

int main()
{
	char ch;
	int n_chars = 0;
	int n_lines = 0;
	int n_words = 0;
	bool word_flag = false;
	bool line_flag = false;

	printf("Enter text :\n");

	while ((ch = getchar()) != STOP)
	{
		if (!isspace(ch))  // 공백이 아니라면
		{
			n_chars++;
		}
		if (!isspace(ch) && !line_flag)  // 줄을 바꾸고 처음 시작할 때 line 수를 증가시킵니다. 
		// 이후로 line_flag가 true이면 !line_flag가 false이기 때문에 line 수는 변화하지 않습니다.
		{
			n_lines++;
			line_flag = true;
		}	
		if (ch == '\n')  // 줄바꿈 기호이면, line_flag가 false가 되어, 다음 줄에서 첫 글자를 입력하면 line 수가 증가합니다.
		{
			line_flag = false;
		}
		if (!isspace(ch) && !word_flag)
		{
			n_words++;
			word_flag = true;
		}
		if (isspace(ch))
		{
			word_flag = false;
		}
	}
		
	printf("\n");
	printf("Character = %d, Words = %d, Lines = %d\n", n_chars, n_words, n_lines);
	
	return 0;
}

