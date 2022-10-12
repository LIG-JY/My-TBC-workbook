#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const int secret_code = 337;
	int answer = 0;
	do
	{
		printf("Enter secret code : ");
		scanf("%d", &answer);
	} while (answer != secret_code);
	printf("Good!");

	return 0;
}
