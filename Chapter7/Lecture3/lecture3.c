#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>	// isalpha() and more

/*
	Reference link
	https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
*/

int main()		
{
	// Lower to Upper , Upper to Lower
	char ch;
	int ex;
	while ((ch = getchar()) != '\n')  // use '\n' to find the end of a sentence
	{
		ex = islower(ch);  // islower의 return 값 확인
		printf("%d", ex);
		if (islower(ch))  // ch 는 내부적으로 int
			ch = toupper(ch);
		else if (isupper(ch))
			// 'A' = 65 , 'a' = 97
			ch = tolower(ch);
		putchar(ch);
	}	
	
	return 0;
}
