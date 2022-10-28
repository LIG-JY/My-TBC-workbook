#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a; // file 영역 변수
int int_max(int i, int j);

int int_max(int i, int j)
{
	a = 45; // 함수 frame에서 file 영역 변수 a에 접근이 가능합니다.
	int m; // m은 지역변수입니다.
	m = i > j ? i : j;
	return m; // 변수m은 int_max의 scope 안에서만 유효합니다. stack frame의 개념 
}

int main()
{
	int a; // 바깥에 file 영역변수가 있고, main 함수 안에 새로운 변수가 있을 때, 더 작은 영역의 namespace가 우선순위

	a = int_max(1, 2);
	printf("%d\n", a);
	printf("%p\n", &a); // pointer의 p, 변수 a의 주소를 출력합니다.
	{
		////int a; // 새로운 변수, 메모리 주소가 다르다.
		a = int_max(4, 5); // 새로 더 작은 영역
		printf("%d\n", a);
		printf("%p\n", &a); // pointer의 p, 변수 a의 주소를 출력합니다.

		int b = 51;
	}
	/*printf("%d", b);*/
	printf("%d\n", a);
	printf("%p\n", &a); // pointer의 p, 변수 a의 주소를 출력합니다.
	
	return 0;
}

