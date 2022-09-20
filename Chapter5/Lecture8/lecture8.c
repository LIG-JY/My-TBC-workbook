#include <stdio.h>

int main()
{
	int a = 0;
	a++; // a = a + 1 or a += 1
	printf("%d\n", a);

	++a; // a = a + 1 or a += 1
	printf("%d\n", a);

	double b = 0;
	b++; // a = a + 1 or a += 1
	printf("%d\n", b);

	++b; // a = a + 1 or a += 1
	printf("%d\n", b);

	int count = 0;
	while (count < 10) // count++ or ++count
	{
		printf("%d ", count);
		count ++;
	}

	int i = 1, j = 1;
	int i_post, pre_j;

	i_post = i++;
	pre_j = ++j;

	printf("%d %d\n", i, j);
	printf("%d %d\n", i_post, pre_j);

	int n = 3;
	int m = 2 * --n;
	printf("%d %d\n", n, m);

	n = 1;
	m = 2 * n--;
	printf("%d %d\n", n, m);

	/* very high precedence */

	/*int x, y, z;
	x = 3, y = 4;
	z = (x + y++) * 5;
	printf("%d %d %d\n", x, y, z);*/

	
	/* ++ and -- affect modifiable lvaues */
	int x, y, z;
	x = 1, y = 1;
	z = x * y++; // (x*y)++ 가 아닙니다. (x*y)는 일시적으로 rvalue입니다. x,y는 각각 메모리공간을 갖지만, x*y는 아닙니다.
	printf("%d %d %d\n", x, y, z);
	// z = (x*y)++ // compile error
	// z = 3++ // compile error
	

	/* Bad practices */
	//int n = 1;
	//printf("%d %d", n, n * n++);
	//int x = n / 2 + 5 * (1 + n++);
	//int y = n++ + n++;
	// 식을 2줄이나 3줄로 쪼개서 명확하게 코딩합시다. 헷갈립니다.
	return 0;
}
