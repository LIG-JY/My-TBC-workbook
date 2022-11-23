#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// type qualifiers: const, volatile, ...  -> 한국어로 한정자라고 합니다. 자격을 바꾸어준다. 한정해준다. 
	// const는 기본적으로 변수를 상수로 바꿔주는 역할을 합니다.
	// const double PI = 3.14159;
	// PI = 2.14159;
	// // 오류가 나옵니다. note: variable 'PI' declared const here

	// const int arr[5] = { 1, 2, 3, 4, 5};
	// arr[1] = 123;
	
	const double arr2[3] = { 1.0, 2.0, 3.0};
	arr2[0] = 100.0;
	// 배열의 각각 원소의 값을 바꿀 수 없게 된다.

	double* pd = arr2;
	*pd = 3.0;  
	// dereferencing 해서 3이라는 값을 넣게 됩니다. pd[0] = 3.0; , arr[0] = 3.0; 과 동일하다.
	pd[2] = 1024.0;
	// arr2[2] = 1024.0; 과 동일하다. 배열은 포인터다. pd를 arr(배열의 이름)과 동일하다고 생각하면 덜 헷갈립니다. 
	printf("%f %f", pd[2], arr2[2]);
	// warning: initializing 'double *' with an expression of type 'const double[3]' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
	// 원래 arr2는 const 배열인데, const가 아닌 pointer 변수를 새로 정의해서 값을 바꿔서 경고가 나오고, VScode에서는 오류가 발생합니다.

	// const double* pd = arr2;
	// pd++;  // allowed -> 포인터가 배열에서 한 칸씩 이동하는 연산 따라서 이동하고 2.0을 가리키는데 여기서 또 [2]로 2칸 더 가서 출력하니 이상한 값이 출력됩니다.
	// printf("%f %f", pd[2], arr2[2]);
	// 따라서 실수하기 좋죠. 이런 것을 막으려면 -> const double* const pd = arr2 이런식으로 포인터 변수 앞에도 const를 붙여주면 됩니다.

	return 0;
}
