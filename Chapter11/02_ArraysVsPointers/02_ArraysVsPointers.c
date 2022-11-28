#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// malloc

void test_function()
{
	int j;
	printf("Stack high \t%llu \n", (unsigned long long) & j);
}

int main()
{
	/* Array Versus Pointer */
	const char* pt2 = "I am a string.";
	const char* pt3 = "I am a string.";
	const char* pt4 = "I am a string!!!";
	const char ar1[] = "I am a string.";
	const char ar2[] = "I am a string.";
	const char ar3[] = "I am a string!!!";

	printf("rodata(read only data) low \t%llu %llu %llu %llu\n", (unsigned long long) pt2,
		(unsigned long long) pt3, (unsigned long long) pt4,
		(unsigned long long) "I am a string.");

	printf("Stack high \t%llu %llu %llu \n", (unsigned long long) ar1,
		(unsigned long long) ar2, (unsigned long long) ar3);

	// 위의 출력문에서 stack과 rodat의 주소 배치를 각각 확인해야함. 각각 분류끼리 가까운 주소를 사용한다.
	// 첫번째 printf문에서 pt2, pt3은 같은 rodata의 주소를 담고 있습니다. 그리고 "I am a string."을 직접 출력할 때도 같은 값이 나옵니다.
	// >>> 이유 질문?
	// 두번째 prinf문에서 배열은 각각 메모리를 확보하고 있기 때문에 주소가 다르다.

	/* Memory address check */



	/* Local variables */
	printf("Stack high \t%llu %llu %llu \n", (unsigned long long) &pt2,
		(unsigned long long) & pt3, (unsigned long long) & pt4);
	/*포인터 변수도 변수니까 주소를 가진다.
	스택에 올라갑니다. 지역변수*/
	int i;
	printf("Stack high \t%llu \n", (unsigned long long) & i);
	// i도 초기화되지 않았지만, 지역변수이고 스택에 올라갑니다.


	/* Local variable in a function*/
	test_function();

	/* Dynamic allocation */
	char* p5 = (char*)malloc(sizeof(char) * 100);
	printf("heap middle \t%llu \n", (unsigned long long) p5);

	char* p6 = (char*)malloc(sizeof(char) * 100);
	printf("heap middle \t%llu \n", (unsigned long long) p6);
	// 동적할당은 크기를 예상할 수 없으니까 heap으로 stack과 비교해서 생각하자.

	/* Array Versus Pointer (continued) */

	//ar1++; // error; 배열의 이름과 포인터의 차이점을 알 수 있다. 배열의 이름에 증감연산자 사용불가
	pt2++; // 포인터는 증감연산자를 사용할 수 있다.
	puts(pt2); // "I am a string."에서 증감연산자 때문에 한칸 이동해서  " am a string."이 출력된다.

	/* Array and Pointer Differences */
	char heart[] = "I love kelly";
	const char* head = "I love kelly";

	for (int i = 0; i < 6; ++i)
	{
		putchar(heart[i]);
	}
	printf("\n");

	for (int i = 0; i < 6; ++i)
	{
		putchar(head[i]);
	}
	printf("\n");

	// pointer addition
	for (int i = 0; i < 6; ++i)
		putchar((*(heart + i)));
	printf("\n");

	for (int i = 0; i < 6; ++i)
		putchar((*(head + i)));
	printf("\n");

	/*문자열 전부를 출력하는 코드*/
	while (*(head) != '\0')  // 포인터로 indirection 했을 때 Nullchar이면 문자가 끝이니 종료
	{
		putchar(*(head++));  // 포인터 이동
	}

	head = heart; // ok, 포인터가 가리키는 주소를 변경, 배열의 이름은 포인터와 호완된다.
	// heart = head; 반대로는 안 된다.

	// Cannot change heart. Can change the elements of heart
	heart[7] = 'H';  // 배열의 이름은 바꿀 수 없다. 증감연산자를 사용할 수 없듯이.
	*(heart + 7) = 'K';  // 배열의 이름이 포인터 변수와 호완이 되기 때문에 산술연산이 가능하다.

	putchar('\n');

	char* word = "Google";
	/*word[2] = 'k';*/  // Runtime error, 포인터가 가리키는 literal은data segment에 있다. 따라서 X
	// const char* word = "Google"; 을 권합니다. C언어 refernecing

	const char* str1 = "a Whole new world";
	const char* copy;

	copy = str1;  // 포인터의 주소를 복사했다. data segment의 문자열의 주소만 복사했다.

	printf("%s %p %p\n", str1, str1, &str1);
	printf("%s %p %p\n", copy, copy, &copy);
	// 첫번째는 버퍼로 printf에서 문자열 출력, 두번째는 str1, copy라는 포인터 변수가 담고있는 주소값 (data segment에 올라간 주소)
	// 세번째는 이 포인터 변수의 주소값, Stack에 올라갑니다.
	// 2개의 출력문이 동일함을 인지하자. 얕은 복사	

	return 0;
}

