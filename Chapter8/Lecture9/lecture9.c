#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()

int main()
{
	int c;
	FILE *file = NULL; // *는 포인터 변수를 의미합니다. 자료형처럼 FILE 구조체를 정의합니다.
	char file_name[] = "my_file.txt"; // TODO: use scanf(...) -> 같은 경로의 text file을 읽는 이슈 때문에 scanf로 받기도 합니다.
	// my_file.txt는 하드코딩 ㅋㅋ 직접 파일 이름을 입력하는 방식입니다.

	file = fopen(file_name, "r"); // file_name이라는 변수의 값을 file이름으로 읽습니다. 파일스트림을 연다.
	if (file == NULL) // NULL은 파일이 없다는 말입니다. 초기화된 상태 그대로다.
	{
		printf("Failed to open.\n");
		exit(1); // 프로그램 종료
	}

	while ((c = getc(file)) != EOF) // file 스트림의 데이터를 입력
		putchar(c); // 출력
	fclose(file); // file 닫기
	
	return 0;
}
