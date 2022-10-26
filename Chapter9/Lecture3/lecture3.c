#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int int_min(int, int); // 반환 자료형이 Int

int main()
{
	int i1, i2;

	while (1)
	{
		printf("Input two integers : ");
		
		if (scanf("%d %d", &i1, &i2) != 2) break; // 정수 자료형이 2개 입력되지 않으면 break
		
		int lesser = int_min(i1, i2);
		//int lesser = min;
		printf("The lesser of %d and %d is %d\n", i1, i2, lesser);

		//printf("The lesser of %d and %d is %d\n", i1, i2, int_min(i1, i2));
		
	}

	printf("End.\n");

	return 0;
}

int int_min(int i, int j)

// 반환 자료형이 int 문법상 생략할 수 있습니다. 
// 즉 컴파일러가 반환 자료형이 없다면 int라고 간주합니다. 하지만 생략 안 하는 것을 추천합니다.
// int_min(int i, int j)
{
	int min;

	if (i < j)
		min = i;
	else
		min = j;

	return min;

	//return (i < j) ? i : j;

	//return (float)min; -> int로 리턴하지 않고, 강제로 float로 형변환해서 return하는 경우

	//if (i < j)
	//	return i;
	//else
	//	return j;

	//printf("ERROR"); -> 의도적으로 실행되지 않는 코드를 적어주는 것
	//exit(1); -> 일어나면 안 될 일이 일어나고 있다!!!

	//return; // return with no value
}
