#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MESSEGE "A symbolic string contant"
#define MAXLENGTH 81  // Symbolic constant

int main()
{
	char words[MAXLENGTH] = "A string is an array";
	const char* pt1 = "A pointer to a string.";  // 문자열이 저장된 긴 메모리 공간의 첫번째 주소를 담는 포인터
	/*위의 두 코드의 차이를 확인해본다. 첫번째 char의 배열로 선언하는 경우 words라는 자기의 메모리가 존재한다.
	하지만 두번째 코드의 경우 '어딘가'에 저장되어있는 문자열의 첫번째 주소를 가리키게 된다.*/

	puts("Puts() adds a newline at the end:");  // puts() add \n at the end
	puts(MESSEGE);
	puts(words);
	puts(pt1);

	words[3] = 'p';  // 배열이라서 교체가 정상적으로 작동합니다.
	puts(words);
	/*char* pt1 = "A pointer to a string.";*/
	/*pt1[3] = 'h';*/  // 수정할 수 없는 lvalue, 교체할 수 없다. const 때문입니다. 하지만 cosnt를 땐다면?

	char greeting[50] = "Hello" "kcoW" "yeah";  // 중간에 따옴표 넣어도 따옴표 다 생략해서 출력됩니다.
	puts(greeting);
	printf("\" To be, or not to be\" Hamlet said.\n");   // 겹따옴표 자체를 출력할 때는 escape sequence

	printf("%s, %p, %c\n", "WE", "ARE", *"excellent programming");
	// 1) prtinf에서 %s는 문자열의 format specifier이다.
	// 2) printf에서 %p는 문자열에서 첫번째 char(문자)의 주소를 가리킨다. A의 첫번재 주소를 담고 있다.
	// 3) excellent~~~ 라는 문자열에서 첫번째 char(문자)e의 주소를 가리킨다. e의 주소에서 redirection하면 e가 나온다.

	const char m1[15] = "Love you!";
	for (int i = 0; i < 15; ++i)
	{
		printf("%d ", (int)m1[i]);  // Note the null character
	}
	printf("\n");

	const char m2[15] = { 'L','o','v','e','y','o','u','!','\0' };
	for (int i = 0; i < 15; ++i)
	{
		printf("%d ", (int)m2[i]);  // Note the null character, 마지막에 Null character 빼도 컴파일러가 잘 넣어줍니다.
	}
	printf("\n");

	const char m3[] = "Love you, too!";
	for (int i = 0; i < 15; ++i)
	{
		printf("%d ", (int)m3[i]);  // Note the null character
	}
	printf("\n");

	char cookies[2 * sizeof(int)] = { 'A', };
	puts(cookies);  // Null character 출력 X
	for (int i = 0; i < 2 * sizeof(int); ++i)
	{
		printf("%d ", (int)cookies[i]);  // Note the null character
	}
	printf("\n");
	
	char truth[10] = "Truths is ";
	if (truth == &truth[0]) puts("true!");   // 배열의 이름은 포인터다. 첫번째 원소의 가장 첫번째 주소를 담고 있다.
	if (*truth == 'T') puts("true!");  // 배열의 이름이 포인터이기 때문에 indirection이 가능하다. 첫번째 원소를 찾아간다.
	if (*(truth + 1) == truth[1]) puts("true!"); // 배열의 이름이 포인터이기 때문에, 포인터는 연산이 가능하다. 인덱스 한 칸씩 이동하는 것과 똑같다.
	if (truth[1] == 'r') puts("true!"); // 배열의 이름에서 subscripting 기능을 사용했다. 배열의 성질

	return 0;
}
