#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
		Well aligned structure
	*/
	struct aligned
	{
		int a;
		float b;
		double c;
	};

	/*
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
	|int a  |float b|double c             |
	4 + 4 + 8 = 16
	*/

	struct aligned a1, a2;
	printf("struct aligned a1\n");
	printf("Sizeof %zd\n", sizeof(struct aligned));
	printf("%lld\n", (long long)&a1);
	printf("%lld\n", (long long)&a1.a);
	printf("%lld\n", (long long)&a1.b);
	printf("%lld\n", (long long)&a1.c);

	printf("struct aligned a2\n");
	printf("Sizeof %zd\n", sizeof(a2));
	printf("%lld\n", (long long)&a2);
	printf("%lld\n", (long long)&a2.a);
	printf("%lld\n", (long long)&a2.b);
	printf("%lld\n", (long long)&a2.c);


	/*
		padding (struct member alignment)
		- 1 word: 4 bytes in x86, 8 bytes in x64
		word는 데이터를 묶어서 전송(메모리와 CPU가 데이터를 주고받을 때)하는 단위를 말한다. 
	*/

	struct Padded1
	{
		char a;
		float b;
		double c;
	};

	/* Without padding (예상)
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|a|float b|double c          | ?  ?  ?
	1 + 4 + 8 = 13
	*/

	/* With padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|char a |float b|double c             |
	4(char?) + 4 + 8 = 16
	컴파일러가 char에 빈공간 3byte를 넣는다. padding을 넣어준다.
	word의 단위에 맞춰서 보내면 효율적이기 때문에 4의 배수로 구조체의 size를 만들기 위해서 padding을 넣어주네요.
	*/

	struct Padded1 p1;

	printf("struct aligned p1\n");
	printf("Sizeof %zd\n", sizeof(p1));
	printf("%lld\n", (long long)&p1);
	printf("%lld\n", (long long)&p1.a);
	printf("%lld\n", (long long)&p1.b);
	printf("%lld\n", (long long)&p1.c);

	/*
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	|float a        | double b            | char c                |
	8(float?) + 8 + 8(char?) = 24
	double을 한 word에 통채로 넣기 위해서 이렇게 된다고 하네요...
	*/

	struct Padded2
	{
		float a;
		double b;
		char c;
	};

	struct Padded1 p2;

	printf("struct aligned p2\n");
	printf("Sizeof %zd\n", sizeof(p2));
	printf("%lld\n", (long long)&p2);
	printf("%lld\n", (long long)&p2.a);
	printf("%lld\n", (long long)&p2.b);
	printf("%lld\n", (long long)&p2.c);

	/* p1 과 p2를 비교해서 memeber의 순서에 따라 padding이 달라진다.
	이에 따라 메모리의 효율적 사용이 결정된다.*/


	/*
	|f[0].name        | f[0].age | f[0].height | ... ... |f[3].name        | f[3].age | f[3].height |
	*/

	struct arraypd
	{
		char name[41];
		int age;
		float height;
	};

	struct arraypd person;

	printf("struct aligned person\n");
	printf("Sizeof %zd\n", sizeof(person));
	printf("%lld\n", (long long)&person);  // 구조체의 주소랑 구조체의 첫번째 맴버의 주소가 같죠? 
	printf("%lld\n", (long long)&person.name[0]);   // name[0]이나 배열의 이름의 주소나 같죠?
	printf("%lld\n", (long long)&person.name);
	printf("%lld\n", (long long)&person.age);
	printf("%lld\n", (long long)&person.height);
	// 41 + 4 + 4?
	// 44 + 4 + 4
	return 0;
}
