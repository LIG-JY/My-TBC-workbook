#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>	// toupper(), ispunct(), ...

#define NUM_LIMIT 1024

void ToUpper(char*);
int PunctCount(const char*);

int main()
{
	char line[NUM_LIMIT];
	char* new_line = NULL;
	fgets(line, NUM_LIMIT, stdin);
	new_line = strchr(line, '\n');
	// strchr str에 해당하는 문자열에서 val에 해당하는 문자의 첫번째 포인터를 찾아줍니다.
	if (new_line)
	{
		*new_line = '\0';  // 찾으면 Null character로 바꾼다.
	}
	ToUpper(line);
	puts(line);
	printf("%d\n", PunctCount(line));
	puts(new_line);  // new_line은 Null character이라서 출력해보면 완벽한 공백임
	puts("hi");

	return 0;
}

void ToUpper(char* str)  // 문자의 포인터가 파라매터라면 사실상 문자열을 이용하기 위해서이다. 대부분 이렇다.
{
	while (*str) // NULL character 만나면 종료
	{
		*str = toupper(*str);
		/*
		if (islower(*str))
			*str = toupper(*str);
		*/
		str++;  // 문자열 포인터 이동
	}
}

int PunctCount(const char* str)
{
	int ct = 0;
	while (*str) // NULL character 만나면 종료
	{
		if (ispunct(*str))
		{
			ct++;
		}
		str++; // 문자열 포인터 이동
	}

	return ct;
}
