#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>   // pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
	unsigned char i = to_decimal("01000110");
	unsigned char mask = to_decimal("00000101");

	print_binary(i);
	print_binary(mask);
	print_binary(i & mask);   // Bitwise "AND"


	/*
		Decimal to binary
			   Number     Mask         Mask
		2^7 : (01000110 & 10000000) != 10000000    print 0
		2^6 : (01000110 & 01000000) == 01000000    print 1
		2^5 : (01000110 & 00100000) != 00100000    print 0
		2^4 : (01000110 & 00010000) != 00010000    print 0
		2^3 : (01000110 & 00001000) != 00001000    print 0
		2^2 : (01000110 & 00000100) == 00000100    print 1
		2^1 : (01000110 & 00000010) == 00000010    print 1
		2^0 : (01000110 & 00000001) != 00000001    print 0
	*/

	return 0;
}

void print_binary(const unsigned char num)
{
	printf("Decimal\t%3d\t\t==\tBinary ", num);

	const size_t bits = sizeof(num) * 8;   // byte -> bit 화
	for (size_t i = 0; i < bits; i++)
	{
		const unsigned char mask = (unsigned char)pow(2, (bits - i - 1));

		if ((num & mask) == mask)    //  target 자리의 수가 1이면
			printf("%d", 1);
		else
			printf("%d", 0); 

	}
	printf("\t @@ \n");
}

unsigned char to_decimal(const char bi[])
{
	unsigned char answer = 0;
	for (int i = strlen(bi)-1; i >= 0; i--)
	{
		if (bi[i] == '1')
		{
			answer += pow(2, strlen(bi) - i - 1);
		}
	}
	return answer;
}
