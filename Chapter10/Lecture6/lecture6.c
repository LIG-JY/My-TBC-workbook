#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12
#define YEARS 3


int main()
{
	double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
	double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
	double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

	/*
	1. Use 2D array
	2. Print data
	3. Calculate and print yearly average temperatures of 3 years
	4. Calculate and print monthly average temperatures for 3 years
	*/


	/* Step 2 */
	double years[YEARS][MONTHS] = {{ -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 },
								   { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 },
								   { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 }};
	printf("[Temperature Data]\n");
	printf("Year index : \t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\n");
	for (int i=0; i<YEARS; ++i)
	{
		printf("Year %d     : ",i );
		for (int j=0; j<MONTHS; ++j)
		{
			printf("\t%.1lf", years[i][j]);
		}
		printf("\n");
	}


	

	/* Step 3 */
	printf("\n");
	printf("[Yearly average temperatures of 3 years]\n");
	for (int i=0; i<YEARS; ++i)
	{
		double year_avg = 0.0;
		for (int j = 0; j<MONTHS; ++j)
		{
			year_avg += years[i][j];
		}
		printf("Year %d : average temperature = %.1lf\n",i ,year_avg/12);
	}
	

	/* Step 4 */
	printf("\n");
	printf("[Monthly average temperatures for 3 years]\n");
	printf("Year index : ");
	for (int i=0; i < MONTHS; ++i)
	{
		printf("\t%d", i+1);
	}
	printf("\n");
	printf("Avg temps  : ");
	for (int i=0; i<MONTHS; ++i)
	{
		double month_avg = 0.0;
		for (int j=0; j<YEARS; ++j)
		{
			month_avg += years[j][i];
		}
		printf("\t%.1lf", month_avg/3);
	}

	return 0;
}
