#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);
char* s_gets(char* st, int n);

int main()
{
	struct name_count user_name;

	user_name = receive_input();  // lastname, firstname 멤버에 값을 복사한다.
	user_name = count_characters(user_name);  // num 멤버에 값을 복사한다.
	show_result(user_name);

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);  // vs. scanf()
	if (ret_val)
	{
		find = strchr(st, '\n');	// look for newline
		if (find)					// if the address is not NULL
			*find = '\0';			// place a null character there
		else
			while (getchar() != '\n')
				continue;			// dispose of rest of line
	}

	return ret_val;
}

struct name_count receive_input()
{
	struct name_count result;   // 선언만 합니다.
	int flag;

	printf("Input your first name:\n>> ");

	//s_gets(ptr_nc->first, NLEN);
	flag = scanf("%[^\n]%*c", result.first); // ^ : cap operator:not을 의미합니다.
	printf("%d \n", flag);
	if (flag != 1)
		printf("Wrong input");

	printf("Input your last name:\n>> ");

	//s_gets(ptr_nc->last, NLEN);
	flag = scanf("%[^\n]%*c", result.last);
	if (flag != 1)
		printf("Wrong input");

	return result;
} 

struct name_count count_characters(struct name_count result)
{
	result.num = strlen(result.first) + strlen(result.last);
	//ptr_nc->num = (int)strlen(ptr_nc->first) + (int)strlen(ptr_nc->last); // int castings remove warnings
	return result;
}

void show_result(const struct name_count result)
{
	printf("Hi, %s %s. Your name has %d characters.\n",
		result.first, result.last, result.num);
}
