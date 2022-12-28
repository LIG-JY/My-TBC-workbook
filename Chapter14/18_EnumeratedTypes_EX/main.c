#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp (HINT!)
#include <stdbool.h>// C99

enum spectrum {red, orange, yellow, green, blue};
const char* colors[] = { "red", "orange", "yellow", "green", "blue" };


int main()
{
	while (1)
	{
		puts("Input a color name (empty line to quit):");
		
		// xx

		// if not xx -> break
		enum spectrum color;
		char choice[100] = { 0 , };
		
		if (scanf("%[^\n]%*c", choice) != 1)
			break;
		int flag = 0;
		for (color = red; color <= blue; ++color)
		{
			if (strcmp(colors[color], choice) == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			printf("Succes\n");
			switch (color)
			{
			case red:
				puts("Rose");
				break;
			case orange:
				puts("Oyeah");
				break;
			case yellow:
				puts("yeah");
				break;
			default:
				puts("noword");
				flag = 0;
			}
		}
		else
			printf("retry\n");
	}
	puts("Goodbye!");

	return 0;
}
