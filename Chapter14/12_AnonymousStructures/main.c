#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 20

struct names
{
	char first[MAX];
	char last[MAX];
};

struct person
{
	struct names names;  // nested structure member
	int id;
};

struct person2
{
	struct {
			char first[MAX];
			char last[MAX];
			};  // anonymous structure
	int id;
};

int main()
{
	struct person gus = { {"adfa", "bcad"}, 1 };
	struct names shan_names = { "shan", "gus" };
	struct person shan = { shan_names, 2 };
	puts(gus.names.first);
	puts(shan.names.last);

	struct person2 zus = { {"zxc", "cxz"}, 3 };
	// struct person2 zus = { "zxc", "cxz" , 3 };  // also works , 메모리에서 일렬로 존재한다.
	puts(zus.first);   // 익명이라서 names 구조체 안 나옴. VS가 도와준다.
	return 0;
}
