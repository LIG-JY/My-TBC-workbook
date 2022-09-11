/* printf example */
#include <stdio.h>
#include <limits.h>

int main()
{
	printf("Characters: %c %c \n", 'a', 65);
	printf("Decimals: %d %ld\n", 1977, 650000L);
	printf("Preceding with blanks: %10d \n", 1977);
	printf("Preceding with zeros: %010d \n", 1977);
	printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf("Width trick: %*d \n", 5, 10);
	printf("%s \n", "A string");

	printf("%10i\n", 1234567); // width 10으로 10자리로 출력합니다.
	printf("%-10i\n", 1234567); // - flag 왼쪽으로 딱 붙여서 출력합니다.
	printf("%+i %+i\n", 123, -123); // + flag 앞의 부호를 붙여서 출력합니다.
	printf("% i % i\n", 123, -123); // space(공백) flag
	printf("%X\n", 17); // specifier X 16진법으로 출력합니다.
	printf("%X\n", 17); // specifier X 16진법으로 출력합니다.
	printf("%#X\n", 17); // specifier X 16진법으로 출력합니다. 0을 가장 앞에 붙여줍니다.
	printf("%05i\n", 123); // 5자리 width에 남는자리를 0으로 채워줍니다. 파일 이름을 만들 때 종종씁니다.
	printf("%*i\n", 7, 456); // 앞의 인자를 width로 설정합니다.

	printf("\nprecision\n");
	printf("%.3d\n", 1024); // 정확도 3글자를 충족해야합니다. (유효숫자)
	printf("%.5d\n", 1024); // 정확도 5글자를 충족해야합니다. 따라서 맨 앞에 0을 추가합니다.
	printf("%.3f\n", 123456.1234567); // 소수점 이하 3자리까지 반올림합니다.
	printf("%.3f\n", 123456.1235); // 소수점 이하 3자리까지 반올림합니다.
	printf("%10.3f\n", 123.45678); // 10자리 출력 + 소수점 이하 3자리까지 반올림합니다.
	printf("%010.3f\n", 123.45678); // 남는자리 0으로 채웁니다.+10자리 출력 + 소수점 이하 3자리까지 반올림합니다.
	printf("%.5s\n", "ABCDEFGHIJKLMNOP"); // 5자리 까지 string으로 출력합니다. 나머지는 잘립니다.
	printf("%.s\n", "ABCDEFGHIJKLMNOP"); // 입력을 안 하면 0 까지 string으로 출력합니다. 나머지는 잘립니다.

	printf("\nlenght\n");
	printf("%hhd %hd %d\n", 257, 257, 257); // hhd의 경우 char과 동일하게 1byte라서 8비트 따라서 256까지 표기가능하기 때문에 오버플로우가 발생합니다.
	printf("%d %lld %lld\n", INT_MAX+1, INT_MAX+1, 214748364LL); 
	// x64, x86결과가 다를 수 있습니다.(32비트 64비트 차이) lld하면 INT_MAX+1도 출력할 수 있다.


	return 0;
}

