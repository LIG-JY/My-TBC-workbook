#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TEST "A string from #define."

void custom_put(const char* str);
int custom_put2(const char* str);

int main()
{

	/*
		puts() : add \n at the end
	*/
	char str[60] = "String array initialized";
	const char* ptr = "A pointer initialized";

	puts("String with out \\n");
	puts("End");
	puts(TEST);
	puts(TEST + 5);
	puts(&str[3]);  // puts(str[3]); -> Error
	puts(ptr + 3);

	/* puts()가 문자열의 포인터(주소값)를 인자로 받는 것을 확인할 수 있다.*/

	/*
		string without \0
	*/

	char aloha[] = { 'h', 'i', '!' };  // No \0 at the end.
	/*겹따옴푤르 이용해서 문자열을 초기화하면 Null character \0이 자동으로 초기화된다.
	배열로써 각각의 문자들을 집어넣으면 강제로 \0을 초기화하지 않을 수 있다.
	hi!儆儆儆儆?{? 처럼 이상한 값이 나오는데, 우연히 메모리에 존재하는 Null character을 만날 때
	까지 출력을 진행하는 것으로 알 면 된다.*/
	puts(aloha);

	/*
		puts() and fputs()
	*/


	char line[100];
	while (gets(line))  // while gets(line) != NULL;
		puts(line);

	char fline[100];
	while (fgets(fline, 100, stdin))
		fputs(fline, stdout);

	/*
		printf()
	*/

	char pf[] = "Just do it ronaldo";
	puts(pf);
	printf("%s\n", pf);  // \n을 인위적으로 추가해줘야합니다.
	puts("hi");

	char input[100];
	int ret = scanf("%10s", input); // EX) input: Hey mejot! zza
	printf("%s\n", input);  // Hey
	ret = scanf("%10s", input);  // buffer에 남아있는 Hey mejot! zza
	printf("%s\n", input);  // mejot! 출력
	/*Scanf의 장점: 여러 자료형을 입력받기에 편하다.
	단점: 띄워쓰기 seperator을 기준으로 읽는다. buffer에 입력을 모두 담아두고
	띄워쓰기를 기준으로 읽는다. 사실 format specifier에서 10글자는 의미가 없다.*/


	/*
		Custom function
	*/
	char pig[100] = "mY king ronaldo! King God Doo!";
	custom_put(pig);  // 문자열(배열)의 이름은 포인터와 유사하다.

	printf("\n");
	int result = custom_put2(pig);
	printf("\n%d", result);   // 이거 개수 세보면 Nullcharacter 포함 안 되구 순수 글자 수 나옴

	return 0;
}

/*
	puts() which doesn't add a new line at the end
	Use pointer increment operator and putchar()
*/

	void custom_put(const char* str)
	{
		for (int i = 0; *(str + i) != '\0'; ++i)   // 조건문에 Null character을 써야한다. \n 쓰면 쓰레기값 출력!!
			putchar(*(str + i));

		/* 교수님 풀이
		while (*str != '\0') //while(*str)
[O			putchar(*str++);
		*/
	}

	int custom_put2(const char* str)
	{
		int count = 0;
		for (int i = 0; *(str + i) != '\0'; ++i)
		{
			count++;
			putchar(*(str + i));
		}
		return count;
	}
