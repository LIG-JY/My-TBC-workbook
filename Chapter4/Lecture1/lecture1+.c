#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char fruit_name[40]; 
	/*40 개의 char_type의 메모리 공간을 대표하는 하나의 주소*/

	printf("What is your favorite fruit?\n");

	scanf("%s", fruit_name); 
	
	/* string으로 변환, ampersand의 사라짐 
	왜냐하면 fruit_name이 이제 변수 명이 아니라 주소가 되었습니다. 위의 '대표하는 주소' 때문입니다. */ 

	/* 왜 ampersand를 사용하나요?
	scanf가 fruit_name memory공간에 입력받은 값을 넣어줍니다.
	따라서 fruit_name앞에 ampersand를 붙여서 주소로 변환해주는 것입니다.
	즉 컴퓨터는 furit_name이라는 char_type 변수의 메모리 주소에 값을 넣게 됩니다.*/

	printf("You like %s!\n", fruit_name); // '문자의 배열' string으로 바꿉니다.

	return 0;
}
