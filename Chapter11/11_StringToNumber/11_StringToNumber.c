#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	/*
		string to integer, double, long
		atoi(), atof(), atol()
	*/

	/*Example 1*/
	//if (argc < 3)
	//{
	//	printf("Wrong Usage of %s\n", argv[0]);  // 명령줄인수 argv[0] -> 실행파일의 이름
	//}
	//else
	//{
	//	int time = atoi(argv[1]); // 문자를 숫자로, 2번째 명령줄인수 횟수만큼

	//	for (int i = 0; i < time; ++i)
	//	{
	//		puts(argv[2])  // 3번째 명령줄인수 출력
	//	}
	//}

	/*Example2*/

	/*printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));*/

	/*
		string to long, unsigned long, double
		strtol(), strtoul(), strtod()
		strtod() converts base 10 only
		strtol(), strtoul() -> Base 여러가지 사용가능
	*/

	char str1[] = "-1024Hello";
	char* end;
	unsigned long l = strtoul(str1, &end, 10);  
	// End pointer을 왜 사용할까? 숫자가 아닌 부분의 시작문자의 포인터 따라서 -1024말고 Hello 문자열이다.
	printf("%s %ld %s %d\n", str1 , l, end, (int)*end);
	// 대문자 H는 72 ASCII 코드

	char str2[] = "10FFHello";
	// 16진수 10FF -> 10진수로 4351
	long m = strtol(str2, &end, 16);
	printf("%s %ld %s %d\n", str2, m, end, (int)*end);

	/*
		Numbers to strings
		Use sprintf() instead of itoa(), ftoa()
	*/

	char temp[100];
	puts(_itoa(10, temp, 16));  // 10을 16진수로 즉 a로 출력합니다.
	// 표준에서 사용권장 X

	sprintf(temp, "%x", 10);  // 10을 16진수로 즉 a로 출력합니다.
	puts(temp);

	return 0;
}
