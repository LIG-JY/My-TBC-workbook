#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	//char* title;		// Not recommended
	//char* author;		// Not recommended
	float price;
};

struct rectangle
{
	double width;
	double height;
};

double rect_area(struct rectangle r)
{
	return r.height * r.width;
}

double rect_area_ptr(struct rectangle * r)
{
	return r->height * r->width;
}

int main()
{
	struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f };

	/*
		Compound literals
		- Temporary structure values
	*/


	//book_to_read = { "Alice in Wonderland", "Lewis Carroll", 20.3f };//Error
	strcpy(book_to_read.title, "A whole new world");
	strcpy(book_to_read.author, "Aladin");
	book_to_read.price = 20.3f;

	struct book book_to_read2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
	book_to_read = book_to_read2;

	book_to_read = (struct book) { "Alice in Wonderland", "Lewis Carroll", 20.3f };

	struct rectangle rec1 = { 1.0 ,2.0 };
	double area = rect_area(rec1);
	printf("%lf\n", area);
	area = rect_area((struct rectangle) { 2.0, 3.0 });
	printf("%lf\n" , area);

	area = rect_area_ptr(&(struct rectangle) { .height = 5.0, .width = 6.0 });
	printf("%lf\n", area);

	return 0;
}
