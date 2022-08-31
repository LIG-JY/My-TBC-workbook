#include <stdio.h>
#include <float.h>

int main()
{
	printf("%u\n", sizeof(float));
	printf("%u\n", sizeof(double));
	printf("%u\n", sizeof(long double)); // vscode의 컴파일러에서는 double 과 longdouble의 메모리 크기가 같습니다.

    float f = 123.456f;  // float수를 float 자료형 변수에 할당
    double d = 123.456;  // literal 입장에서는 doulbe이 기본형입니다. double수를 double 자료형 변수에 할당

    float f2 = 123.456;  // float 자료형 변수에 dobule수를 할당할 때 f를 안 붙이면 truncation warning이 뜹니다.
    double d2 = 123.456f; 
    /* double 자료형 변수에 float수를 할당하면 문제가 생기지 않습니다. double 자료형이 더 큰 메모리를 차지하기 하기 때문에 여유가 있죠. */
	
    int i = 3;
    float f3 = 3.f; // 3.0f라고 쓰는 것을 추천합니다.
    double d3 = 3.; // 3.0이라고 쓰는 것을 추천합니다.

    float f4 = 1.234e10f; // 과학적 표기법을 사용합니다. 1.234(fraction)*10^10(exponenet). 마지막 f는 float 수를 의미합니다.

    float f5 = 0x1.1P1; // 0x붙으면 16진수 1.1이 16진수 1.1 e대신에 P를 사용해도 됩니다.
    double d5 = 1.0625e0;

    printf("%f %F %e %E\n", f, f, f, f); // F하면 대문자로 출력되는데 16진수일 때만 의미가 있겠죠?
    printf("%f %F %e %E\n", d, d, d, d); // E를 format specifier은 과학적 표기법으로 나타낼 때 e를 대문자로 출력합니다.
    printf("%a %A\n", f5, f5); // a format specifier은 16진수로 출력하게 합니다. A로 하면 대문자로 출력합니다.
    printf("%a %A\n", d5, d5);
    
	return 0;
}
