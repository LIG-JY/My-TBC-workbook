#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>		// islower()
#include <stdbool.h>
#include <iso646.h>		// and, or, not

#define PERIOD '.'

int main()
{
	/*	
		Logical operators 
		
		&& : and
		|| : or
		!  : not
	*/

	bool test1 = 3 > 2 || 5 > 6; // true
	bool test2 = 3 > 2 && 5 > 6; // false, 하나라도 false면 false
	bool test3 = !(5 > 6); // true, equivalent to 5 <= 6


	/* Character counting example */
	char ch;
	int count = 0;
	while ((ch = getchar() != PERIOD))  // . 찍으면 
	{
		if (ch != '\n' && ch != ' ')  // 줄바꿈과 공백은 세지 않는다.
		{
			count++;
		}
	}
	printf("%d", count);


	/*
		Alternatives in  
		&&	: and
		||	: or
		!	: not
	*/
	// and, or ,not을 쓸 수 있습니당. iso646 헤더를 불러오면 됩니다.

	/* 
		Precedence 
	
		Check !, &&, !! in the operator precedence table
		https://en.cppreference.com/w/c/language/operator_precedence
	*/


	/*
		Short-circuit Evaluation
		- Logical expressions are evaluated from left to right
			
	*/

	int temp = (1 + 2) * (3 + 4);  // 논리연산자는 왼쪽에서 옆으로 계산합니다.


	/* Ranges */ // 주의할 점!!
	for (int i = 0; i < 100; i++)
		if (i >= 10 && i <= 20)
			printf("%d", i);

	printf("\n")

	for (int i = 0; i < 100; i++)
		if (10 <= i <= 20)  
			printf("%d", i);

	return 0;
}
