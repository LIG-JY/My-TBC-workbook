#include <stdio.h>

int main()
{
	printf("Integer divisions\n");
	printf("%d\n", 14 / 7);
	printf("%d\n", 7 / 2); // 3.5 in floating division , 결과값이 %d 정수이기 때문에 버림해서 3이 결과입니다. (Truncation)
	printf("%d\n", 7 / 3); // 2.333 in floating division
	printf("%d\n", 7 / 4); // 1.75 in floating division
	printf("%d\n", 8 / 4); //2

	printf("Truncating toward zero (C99)\n");
	printf("%d\n", -7 / 2); // -3.5 in floating division , (Truncation) 소수점 이하 부분은 잘려나갑니다. C99표준
	printf("%d\n", -7 / 3); // -2.333 in floating division
	printf("%d\n", -7 / 4); // -1.75 in floating division
	printf("%d\n", -8 / 4); // -2

	printf("\nFloating divisions\n");
	printf("%f\n", 9.0 / 4.0); 
	printf("%f\n", 9.0 / 4); // Note: 4 is integer, CPU는 자료형이 다른 두 숫자끼리 나누기를 할 수 없습니다. 따라서 내부에서 컴파일러가 int를 double로 바꿔줍니다. (형변환)

	return 0;
}	

