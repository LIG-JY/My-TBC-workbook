#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	for (int n = 1, nsqr = n * n; n < 10; n++, nsqr = n * n) // expression 하나에서 콤마 연산자를 통해서 for문을 유연하게 사용할 수 있습니다.
	// for (int n = 1, double nsqr = n * n; n < 10; n++, nsqr = n * n)  -> 이렇게 다른 자료형의 변수를 콤마 연산자와 사용할 수는 없습니다.

	//Note that commas in printf() are not comma operators 
	//but separators
	printf("%d %d\n", n, nsqr);
	/* 여기서는 콤마 연산자가 아니라 seperator입니다. 각 변수(인자)를 구분지어 줍니다. */

	int i, j;
	i = 1;
	i++, j = i;  
/* comma is a sequence point -> 콤마 연산자는 statement를 끝내는 ;처럼 sequence point라고 합니다. 
	 이 sequence point를 만나면 앞에서 만나는 계산값들을 계산하게 됩니다. 
	 위의 식에서는 콤마를 만났기 때문에 후위연산자이지만 i++가 계산되고 i에 2가 대입되고, 다음에 j에 i를 대입하고 ;로 statement를 종료합니다. */

	int x, y, z;
	z = x = 1, y = 2;
	printf("x=%d y=%d z=%d\n", x, y, z);
	/*  대입연산자는 Associativity가 오른쪽에서 왼쪽입니다.
		콤마 연산자는 Associativity가 왼쪽에서 오른쪽입니다.
		따라서 우선 콤마의 왼쪽이 계산됩니다. 따라서 대입연산자를 계산하게 되고 대입연산자의 Associativity에 따라서 x = 1로 x에 1이 대입되고
		z에 x의 값이 대입됩니다. 콤마 연산자의 Associativity에 따라 y = 2가 대입됩니다. 
	*/
	z = (x = 1), (y = 2);
	printf("x=%d y=%d z=%d\n", x, y, z);
	/*
		위와 연산 순서 동일합니다.
	*/
	z = ((x = 1), (y = 2));
	printf("x=%d y=%d z=%d\n", x, y, z);
	/*
		콤마 연산자는 가장 오른쪽의 값이 전체 Expression의 값이 됩니다.
		따라서 가장 우선 순위가 빠른 괄호부터 계산을 해서 x = 1을 대입하고, y = 2를 대입한 후 
		분홍색 괄호의 Expression 값은 y = 2(가장 오른쪽 값)이기 때문에 2가 z에 대입이 됩니다.
	*/
	
	
	//int my_money = 123,456; // error 이렇게 사용할 수는 없습니다.
	int my_money = (123, 456); // 오른쪽 값인 456이 대입됩니다.
	
	return 0;
}
