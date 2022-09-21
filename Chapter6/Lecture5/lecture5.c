#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int tv, fv;
	tv = (1 < 2); // True, 관계식의 값은 1
	fv = (1 > 2); // False, 관계식의 값은 0
	/*print 해보면 값을 알 수 있습니다*/

	int i = -5;
	while (i)
	{
		printf("%d is True\n", i++); // -5 ,-4 .. -1.0일때 종료
	}
	printf("%d is False\n", i++); // 0 외에는 True

	while(1)
		// 이렇게 무한루프 만들 수 있습니다.
	return 0;
}
