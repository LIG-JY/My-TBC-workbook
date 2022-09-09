#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#define pi 3.141592f
#define AI_NAME "Jarvis"


int main()
{
	float radius, area, circum;

	const float pi = 3.141592f;

	printf("I'm %s.\n", AI_NAME);

	printf("Input radius\n");

	scanf("%f", &radius);

	area = pi * radius * radius;

	circum = pi * 2.0f * radius;

	printf("Area is %f\n", area);

	printf("circum is %f\n", circum);


	/*TODO: wrong usage, strings, const*/

	return 0;
}
