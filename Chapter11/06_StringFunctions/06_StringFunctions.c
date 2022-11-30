#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);
char* my_strncat(char*, char*, unsigned int);
int my_strcmp(char*, char*);

int main()
{
	///*
	//	strlen() : returns length of the string
	//*/
	//char msg[] = "Just, Do it!";
	//puts(msg);
	//printf("Length is %d\n", strlen(msg));  // Null character 빼고 12글자라서 12를 return
	//fit_str(msg, 4);
	//puts(msg);
	//printf("Length is %d\n", strlen(msg));


	///*
	//	strcat() and strncat() : string concatenation
	//*/
	/*char str1[100] = "First String.";
	char str2[] = "Second String.";*/
	//strcat(str1, "hahaha");
	//puts(str1);
	//strncat(str1, str2, 6);  // append 6 character;
	//puts(str1);
	// strncat(str2, str1, 5); -> Runtime error. 왜냐? str2는 배열의 크기를 비우고 초기화해서,
	// Second string.이라는 string의 크기에 맞춰져있다. 즉 char 15바이트 밖에 공간이 없다.
	/*my_strncat(str1, str2, 4);
	puts(str1);*/

	//TODO: implement my_strcat() function!

	///*
	//	strcmp() and strncmp() : compare strings (not characters)
	//*/
	//printf("%d\n", strcmp("A", "A"));  // 같으면 0
	//printf("%d\n", strcmp("A", "B"));  // 앞에 A가 ASCII코드가 더 작기 때문에 음수
	//printf("%d\n", strcmp("B", "A"));  // 반대로 B가 더 커서 양수
	//printf("%d\n", strcmp("shangus", "shangus"));
	//printf("%d\n", strcmp("urihyung", "urihyungg"));  // Nullcharacter은 0이고, 뒤의 g가 하나 더있기 때문에 더 크다. 음수
	//printf("%d\n", strncmp("bananas", "banana", 6));
	/*printf("\n %d", my_strcmp("noa", "no"));*/

	//TODO: implement strcmp!

	/*
		strcpy() and strncpy()
	*/
	char destination[100] = "";     // memory 충분히 확보
	char source[] = "Start Programming!";
	//destination = source; // error ->  이유?? 앞 강의 찾아보라는데;; 복습 ㄱㄱ
	//destination = "Start Programming!"; // error -> 컴파일러에서 한 글자씩 수정하도록 막아놓음
	//strcpy(destination, source);
	//puts(destination);
	//strncpy(destination, source, 5);  // '\0' is not add. 딱 5글자만 복사해서 Null character를 복사하지 않는다. programing 뒤에 있음.
	//puts(destination);  // (강의 참조)
	//strcpy(destination, source+6);
	//puts(destination);
	//strcpy(destination, source);
	//puts(destination);
	//strcpy(destination + 6,"Coding!"); // 6칸인 Start 까지 이동해서, Coding! 을 복사해서 더한다.
	//puts(destination);

	/*
		sprintf()
	*/

	char spt[100] = "";
	int i = 123;
	double d = 3.14;
	sprintf(spt, "%05d.png %f", i, d);  
	puts(spt);
	// 다른 자료형을 printf 출력하듯이 문자열로 만들어준다.
	// 파일 이름 만들 때 편하다.

	/*
		There are more functions...
	*/

	printf("%s\n", strchr("Hello World!", 'W'));
	/*주어진 chr로 시작하는 포인터를 return한다. 그리고 이 리턴값이 printf 의 %s로 출력해서 "World!"가 출력된다*/

	printf("%s\n", strpbrk("Hello World!", "ABCDE"));  
	printf("%s\n", strpbrk("Hello World!", "abcde"));
	/*주어진 control paramter 문자열 중 하나의 char로 시작하는 포인터를 return 한다.
	1 ) ABCDE 가 없으니 NULL
	2) e가 있네요. e의 주소를 담고 있는 포인터를 문자열로 출력한다.
	*/
	printf("%s\n", strrchr("Hello World! Hello World!", 'l'));  
	/*가장 마지막에 등장하는 char을 찾아서 포인터를 return
	따라서 ld! return
	*/

	printf("%s\n", strstr("Hello World!", "wor"));
	printf("%s\n", strstr("Hello World!", "Wor"));
	/*문자열 끼리 비교해서, 가장 첫번째로 substr과 일치하는 문자열에서 첫번째 포인터를 return 합니다.
	1) wor이랑 일치하는 문자열 없어서 NULL
	2) Wor이랑 일치하는 World! return
	*/




	return 0;
}

void fit_str(char* str, unsigned int size)
{
	if (strlen(str) > size)
	{
		str[size] = '\0';  // index로 바로 접근
	}	
	return;
}
char* my_strncat(char* str1, char* str2, unsigned int size)
{
	//char cat[10000];  // 일단 크게
	//const int maxsize = strlen(str1) + size;
	//int i = 0;
	//while (i < maxsize)
	//{
	//	if (i < strlen(str1))
	//		cat[i] = str1[i];
	//	else
	//		cat[i] = str2[i - strlen(str1)];
	//	i++;
	//}
	//i++;
	//cat[i] = '\0';
	/*return cat;*/
	while (*str1 != '\0')
	{
		str1++;
	}
	
	for (int count = 0; count < size; ++count)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return str1;
}

int my_strcmp(char* str1, char* str2) 
{
	while (*(str1) != '\0' || *(str2) != '\0')
	{
		if (*(str1) > *(str2))
			return 1;
		else if (*(str1) < *(str2))
			return -1;
		else
			str1++;
			str2++;
	}
	return 0;
}
