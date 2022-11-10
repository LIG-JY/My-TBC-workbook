#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12  // symbolic constant, macro



int main()
{
	/* Basic usage */
	int high[MONTHS] = { 1, 2, 3, 4, 5, 6, 7 ,8 ,9, 10, 11, 12 };  // 선언과 동시에 초기화, int 12개를 나열했다.

	for (int i = 0; i < MONTHS; ++i)
	{
		printf("%d\n", high[i]);  
	}

	// high[i]를 하나의 변수처럼 사용할 수 있습니다.
	high[5] = 1000;

	for (int i = 0; i < MONTHS; ++i)
	{
		printf("%d\n", high[i]);
	}
	/*
	high = { 1, 2, 3, 4, 1, 67, 7 ,8 ,9, 10, 11, 12 }; // 선언이 끝나고 다시 배열로 값을 넣을 수 없다.
	high[12] = { 1, 2, 3, 4, 1, 67, 7 ,8 ,9, 10, 11, 12 }; 
	*/
	

	/* Addresses */

	printf("%p %p\n", high, &high[0]);  // same address

	for (int i = 0; i < MONTHS; ++i)
	{
		printf("%lld\n", (long long) & high[i]);  // 10진수 정수로 바꾸기 위해서 long long 캐스팅
		// 출력했을 때 4바이트씩 변하는 것 확인하기
	}


	/* Compiler doesn't check whether indices are valid.*/ 
	/*
	high[12] = 4;  // error, 하지만 빌드는 됩니다. runtime 오류 발생
	high[-1] = 123; // error
	*/


	/* const and array */
	const int temp[3] = { 1, 2, 3 };  // 배열의 원소 값들을 바꿀 수 없다.
	/*temp[1] = 3; // error */


	/* When array is not initialized */
	int not_init[MONTHS];  // 선언만 하는 경우

	for (int i = 0; i < MONTHS; ++i)
	{
		printf("%d\n", not_init[i]);  // 값이 나오긴 하는데 모두 같게 이상한 숫자로 나옵니다.
	}

	//static int not_init[MONTHS];  // static을 사용하면 (static을  storage class라고 합니다.)

	//for (int i = 0; i < MONTHS; ++i)
	//{
	//	printf("%d\n", not_init[i]);  // 모두 0으로 초기화되서 나옵니다.
	//}

	/* Partially initialized */

	int insuff[4] = { 2, 4 };  // 부족하게 초기화

	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", insuff[i]);  // 나머지는 알아서 0으로 초기화되서 나옵니다.
	}


	/* Overlly initialized */
	/*int insuff[2] = { 2, 4 , 5, 6 };*/  // 과하게 초기화 -> 컴파일러가 오류를 잡아줍니다. 이니셜라이즈 값이 너무 많다고하네요


	/* Omitting size */
	const int power[] = { 2, 4 };  // 사이즈는 정해주지 않았지만 초기화하는 데이터는 있습니다. 하지만 컴파일러가 2로 맞게 사이즈를 정해줍니다.
	printf("%d\n", sizeof(power));  // 전체 배열의 사이즈를 구하는 방법, len과 다릅니다.
	printf("%d\n", sizeof(power[0])); // 배열의 원소의 자료형을 구하는 방법, 사이즈를 통해서 찾죠
	for (int i = 0; i < sizeof(power) / sizeof(power[0]); ++i)
	{
		printf("%d\n", power[i]); // 이런 방식은 동적할당에서 사용할 수 없습니다.
	}
	

	/* Designated initializers */
	int design[MONTHS] = { 2, 4, [4] = 5, 30, 5, [2] = 100};  // 강의 참조 신기함.


	/* Specifying Array sizes */

	int ex[MONTHS];  // 양의 정수면 됩니다.
	int ex2[12 * 3]; // 계산식도 됨
	float ex3[sizeof(int) - 1];
	float ex4[(int)2.5]; // 이런 것도 된다.

	return 0;
}
