#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
		for(initialize; test; update)
		" for문을 실행할 때 initialize expression은 한 번만 실행됩니다. "
		" test에서 False가 아니면 아래의 statement를 실행합니다. "
		" updat하고 다시 test가 실행됩니다. " 
			statement
	*/

	for (int i = 10; i > 0; i--);
		// do something

	for (int i = 10; i < 100; i = i + 8);
		// do something

	for (char c = 'A'; c <= 'Z'; c++);  // 내부적으로 ASCII
		// do something

	for (int i = 0; i * i < 10; i++);
		// do something
	
	for (int x = 1, y = 5; y <= 20; y = (++x * 3) + 10);  // 같은 자료형의 변수는 여러개 사용할 수 있다.
		// do something

	for (double d = 100.0; d > 300; d = d * 1.1);  // 정수형과 실수형 비교할 때 주의점 != 같이 일치를 쓰면 어려울 수 있다.
		// do something

	for (;;);
	//  while(1) 이랑 동일합니다.

	int i = 0;
	for (printf("Let's go! \n"); i != 7; scanf("%d", &i));
	// update를 scanf로 받습니다...
	return 0;
}
