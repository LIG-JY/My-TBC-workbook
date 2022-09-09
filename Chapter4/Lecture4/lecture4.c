#include <stdio.h>
#include <string.h> // strlen and more. strlen을 사용하기 위해 필요한 헤더
#include <stdlib.h>

int main()
{
	char str1[100] = "Hello";
	char str2[] = "Hello";
	char str3[100] = "\0";
	char str4[] = "\n";
	char str5[100] = " \0";

	printf("%zu %zu\n", sizeof(str1), strlen(str1));
	printf("%zu %zu\n", sizeof(str2), strlen(str2));
	printf("%zu %zu\n", sizeof(str3), strlen(str3));
	printf("%zu %zu\n", sizeof(str4), strlen(str4));
	printf("%zu %zu\n", sizeof(str5), strlen(str5));




	/* Extra 동적할당*/
	char *str6 = (char*)malloc(sizeof(char) * 100); 
	// sizeof(char)의 return값에 100을 곱한 만큼 메모리 공간을 할당합니다.
	// 이 메모리에는 char자료형이 들어갑니다
	// *str6은 이 메모리 주소의 포인터 변수입니다.
	str6[0] = 'H'; str6[1] = 'e'; str6[2] = 'l'; str6[3] = 'l'; str6[4] = '0'; 
	str6[5] = '\0';
	printf("%zu %zu\n", sizeof(str6), strlen(str6));

	return 0;
}
