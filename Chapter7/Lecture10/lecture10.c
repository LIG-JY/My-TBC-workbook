#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* continue */


	/* while and continue */


	/* for and continue */
	for (int count = 0; count < 10; ++count) // getchar 입력할 때 buffer 확인
	{
		int c = getchar();
		if (c == 'a')
		{
			continue;
		}
		putchar(c);
	}


	/* continue as a placeholder */


	/* Need to use continue ? */


	/* break */





	return 0;
}
