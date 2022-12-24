#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 101

struct book
{
	char name[20];
	char author[20];
};

void print_books(const struct book* books, int n);

int main()
{
	struct book my_books[3];// = { {"The Great Gatsby", "F. Scott Fitzgerald"}, ... };
	struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3); 
	if (!my_books)
	{
		printf("malloc failed");
		exit(1);
	}
	my_books[0] = (struct book) {"1bc", "def" };  // 구조체 자료형에 괄호 해줘야 syntax error 발생 안 한다.
	my_books[1] = (struct book){ "2bc", "def" };
	my_books[2] = (struct book){ "3bc", "def" };
	/*printf("%s %s",my_books[2].name, my_books[2].author);*/
	print_books(&my_books, strlen(my_books));
	return 0;
}

void print_books(const struct book* books, int n)
{
	for (int i = 0; i < n; ++i)
	{
		const struct book* my_book = books + i;
		printf("%s %s\n", my_book->name, my_book->author);
	}
}
