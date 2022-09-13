#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <inttypes.h> // intmax_t

int main()
{
	/* multiple inputs with blank separators */
	int i;
	float f;
	char str[30];
	scanf("%d %f %s", &i, &f, str); //Note % is absent in front of str
	/*주의할것 scanf에서는 printf와 달리 float와 long float을 구분하기 때문에
	double로 퉁치는게 아니라 구분해야합니다. %f, %lf*/
	printf("%d %f %s\n", i, f, str); //Note % is absent(공백) in front of str

	/* character */
	char c;
	scanf("%c", &c); // try blank
	printf("\i\n", c); // blank is 32(ASCII)


	/* Unsigned as signed */
	unsigned i;
	scanf("%i", &i); // try negative
	printf("%i\n", i);


	/* Unsigned as unsigned */
	unsigned u;
	scanf("%i", &u); // try negative
	printf("%i\n", u);


	/* floating point numbers */
	double d = 0.0f;
	scanf("%lf", &d); // if, try E notation(과학적표기법) double을 lf로 받습니다.(scanf주의점)
	printf("%f\n", d); // printf에서는 f로 출력해도 double로 변환하기 때문에 %f를 써도 상관없습니다.


	/* Width */
	char str[30];
	scanf("%5s", str); //width 5글자까지만 입력이 됩니다. 
	printf("%s\n", str);


	/* h modifier */
	char j;
	scanf("%hhd", &j); // try large number(255초과 시 오버플로우 발생합니다.)
	printf("% i\n", j);


	/* integer with characters */
	int k;
	scanf("%i", &k); // try '123ab', '123ab45'
	printf("%i\n", k);


	/* j modifier */
	intmax_t t;
	scanf("%ji", &t); // intmax_t == longlong, portable type
	printf("%ji\n", t); // intmax_t를 사용할 때 j modifier가 필요합니다.


	/* Regular characters */
	int a, b;
	scanf("%d","%d",&a, &b); // try blank seperator only 입력할 때 ,로 구분해서 a b에 각각 할당합니다.
	printf("%d %d\n", a, b); // 


	/* char receives blank */
	int a, b;
	char c;
	scanf("%d%c%d", &a, &c, &b); // try 123 456
	printf("%d|%c|%d\n", a, c, b); // | is seperator


	// sentences?, getchar(), fgets(), etc.

	/* return value of scanf() */


	/* *modifier for printf() */
	int a = 123;
	int width = 5;
	printf("Input width : ");
	scanf("%d", &width); // try 123 456
	printf("*%d\n", width, a); // | is seperator


	/* *modifier for scanf() */
	int z;
	scanf("%*d%*d%d", &z); 
	printf("Your third input is %d\n", z); // | is seperator

	return 0;
}
