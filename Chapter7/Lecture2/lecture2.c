#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// getchar(), putchar()

int main()
{
	/*
		 1. Intoduce getchar(), putchar()
		 2. Use while loop to process character sequences
		 3. Filter a specific character
		 4. Convert numbers to asterisks
		 5. Lower characters to Upper characters
	*/

	char ch;
	// int ch
	ch = getchar();  // 한 글자를 가져오는 함수, return은 int ASCII
	putchar(ch);  // 한 글자를 화면에 출력하는 함수

	//
	char ch;

	ch = getchar()

	while (ch != '\n')  // use '\n' to find the end of a sentence
	{
		putchar(ch);  // buffer의 개념,

		ch = getchar();
	}	

	putchar(ch);

	//  while문 조건 expression에 함수의 return 활용하기

	while ((ch = getchar()) != '\n')  // use '\n' to find the end of a sentence
	{
		putchar(ch);  
	}	

	putchar(ch);

	// filtering

	while ((ch = getchar()) != '\n')  // use '\n' to find the end of a sentence
	{
		if (ch == 'f' || ch == 'F')  // 더 좋은 방법 or이라는 논리연산자
		{
			ch = 'X';
		}
		// if (ch == 'F')  // 대문자 F도 바꾸기. 하지만 더 좋은 방법이 없을까?
		// {
		// 	ch = 'X';
		// }
		
		putchar(ch);
	}	

	putchar(ch);

	// asterisks로 바꾸기

	while ((ch = getchar()) != '\n')  // use '\n' to find the end of a sentence
	{
		// if (ch == '0')  // 모든 숫자를 다 커버할 수는 없을까?
		// {
		// 	ch = '*';
		// }

		// for (int i = '0'; i <= '9'; ++i)  // ASCII 활용하기 for문 활용
		// 	if (ch == i)
		// 		ch = '*';

		if (ch >= '0' && ch <= '9')
			ch = '*';
		
		putchar(ch);
	}	

	putchar(ch);

	// Lower to Upper , Upper to Lower

	while ((ch = getchar()) != '\n')  // use '\n' to find the end of a sentence
	{

		if (ch >= 'a' && ch <= 'z')  // 'A' = 65 , 'a' = 97
			ch -= 'a' - 'A';
		elif (ch >= 'A' && ch <= 'Z')  // 'A' = 65 , 'a' = 97
			ch += 'a' - 'A';
		
		putchar(ch);
	}	

	return 0;
}
