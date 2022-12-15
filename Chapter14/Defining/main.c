#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41



struct person  // tag 구조체의 이름이라고 생각하면 된다. 변수명 짓는 규칙과 똑같이 적용된다.
{
	char name[MAX];  // member 선언만으로는 member는 메모리를 갖지 않는다.
	int age;  // memeber
	float height;  // memeber
};


int main()
{
	int flag;  // scanf의 value를 return 받기 위함.

	/* Structure variable */
	struct person naldo;  // 구조체 변수를 선언하는 순간, 구조체의 member가 메모리를 사용한다.

	/* dot(.) is structure membership operator (member access operator, member operator) */
	strcpy(naldo.name, "ChulSoo");
	printf("%s\n", naldo.name);
	naldo.age = 1000;

	// dot(.) has higher precedence than &
	flag = scanf("%f", &naldo.height);  // & 보다 .이 연산자 우선순위가 높다.
	printf("%f\n", naldo.height);

	/* Initialization */
	struct person messi = { "messi", 18, 170.0f };  // member 선언 순서와 값 초기화 순서가 동일해야한다.

	printf("%s\n", messi.name);
	printf("%f\n", messi.height);

	/*  Designated initializers */
	struct person king = {  
		.height = 170.0f,
		.age = 18, 
		.name = "messi",
	};  // 순서 안 지켜도 된다. designate!
	printf("king's age is %d\n", king.age);

	/* Pointer to a strcture variable */
	struct person* pointer;
	pointer = &king;


	/* Indirect member(ship) operator (or structure pointer operator) */

	pointer->age = 123;  // 포인터로 사용할 때는 . 대신에 ->
	printf("king's age is %d\n", king.age);  //  pointer로 king 구조체의 age를 변화시킨 결과 출력해서 확인해보자.
	printf("king's name is %s\n", (*pointer).name);  // indirection 연산자를 먼저 사용해도 괜찮다.

	/* Structure declarations in a function */
	// 구조체를 함수 block 안에서 지역변수처럼 사용할 수 있다.


	/* No tag */

	struct
	{
		char name[MAX];  
		int age;  
		float height;  
	} mario, princess;  // tag 없이 구조체 변수 바로 선언


	/* typedef and structure */

	typedef struct person my_person;  //  struct person 이라는 구조체를 my_person으로 임의로 타입처럼 지정한다.

	my_person pp1;

	typedef struct
	{
		char name[MAX];
		int age;
		float height;
	} my_person2;   // mario가 하나의 type처럼 된다. 

	my_person2 pp2;   // mario가 하나의 type처럼 된다. 

	return 0;
}
