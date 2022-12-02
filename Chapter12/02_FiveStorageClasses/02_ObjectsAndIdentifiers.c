#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
		Object
		- "An object is simply a block of memory that can store a value." (KNK p. 487)
		- Object has more develped meaning in C++ and Object Oriented Programming (OOP)
		Identifiers
		- Names for variables, functions, macros, and other entities. (KNK p. 25)
	*/
	int var_name = 3;
	/*변수의 이름(Identifier)을 통해서 메모리 공간(object)에 접근할 수 있다.
	C언어가 object에 직접 사용하도록 도와준다.
	참고로 Assembly에서는 object의 주소에 직접 접근을 하게된다.
	*/
	int* pt = &var_name;  // pt is identifier
	*pt = 1;  // *pt -> expression(표현식) *pt designate(지목) an object. (Indirection을 풀어쓴 말)

	int arr[100];  // arr is an identifier. (이름은 이름이니까)
	// arr은 첫번째 element에 대한 주소다..!!! 따라서 그 자체가 메모리 공간을 갖는 object는 아니다.
	arr[0] = 7; // arr[0]은 Expression, 이 표현식을 통해서 object에 접근할 수 있다. 0번 index가 가리키는 메모리 공간은 obejct다.

	/*
		lvalue is an expression 'referring' to an object. (K&R p.197)
		L-value : left side of an assignment
		R-value : right side, variable, constant, expressions (KNK p. 67)
	*/


	int left_value = 3;  // modifiable lvalue
	/*left_value가 가리키는(reference) 메모리 공간(object)에 3이라는 value를 복사해 넣는다.*/
	int *left_pt = &left_value;  // 포인터 또한 어떤 값(주소)를 가지고 있는 메모리 공간을 referring하기 때문에 lvalue이다.
	*left_pt = 5;  // *left_pt is not an identifier, but a modifiable lvalue expression (object의 값을 바꿀 수 있다.)

	int* ptr = arr + 2 * left_value;  
	//  address rvlaue (arr이 배열의 이름이다. 따라서 주소이다.) 여기에 left_value의 값으로 연산을 해준다.
	*(arr + 2 * left_value) = 456;  // lvalue expression (주소에 indirection 했으니까 Expression) 이를 통해서 이 주소의 object에 456이라는 값을 복사한다. 따라서 lvalue

	const char* str = "Constant string";  // str is a modifiable lvalue
	str = "Constant stringConstant string";  // 다른 string으로 교체가 가능하다. "Constant string"은 값(literal)이다. Rvalue -> datasegment 영역(메모리 레이아웃 강의 참조)
	printf("%s", str);
	// str[0] = 'A'; -> ERROR (data segment 영역 Read Only) 
	// const를 써주는 이유? 
	// 11.1강 9분 50초경 참조. const를 빼고 빌드해서 문자열을 수정하는 코드를 실행하면(컴파일러가 바로 에러를 잡아주지 못함),
	// Runtime Error발생. 이런 실수를 막기위해서 const를 붙여준다.(권장사항)

	char str2[] = "String is an array";  // 메모리 레이아웃 단원 참고, Heap 메모리 공간에 올라갑니다. str2라는 identifier로 특정한 메모리 obejct를 referring 하고 있다.
	str2[0] = 'A'; // OK

	/*
		<다음 강의에서 이어지는 내용>
		Identifiers have scope.
		Objects have storage duration.
		Variables and functions have one of the following linkages:
			external linkage, internal linkage, or no linkage.
	*/

	return 0;
}
