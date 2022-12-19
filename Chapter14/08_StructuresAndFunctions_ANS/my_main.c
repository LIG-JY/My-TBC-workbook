#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NLNE 30

struct name_count {
	char first[NLNE];
	char last[NLNE];
	int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main()
{
	struct name_count user_name;

	receive_input(&user_name);
	count_characters(&user_name);
	show_result(&user_name);

	return 0;
}


void receive_input(struct name_count* name)
{
	printf("Input your first name:\n");
	s_gets(&(name->first), NLNE);
	printf("Input your last name:\n");
	s_gets(&(name->last), NLNE);
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);  // vs. scanf()
	if (ret_val)  // not NULL
	{
		find = strchr(st, '\n');	// look for newline. strchr() 함수는 string의 문자로 변환되는 c의 첫 번째 표시에 대한 포인터를 리턴합니다. 함수는 지정된 문자를 찾지 못하면 NULL을 리턴합니다.
		if (find)					// if the address is not NULL
			*find = '\0';			// place a null character there
		else  // strchr retrun NULL
			while (getchar() != '\n')
				continue;			// dispose of rest of line
	}

	return ret_val;
}

void count_characters(struct name_count* name)
{
	int fisrt = strlen(name->first);
	int last = strlen(name->last);
	name->num = fisrt + last;
}

void show_result(const struct name_count* name)
{
	printf("Hi, %s %s. Your name has %d characters\n", name->last, name->first, name->num);
}
