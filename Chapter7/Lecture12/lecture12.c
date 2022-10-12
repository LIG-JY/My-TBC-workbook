#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char c;
	while ((c = getchar()) != '.')
	{
		printf("You love ");

		switch (c)
		{
		case 'a':
		case 'A':
			printf("apple");
			break;
		case 'b':
		case 'B':
			printf("banana");
			break;
		case 'c':
		case 'C':
			printf("chocolate");
			break;
		default:
			printf("nothing"); // default에는 break 필요없습니다.	
		}

		printf(".\n");

		while (getchar() != '\n')
		{
			continue;
		}
	}

	return 0;
}
