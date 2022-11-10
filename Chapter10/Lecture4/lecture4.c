#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[5];  // 배열 선언

	int num = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < num; ++i)
		arr[i] = (i + 1) * 10;

	int* ptr = arr;  // 배열의 이름은 이 배열이 차지하는 공간을 대표하는 포인터와 유사하다. 즉 주소죠

	printf("%p %p %p\n", ptr, arr, &arr[0]);  // 3개다 주소값이 같다. 기본적으로 16진수

	printf("%p %p %p\n", ptr + 2, arr + 2, &arr[2]);  // 3개다 주소값이 같다. arr + 2는 주소에 

	/*arr += 2;*/ // invalid -> arr이라는 변수가 배열의 첫번째 주소를 가리킨다. 이 주소값이 바뀌면 배열의 존재 자체가 위협받음
	
	ptr += 2;
	
	printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]); // dereferencing, 4번째 값이 잘 나오죠
	/*핵심은 배열의 indexing과 포인터 산술연산을 대체할 수 있다 입니다.*/

	/*int* ptr = arr;*/ // 이거 그냥 두면 똑같은 이름의 포인터 변수를 두번 선언하게 되어서 오류가 발생합니다.
	for (int i = 0, *ptr = arr; i < num; ++i) // 따라서 for 문의 지역변수로 사용하면 문제가 없다.
	{
		printf("%d %d \n", *ptr++, arr[i]);  
		// 후위연산자 생각하기, *ptr로 indirecting하고, statment의 끝에서 ; 를 만나면 *ptr(포인터변수)에 더하기 1을 해줍니다.
		/*그렇게 되면 다음 포문에서 *ptr은 1칸 (intsize 4만큼 주소가 이동), 즉 인덱스를 1만큼 움직인 배열의 값이 나옵니다.*/
	}

	for (int i = 0, *ptr = arr; i < num; ++i)
	{
		printf("%d %d \n", *(ptr + i), arr[i]);  // 위의 for문과 완전히 동일
	}
	
	for (int i = 0, *ptr = arr; i < num; ++i)
	{
		printf("%d %d \n", *ptr + i, arr[i]);  // 33이하 코드와 비교, indirection 하고 1을 더하는 것과 , 포인터(주소)에 1을 더하는거랑 완전히 다르다.
	}
	
	return 0;
}
