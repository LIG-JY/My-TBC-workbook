#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count()
{
	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;
	// Stack 영역에 올라간다. 호출할 때 마다 초기화
}


/*
 int* count()
{
	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;
	return &ct;
}
이렇게 사용하지 말 것. Stack에 올라갔다 사라지는 변수의 주소를 반환하면? 문제가 있다. 굳이 사라질 걸 왜?
*/

void static_count()
{
	static int ct = 0;  // 초기화는 오직 한 번만! , 그 이후 ct = 123; 은 그냥 대입이다.
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;
	// Data, BSS영역에 올라간다.
}

/*
int* static_count()
{
	static int ct = 0;  // 초기화는 오직 한 번만! , 그 이후 ct = 123; 은 그냥 대입이다.
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;
	// Data, BSS영역에 올라간다.
	return &ct;

}
*/

int func(static int i)	// Warning (Error in GCC) 함수의 Parameter에 Static을 넣게 되면? 권장X 
{
	// 굳이 새로운 Stack Frame이 만들어지는데, Parameter 를 Static하게 BSS or Data Segment 메모리에 올릴 이유가 없다.
}

void counter_caller()
{
	count();
}

void static_counter_caller()
{
	static_count();
}

int main()
{
	count();
	count();
	counter_caller();

	static_count();
	static_count();
	static_counter_caller();

	return 0;
}
