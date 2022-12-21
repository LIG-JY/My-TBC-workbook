#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
		Flexible array member (struct hack in GCC)
	*/

	struct flex
	{
		size_t count;
		double average;
		double values[];	// flexible array member (last member!)
	};

	const size_t n = 3;

	struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf == NULL)
		exit(1);

	printf("Size of struct flex %zd\n", sizeof(struct flex));
	printf("Size of *pf %zd\n", sizeof(*pf));
	printf("Size of malloc %zd\n", sizeof(struct flex) + n * sizeof(double));

	printf("%lld\n", (long long)pf);
	printf("%lld\n", (long long)&pf->count);
	printf("%zd\n", sizeof(pf->count));
	printf("%lld\n", (long long)&pf->average);
	printf("Address of pf->values is %lld\n", (long long)&pf->values);
	printf("Value of pf->values is %lld\n", (long long)pf->values);
	printf("Size of pf->values is %zd\n", sizeof(pf->values));
	

	pf->count = n;
	pf->values[0] = 1.0;
	pf->values[1] = 2.0;
	pf->values[2] = 3.0;
	
	pf->average = 0.0;
	for (int i = 0; i < pf->count; i++)
	{
		pf->average += pf->values[i];
	}
	pf->average /= (double)pf->count;
	printf("Average is %lf\n", pf->average);

	
	
	struct nonflex
	{
		size_t count;
		double average;
		double *values;	// double형 포인터, 동적할당을 사용할 예정입니다.
	};

	struct nonflex nf;
	nf.values = (double *)malloc(sizeof(double) * n);
	
	
	/* 주의사항 '=' 연산자를 사용해 값을 복사하면 안 된다.
	
	 struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf2 == NULL)
		exit(1);

	*pf2 = *pf1 ;  memcpy()를 대신 사용하라.
	
	*/
	return 0;
}
