#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_DAYS 365

int main()
{
	char my_chars[] = "Hello, World!";  //  배열의 크기를 비워놓으면 알아서 크기를 맞춰서 할당해줍니다.

	int daily_temperature[NUM_DAYS];  // int사이즈의 배열을 365개로 정의합니다. array의 size를 define으로 넣는 경우도 종종 있습니다.
	double stock_prices_history[NUM_DAYS];  

	printf("%zd\n", sizeof(stock_prices_history)); 
	printf("%zd\n", sizeof(double) * NUM_DAYS);  // 위 줄과 결과가 동일합니다.
	printf("%zd\n", sizeof(stock_prices_history[0]));  // 더블 하나이기 때문에 8입니다.

	
	int  my_numbers[5];  // indices, offsets(첫번째 주소로부터 얼마나 떨어져있는가?), subscripts

	my_numbers[0] = 1;
	my_numbers[1] = 3;
	my_numbers[2] = 4;
	my_numbers[3] = 2;
	my_numbers[4] = 1024;

	scanf("%d", &(my_numbers[0]));

	for(int i = 0; i < 5; i++)
	{
		printf("%d\n", my_numbers[i]);
	}

	// my_numbers[5]에 할당할 수 없어용! out of bound

	// my_numbers = 7; compile error

	return 0;
}
