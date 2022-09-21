#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
	while (expression) expression이 true값으로 판명이되면, 즉 컴퓨터 내부에서 1이면 아래의 statment를 실행합니다.
		statement
	*/


	/* Common mistakes */
	int i;
	while (i++ < 3); // while에 ;붙이는 실수 ㄴㄴ
	printf("%d", i);



	return 0;
}
