#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
	fopen() mode string for binary IO
	- "rb", "wb", "ab"
	- "ab+", "a+b"
	- "wb+", "w+b"
	- "ab+", "a+b"
	C11 'x' mode fails if the file exists, instead of overwriting it.
	- "wx", "wbx", "w+x", "wb+x", "w+bx"
	*/

	// Writing example
	FILE* fp = fopen("binary_file", "wb");

	double d = 1.0 / 3.0;
	int n = 123;
	int* parr = (int*)malloc(sizeof(int) * n);
	if (!parr) exit(1);
	for (int n = 0; n < 123; ++n)
		*(parr + n) = n * 2;

	fwrite(&d, sizeof(d), 1, fp);  // &d 주소로 부터 몇 개를, 얼마 사이즈로 쭉 붙여서 저장하겠다 이런 의미이다.
	fwrite(&n, sizeof(n), 1, fp);
	fwrite(parr, sizeof(int), n, fp);  // 시작주소, 각 원소 사이즈, 원소 개수, 파일스트림

	/* 8 * 1 + 4 * 1 + 4 * 123 = 504 byte */
	fclose(fp);
	free(parr);

	// Reading example, feof(), ferror()
	FILE* fp = fopen("binary_file", "rb");
	double d;
	int n = 0;
	fread(&d, sizeof(d), 1, fp);
	fread(&n, sizeof(n), 1, fp);  // 읽어들인 n에 맞춰서

	int* parr = (int*)malloc(sizeof(int) * n);  // 동적할당 메모리 초기화
	if (!parr) exit(1);

	fread(parr, sizeof(int), n, fp);

	printf("feof = %d\n", feof(fp));   // feof -> end of file을 만났는지 확인하는 함수.

	printf("%f\n", d);
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
		printf("%d", *(parr + i));
	printf("\n");
	// 지금까지 파일에 저장된 데이터만큼 딱 읽었기 때문에, EOF를 만나기 직전이다.

	fread(&n, sizeof(n), 1, fp);  // 4바이트(int)만큼 더 읽게 해서 EOF를 만나게 만들었다.
	printf("feof = %d\n", feof(fp));  // EOF를 만나서 0이 아닌 값을 return하게 됩니다.
	printf("ferror = %d\n", ferror(fp));  // return 0 (Error 가 아니면 0을 return 합니다.)

	fwrite(&n, sizeof(n), 1, fp);  // read mode인데 write를 하게 해서 오류를 발생시킨다. 
	printf("ferror = %d\n", ferror(fp));  // 이제 찐으로 오류나서 0이 아닌 값 return

	fclose(fp);  // 파일 스트림 닫기
	

	return 0;
}
