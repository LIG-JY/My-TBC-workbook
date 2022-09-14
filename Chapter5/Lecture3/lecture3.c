
#include <stdio.h>

int main()
{
	printf("%d\n", 1 + 2);

	int income, salary, bonus;

	income = salary = bonus = 100; // triple assignment


	salary = 100;
	bonus = 30;

	income = salary + bonus; // l-value vs r-value
	/*salary+bonus의 값은 임시적으로 r-value*/

	int takehome, tax;
	tax = 20;
	takehome = income - tax;

	int a, b;
	a = -7;
	b = -a;
	b = +a; // + does nothing

	1.0f + 2; // float, 승급개념

	return 0;
}
