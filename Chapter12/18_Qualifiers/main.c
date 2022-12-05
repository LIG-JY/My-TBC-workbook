#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// memcpy


//const double gravity = 9.8;
//const double PI = 3.141592;

int main()
{



	/*
		Qualified types
		const, volatile, restrict, _Atomic
	*/

	/*
		const
		<반드시 초기화를 해야한다. >
	*/

	// C99 ideompotent
	const const const int n = 6;  // 여러개 사용해도 "const int n = 6;" 과 동일합니다.

	typedef const int zip;  // const int를 새로운 type zip으로 정의한다.
	const zip q = 123; // const const int q -> 요런거 가능하게 하려고 const 여려번 쓸 수 있게 허용했다.


	/*
		Global constants
		<header file 만들어서, 변수에 static 선언하고 사용하기>
	*/

	/*
		volatile
		- Do not optimize
		- (ex: hardward clock)
		<휘발성>
	*/
	
	volatile int vi = 25;  // 컴파일러가 알 수 없는 이유에 의해서 값이 바뀔 수 있다. 따라서 컴파일러한태 최적화 하지 말라고 요청한다.


	/*
		restrict (__restrict in VS) 비쥬얼 스튜디오 특
		- sole initial means of accessing a data object
		- compiler can't check this restriction
		<데이터 오브젝트에 접근하는게 하나뿐이다. >
	*/

	int ar[5] = { 1, 2, 3, 4, 5 };
	int* par = ar;

	ar[0] += 3;
	par[0] += 5;
	// par[0] += 8; 컴파일러 입장에서 이렇게 최적화하고 싶지만, 다른 이름이라서 할 수 없다.

	int* __restrict restar = (int*)malloc(5 * sizeof(int));  // restar만 접근한다.
	if (!restar)
		exit(1);
	
	restar[0] += 3;
	restar[0] += 5;
	// restar[0] += 8; restrict한정자를 보고 컴파일러가 최적화할 수 있다. 하지만 컴파일러가 실제로 확인할 방법은 없다. 프로그래머를 믿는 것이다.
	return 0;
}
