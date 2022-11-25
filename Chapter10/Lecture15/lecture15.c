
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	///* Pointer Compatibility */
	///*그냥 int와 double은 호완이 되지만, 포인터의 경우 호완이 되지 않는다.*/
	//int n = 5;
	//double x;
	//x = n;  // promotion
	//int* p1 = &n;
	//double* pd = &x;
	//pd = p1; // warning -> compatible type warning C4133: '=': 'int *'과(와) 'double *' 사이의 형식이 호환되지 않습니다.
	///*결론은 웬만하면 포인터끼리 캐스팅 할 건덕지를 만들지 맙시다.*/

	//int* pt;
	//int (*pa)[3];  // 원소가 3개인 어떤 배열에 대한 포인터
	//int arr1[2][3] = { 3, };
	//int arr2[3][2] = { 7, };
	//int** p2;  // 포인터를 가리키는 포인터 즉 2중 포인터

	//pt = &arr1[0][0];  // 2중 배열의 원소의 주소를 가리킬 수 있다.
	//for (int i=0; i < 6; ++i)
	//{
	//	printf("%d ", *(pt+i));
	//}
	//pt = &arr1[0][0];  

	//pt = arr1[0];
	//// arr1[0]은 int 3개를 담고있는 배열이다. 배열의 이름은 포인터와 같이, int 3개중 첫번째 int의 주소를 담고 있다.
	//// pt는 int 자료형의 주소를 담을 수 있는 포인터이다. arr1[0]의 첫번째 int형 원소의 주소를 담는다. 


	///*pt = arr1; */ // warning -> 포인터 변수에 2차원 배열은 담을 수 없다.

	//pa = arr1;  
	//// pa는 원소가 3개짜리인 배열의 주소를 담는 포인터이다. arr1은 원소가 3개짜리인 배열 2개를 원소로 가지는 배열이다.
	//// 따라서 배열의 이름도 포인터이기 때문에,  arr1은 첫번째 원소인 원소가 3개짜리 배열의 주소를 가리키고 있다.
	//// 이 주소를 pa라는 포인터 변수가 그대로 담는다.

	//pa = arr2;  // warning
	//// pa는 원소가 3개짜리인 배열의 주소를 담는 포인터이다. arr2는 원소가 2개짜리인 배열 3개를 원소로가지는 배열이다.
	//// 배열의 이름도 포인터이기 때문에 arr2는 첫번째 원소인 원소가 2개짜리인 배열의 첫번째 주소를 가리키고 있다.
	//// pa는 원소가 3개짜리인 배열의 주소를 담을 수 있기 때문에, 원소가 2개짜리인 배열의 주소를 담을 수 없다.

	//p2 = &pt;  // pt가 int형 자료의 주소를 담는 포인터 변수이다. 따라서 p2는 이 포인터 변수의 주소를 담고 있다.
	//// 이중포인터

	//*p2 = arr2[0];  // p2에 한 번 indirection을 해주면 int형 자료의 주소를 담는 포인터 변수이다.
	//// 이 포인텨 변수에 int형 자료의 주소를 담을 수 있다. arr2는 2중 배열이다. arr2[0]은 첫번째 원소로 int 원소가 2개인 배열이다.
	//// int 원소가 2개인 배열은, 첫번째 원소의 주소를 담고 있는 포인터 변수의 역할을 하기 때문에(배열의 이름)
	//// *p2이 첫번째 int 원소의 주소를 담게된다.
	//// pt = arr1[0]; 과 같은 원리이다.
	//// C4048	배열 첨자가 다릅니다. 'int (*)[3]'과(와) 'int (*)[2]'


	//p2 = arr2;  // error
	//// 포인터 변수의 크기는 운영체제 마다 다르지만 8바이트라고 하면, 이 8바이트 짜리 포인터 변수의 주소를 담는 p2는
	//// arr2가 int 2개의 원소를 갖는 배열의 주소를 담는 포인터이기 때문에 호완이 되지 않는다.
	//// C4047	'=': 'int **'의 간접 참조 수준이 'int (*)[2]'과(와) 다릅니다.
	//

	///* Pointer and const */

	//int x = 20;
	//const int y = 23;  // y의 값을 바꿀 수 없다.
	//int* p1 = &x;
	//const int*p2 = &y;
	//const int** pp2 = &p1;

	//p1 = p2;  // warning 하지만 문제는 되지 않는다. p1은 const가 아니기 때무니다.
	//*p2 = 123;  // Error가 난다. const int의 주소를 가리키는 p2이기 때문에 indirection하면 const인 y를 변화시키는 것이기 때문이다.
	//
	////const int* const p2 = &y;
	////p2 = p1; // p2도 const라서 아에 p2자체를 바꿀 수 없게 만들었다. 

	//int x2 = 30;
	//int* p3 = &x2;
	//*pp2 = p3;  // 한번 indirection 하면, 바꿀 수 있다. 원래 정의할 때 2번 indirection에서 const가 설정되있어서
	//pp2 = &p1;

	//{
	//	const int** pp2;
	//	int* p1;
	//	const int n = 13;
	//	pp2 = &p1;
	//	*pp2 = &n;  // pp2가 p1의 주소를 담고 있는 포인터 변수이다. indirection을 하면 p1이다. p1은 int n의 주소를 담고있는 포인터변수다.
	//	*p1 = 10;  // p1에 indirection하면 int n이다. 이 n에 10을 대입하는데, n은 const이다?  그래서 이런거 하지마세요...
	//}
	/* C const and C++ const */

	const int y;
	const int* p2 = &y;
	int* p1;
	p1 = p2;  // warning (error in cpp)

	return 0;
}
