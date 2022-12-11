#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// ABCD.......XYZ 까지 적힌 텍스트 파일
	//  Current position 0 and read -> A
	//  Current position 1 and read->B

	int ch;
	long cur;

	FILE* fp = fopen("text.txt", "r");
	cur = ftell(fp);   // 시작점으로 부터 몇 바이트 떨어져있는지 return
	printf("fetll() = %ld\n", cur);

	fseek(fp, 2L, SEEK_SET);  // 시작점으로 부터 2바이트(Long) 떨어진 곳에서 읽을 준비를 한다.
	cur = ftell(fp);
	printf("fetll() = %ld\n", cur);  // 읽으면 한 바이트 더 이동한다.
	ch = fgetc(fp);
	printf("fetll() = %d %c\n", ch, ch);
	cur = ftell(fp);
	printf("fetll() = %ld\n", cur);

	fseek(fp, -2L, SEEK_CUR);  // 현재 위치에서 뒤로 2바이트 이동
	cur = ftell(fp);
	printf("fetll() = %ld\n", cur);  // 읽으면 한 바이트 더 이동한다.
	ch = fgetc(fp);
	printf("fetll() = %d %c\n", ch, ch);

	fseek(fp, 0L, SEEK_END);  // 끝 위치에서 이동 안 한다.  -> EOF
	ch = fgetc(fp);  
	printf("fetll() = %d %c\n", ch, ch);  // EOF 값은 -1

	fseek(fp, -1L, SEEK_END);  // 끝 위치에서 -1 이동한다.
	ch = fgetc(fp);
	printf("fetll() = %d %c\n", ch, ch);

	fseek(fp, -2L, SEEK_END);  // 끝 위치에서 -2 이동 한다.
	ch = fgetc(fp);
	printf("fetll() = %d %c\n", ch, ch);



	return 0;
}
