#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

char* custom_string_input(char* st, int n)
{
	char* ret_ptr;
	int i = 0;

	ret_ptr = fgets(st, n, stdin);
	if (ret_ptr)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar != '\n')  // clear buffer Ex) adfsd\n -> adfsd
				continue;
	}
	return ret_ptr;
}

int main()
{
	/* Creating Space */
	/*char* name = ""; */ // 공간이 부족해서 Runtime Error 발생
	char name[250];
	int result = scanf("%s", name);  // name이 어차피 포인터변수 or 배열의 이름(포인터)이기 때문에 빈 공간의 주소를 가지고 있다.


	/*
		scanf() vs gets()
		scanf() reads one word -> 띄어쓰기 못 읽는다.
		gets() reads one line and removes \n and add \0
		입력받을 때 엔터를 치는 순간 버퍼에서 입력받은 것을 불러온다. 이 때 마지막 엔터를 없애고
		\0을 추가한다.
	*/

	char words[STRLEN];
	gets(words); // 입력 , 포인터를 입력받는다. gets()입장에서 포인터만 입력받기 때문에, 자기가 사용할 수 있는 메모리 크기를 모른다.
	// 단지 메모리가 시작을 어디서 부터하는지만 안다. 이런 점을 보완하기 위해서 등장한게 gets_s()
	// gets_s(words, sizeof(words));
	printf("Start\n");
	printf("printf print %s\n", words);
	puts(words);  // puts() add \n at the end -> puts()는 자동으로 끝에 \n을 넣어줍니다.
	puts("End.");

	/* 입력받을 때 입력받을 메모리 크기를 정의한다.
	실제로 사용자가 입력할 때 메모리의 크기를 초과해서 입력한다면 Runtime Error가 발생한다.
	이를 극복하기 위해서 나온게 fgets(), fputs()*/

	///* fgets() and fputs() */
	char fwords[STRLEN] = "";  // f는 file을 의미한다. 원래는 file입축력 용도의 함수이다.
	fgets(fwords, STRLEN, stdin);  // stdin 인자를 넣으면 콘솔에서 입력가능하다
	//fgets함수는 \n을 제거하지 않는다. file입출력에서는 엔터까지 그대로 입력받는게 편리하기 때문이다.

   ///*개행문자('Wn')을 제거하기 위한 코드가 아래에 있다.*/

	int i = 0;
	while ((int)fwords[i] != '\n' && (int)fwords[i] != '\0')  // 문자열의 끝 '\0'이나 개행문자 '\n'을 만나면
	{
		i++;
	}
	if ((int)fwords[i] == '\n')
	{
		fwords[i] = '\0';
	}

	fputs(fwords, stdout);  // does not add \n 다음줄 자동으로 해주는 기능 없음
	fputs("\nEND", stdout);

	/* Small array */

	char small_array[5];
	puts("Enter long strings:");
	fgets(small_array, 5, stdin);
	fputs(small_array, stdout);
	printf("\n");
	/* EOF -> Control + Z 누르면 파일의 끝이라는 것을 입력할 수 있다. fgets()에 입력하면 return으로 Null*/
	printf("%p\n", small_array);  // Small array의 주소값
	printf("%p\n", fgets(small_array, 5, stdin));  // 이 상황에서 small array에 5바이트가 넘는 입력을 했을 때 과연 return값의 주소는?


	///* Repeating short reading */
	char peice[5];
	puts("Enter long strings:");
	while (fgets(peice, 5, stdin) != NULL && peice[0] != '\n')
		fputs(peice, stdout);  // buffer 때문에 쭉 이어서 출력이 가능하다.



	///* scanf() */
	char str1[6], str2[6];
	//int count = scanf("%5s %5s", str1, str2);  // 5글자씩 딱딱 넣는다. Null charater 빼면 5글자
	//int count = scanf("%6s %6s", str1, str2);  // 6글자씩 넣으면 Runtime Error
	int count = scanf_s("%5s %5s", str1, 6, str2, 6);  // max size를 추가할 수 있다. Null charater 빼면 5글자
	printf("%s|%s \n", str1, str2);
	// scanf_S 할 때 정의한 문자열의 크기에 맞게 해야함


	/* an example of custom input function */
	char st[STRLEN];
	char* ptr = custom_string_input(st, STRLEN);   // return 이 char type pointer 이기 때문에 char type pointer에 대입한다.
	puts(ptr);


	return 0;
}
