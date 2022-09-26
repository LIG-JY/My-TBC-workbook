#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS	5  // c언어스럽게 define을 이용합니다.
#define FIRST_CHAR	'A'
#define LAST_CHAR   'K'

int main()
{
	
	for(int i = 1; i <= NUM_ROWS; i++)  // outer row loop
	{
		for(char j = FIRST_CHAR; j <= LAST_CHAR; j++)  // inner character loop
		{
			printf("%c ", j);	
		}
		printf("\n");
	}

	return 0;
}
