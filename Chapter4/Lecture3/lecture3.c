#include <stdio.h>

int main()
{
	int a = 1;
	int int_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // 배열 초기화, 몇 개의 공간을 만들건지, 어떤 값을 넣을건지 결정

	printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]); //index의 개념

	// printf("%i\n", int_arr[999]); // index 범위 밖에 넣으면 오류

	char c = 'a';
	char str1[10] = "Hello"; // 문자열 배열 초기화, 최대 9글자까지 저장가능하다.null character까지 합치면 10개
	char str2[10] = { 'H', 'i' }; // 이렇게 curly bracket을 이용한 초기화도 가능하다.

	printf(" % c\n", c);
	printf(" % s\n", str1);
	printf(" % s\n", str2);

	printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]);

	//char str3[10] = "Hello world!"; // array size is not enough, 총 13글자
	char str3[20] = "Hello \0world!"; // Null character을 중간에 넣으면?
	printf(" % s\n", str3);
	printf("%hhi %hhi\n", str3[10], str3[11]);
	printf("%c %c\n", str3[10], str3[11]);


	return 0;
}
