#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	double d = 3.1415926535897932384626433832795028841971693993751058209749445923078164062;

	printf("%c\n", 'A'); // 한 글자 character, 아이템에는 작은따옴표 쓸 것
	printf("%s", "I love you\n"); // 출력을 할 string안에 \n을 넣어도 상관없다. stirng이니까!
	printf("Even if there's a small chance,\
we owe this to everyone who's not in this room to try.\n"); // 2줄 이상에 걸쳐서 string적을 때 다음 줄 가기전 \를 써줘야합니다.

	printf("\n");
	printf("%d %i %i %i\n", 1004, 1234, INT_MAX, UINT_MAX); // %i(integer형식지정자)에 unsigned int 자료형의 변수의 최대값을 넣어서 오버플로우가 발생
	printf("%u %u %u\n", 1024, -1, UINT_MAX); // u%(unsigned int형식지정자)에  -1을 넣어서 오버플로우 발생

	printf("\n");
	printf("%f %f %lf\n", 3.141592f, d, d); // l in %lf is ignored
	/*C언어 에서는 컴퓨터가 컴파일 할 때 내부적으로 float을 모두 double로 인식하기 때문에
	double 자료형을 %f 형식지정자에 사용해도 상관없습니다. 그리고 %lf에서 l도 무시됩니다.
	즉 longfloat라고 할 필요없이 double로 되서 괜찮다는 말입니다.*/
	printf("%a %A\n", d, d); // p표기법
	printf("%e %E\n", d, d); // e표기법(과학적표기법)

	printf("\n");
	printf("%g %g\n", 123456.789, 1234567.89); // 자리수에 따라 e표기법,p표기법 달라짐
	printf("%G %G\n", 123456.789, 1234567.89);
	printf("%g %g\n", 0.00012345, 0.000012345); // 자리수에 따라 e표기법,p표기법 달라짐
	printf("%G %G\n", 0.00012345, 0.000012345);

	printf("\n");
	printf("%o\n", 9); // 8진수 9는 11
	printf("%p\n", &d); // d라는 변수의 주소를 출력, pointer of operator

	printf("\n");
	printf("%x %X\n", 11, 11); // 11은 16진수 b
	printf("%%\n", d); // &기호 자체를 출력할 수 있다. 뒤의 아이템은 무시됩니다.

	printf("\n");
	printf("%9d\n", 12345); // 10진수로 형식을 지정하는데 9자리로 받고 남는 칸은 공백으로
	printf("%09d\n", 12345); // 10진수로 형식을 지정하는데 9자리로 받고 남는 칸은 0으로
	printf("%.2f\n", 3.141592); // .2를 붙이면 소수점 2자리까지 출력합니다.
	printf("%.20f %.20lf\n", d, d); // .20를 붙이면 소수점 20자리까지 출력합니다. f든 lf든 상관없다.

	printf("\n");
	int n_printed = printf("Counting!"); // pritnf가 출력한(return)한 값을 다시 변수로 받아서
	printf("%u\n", n_printed); // 출력했습니다. 뒤의 정수는 글자 수입니다, 따라서 printf의 return은 글자 수 임을 알 수 있다.

	return 0;
}
