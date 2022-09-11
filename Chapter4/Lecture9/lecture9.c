#include <stdio.h>

int main()
{
	float	n1 = 3.14;	// 4 bytes ->printf에서 8비이트 double로 변환
	/*float n1 = 3.14f;*/
	double	n2 = 1.234;	// 8 bytes
	int		n3 = 1024;	// 4 bytes
	
	printf("%f %f %d\n\n", n1, n2, n3); // 정상적으로 출력

	/*잘못 출력*/
	printf("%d %d %d\n\n", n1, n2, n3); // 4, 4, 4(N, N, N) 전부 이상한 값
	printf("%lld %lld %d\n\n", n1, n2, n3); 
	/* 8, 8, 4(N, N, N) n1은 8바이트 정상 n2도 8바이트 정상 n3도 정상이다.
	하지만 n1과 n2부동소수점 수를 d(정수형)으로 출력하려다 보니 
		2진수로 변환하는 과정에서 값이 이상하게 출력됩니다.*/
	printf("%f %d %d\n\n", n1, n2, n3); /*8, 4, 4(Y, N, N) 
	n1은 float에다가 8바이트라서 정상적으로 나옵니다.
	하지만 뒤의 2개는 n2가 4바이트로 해석되어 밀려쓰게 되어 문제가 생깁니다.*/
	printf("%f %lld %d\n\n", n1, n2, n3); /*8, 8, 4(Y, N, Y)
	메모리 공간은 모두 맞지만 n2는 부동소수점을 정수로 변환하는 과정에서
	오류가 발생합니다.*/
	return 0;
}
