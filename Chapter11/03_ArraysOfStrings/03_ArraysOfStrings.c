#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* Arrays of Character Strings */

	const char* mythings[5] = {
	"yahoo",
	"naver",
	"daum",
	"google",
	"amazon",
	};

	const char mythings2[5][40] = {
	"apple",
	"banana",
	"ok god",
	"computer",
	"siba jonsan",
	};

	const char* temp1 = "yahoo";
	const char* temp2 = "apple";

	printf("%s %u %u \n", mythings[0], (unsigned)mythings[0], (unsigned)temp1);
	printf("%s %u %u \n", mythings2[0], (unsigned)mythings2[0], (unsigned)temp2);
	/*
	mything2(이중 배열)의 경우 Literal(tmpe2)의 주소와 배열의 첫번째 원소(apple)의 주소가 다르다.
	이중 배열의 경우 stack에 배열로써 메모리를 가지고 있다. 즉 별도의 stack 메모리에 값들이 복사해서 들어가있다.
	반면 temp2의 경우 Text segment에 올라가있다.
	따라서 mything의 경우 text segment에 올라가있는 각 문자열의 포인터를 원소로 가지고 있다.
	*/
	printf("\n");

	printf("%-30s %-30s\n", "My things: ", "My things2: ");  // char 30칸까지 출력
	for (int i = 0; i < 5; ++i)
		printf("%-30s %-30s\n", mythings[i], mythings2[i]);

	printf("\nsizeof My things: %zd sizeof My things2: %zd ",sizeof(mythings), sizeof(mythings2));
	// sizeof는 당연히 다르겠쥬 mything의 경우 char포인터가 4바이트인데 5개 있어서 총 20
	// mything2의 경우 5*40 하면 200
	// 그래서 mything 처럼 사용하면 메모리를 아낄 수 있고, 프로그램에서 사용할 때도 복사를 1번만 하면 됩니다.
	// text-segment의 것만 가져오면 되니까요, 단점이 Reda only니까 수정할 수 없다.
	
	printf("\n");
	for (int i = 0; i < 100; ++i)
		printf("%c", mythings[0][i]);
	printf("\n");

	for (int i = 0; i < 200; ++i)
		printf("%d", mythings2[0][i]);  // format specifier %d로 ASCII출력
	printf("\n");

	for (int i = 0; i < 200; ++i)
		printf("%c", mythings2[0][i]);
	printf("\n");
	// Not a good idea to take advantage of this property
	// 실제 메모리에서 바로 옆 칸의 값을 계쏙출력하는 방식
	// 그냥 배열도 실제 메모리상 선형으로 붙어있다는 것을 보여준다. 실무에서 ㄴㄴ

	return 0;
}
