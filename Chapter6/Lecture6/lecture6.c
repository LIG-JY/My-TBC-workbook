#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>  // boolean을 미리 만들어놓은 헤더입니다.

int main()
{
	_Bool boolean_true = (2 > 1);
	_Bool boolean_False = (1 > 2); // _이 붙은 이유는 이미 bool같이 자료형을 만들어 사용하는 경우 많아서 충돌을 막기 위함입니다.

	printf("True is %d\n", boolean_true);
	printf("False is %d\n", boolean_False);

	printf(boolean_true ? "true" : "false"); // 3항 연산자
	printf("\n");
	printf(boolean_False ? "true" : "false"); // 3항 연산자
	
	bool bt = true;  // 미리 define해놓아서 보라색으로 표시됩니다. 키워드는 아닙니다.
	printf("True is %d\n", bt);


	return 0;
}

