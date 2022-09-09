#include <stdio.h>
#include <limits.h> // 정수 범위 등 자료형의 최대 혹은 최소값을 기호적 상수로 표현합니다.
#include <float.h> // FLT_MAX ....


#define PI 3.141592	// manifest constants, symbolic constants

int main()
{
	printf("PI is %f\n", PI);
	printf("Biggest int is %d\n", INT_MAX);
	printf("One byte in this system is %d bits\n", CHAR_BIT);
	printf("Smallest normal float %e\n", FLT_MIN);

	return 0;
}
