#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);//TODO: add a new menu

int main()
{
	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try agian!!!\n");

	while (true)
	{
		printf("Choose an option:\n");
		printf("u) to upper\n");
		printf("l) to lower\n");
		printf("t) to transpose\n");//TODO: add a new menu
		
		char c;
		while (scanf("%c%*[^\n]%*c", &c) != 1)
			printf("Please try agian.\n");

		typedef void (*FUCKPTR)(char*);
		FUCKPTR options[] = { ToUpper , ToLower ,Transpose };
		char operation[] = { 'u', 'l', 't' };

		void (*fucptr)(char*);
		for (int i = 0; i < sizeof(operation) / sizeof(char); i++)
		{
			if (c == operation[i])
			{
				fucptr = options[i];
				fucptr(input);
			}
		}

		/*switch (c) {
		case 'u': fucptr = ToUpper; fucptr(input);  break;
			
		case 'l': fucptr = &ToLower; fucptr(input); break;

		case 't': fucptr = options[2]; fucptr(input); break;

		default: break;
		}*/
		
		break;
	}

	printf("%s", input);

	return 0;
}

void update_string(char* str, int(*pf)(int))
{

}

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
		{
			*str = toupper(*str);
		}
		else
		{
			*str = tolower(*str);
		}
		str++;
	}
}
