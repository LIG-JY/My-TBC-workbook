#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char fruit_name; // stores only one character

	printf("What is your favorite fruit?"\n);

	scanf("%c", &fruit_name); // becareful with &(ampersand)

	/* 왜 ampersand를 사용하나요? 
	scanf가 fruit_name memory공간에 입력받은 값을 넣어줍니다.
	따라서 fruit_name앞에 ampersand를 붙여서 주소로 변환해주는 것입니다.
	즉 컴퓨터는 furit_name이라는 char_type 변수의 메모리 주소에 값을 넣게 됩니다.*/

	printf("You like %c!\n", fruit_name);

	return 0;
}