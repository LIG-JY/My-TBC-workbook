#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_TITLE 40
#define MAX_AUTHOR 40
#define MAX_BOOKS 3	/* maximum number of books */

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

struct book
{
	char title[MAX_TITLE];
	char author[MAX_AUTHOR];
	float price;
};

int main()
{
	struct book library[MAX_BOOKS] = { {"Empty", "Empty", 0.0f}, }; /* array of book structures */

	int count = 0;

	while (1)
	{
		//TODO: input title
		printf("Input a book title or press [Enter] to stop.\n>>");
		char* title;
		title = fgets(library[count].title, MAX_TITLE, stdin);
		//TODO: break if the first character of the input title is '\0'
		if (title[0] == '\0' || title[0] == '\n')
			break;

		//TODO: input author name
		printf("Input the author.\n>>");
		char* author;
		title = fgets(library[count].author, MAX_AUTHOR, stdin);
		
		//TODO: input price
		printf("Input the price.\n>>");
		int flag;
		flag = scanf("%f", &(library[count].price));
		
		//TODO: clear buffer
		int c;

		while ((c = getchar()) != '\n' && c != EOF) {}
		
		count++;

		if (count == MAX_BOOKS)
		{
			printf("No more books.\n");
			break;
		}
	}

	if (count > 0)
	{
		printf("\nThe list of books:\n");
		for (int index = 0; index < count; index++)
			printf("\"%s\" written by %s: $%.1f\n",
				library[index].title, library[index].author, library[index].price);
	}
	else
		printf("No books to show.\n");

	return 0;
}
