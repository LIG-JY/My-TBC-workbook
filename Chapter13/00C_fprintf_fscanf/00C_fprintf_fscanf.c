#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31

int main(void)
{
	FILE* fp;
	char words[MAX] = { '\0', };
	
	const char* filename = "record.txt";

	/*
	fopen() mode strings for text files
	- r: reading
	- w: creating-and-writing or over-writing
	- a: appending or creating-and-writing
	- r+: both reading and writing
	- w+: reading and writing, over-writing or creating
	- a+: reading and writing, appending or creating
	*/

	if ((fp = fopen(filename, "r+"))  == NULL)  // try w+ , a+
	{
		fprintf(stderr, "Cant't open \"%s\"file.\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))
	// words라는 문자(char)의 배열에(문자열) stdin을 통해서 입력받는다. 입력받은 문자열이 1개가 있냐? 즉 입력이 없으면 조건이 거짓이죠.
	// 그리고 입력받은 string을 봤을 때 첫 글자가 .(마침표)면 실행하지 않는다.
	{
		fprintf(fp, "%s\n", words); // fp라는 데이터stream에(fp가 스트림의 주소를 값으로 가진다.) "%s\n" 형식으로, words문자열을 출력한다.(쓴다.)
	}
	rewind(fp);  // 파일의 처음으로 돌아간다. (위 코드에서 파일 스트림에 쭉쭉 쓰다가. 다시 파일의 처음으로 돌아간다.)

	while (fscanf(fp, "%s", words) == 1)  // fp 파일에서 fscaf로 words 1단어(character)씩 읽어들인다. 1자리 문자열이 그냥 문자(char)이다.
	// fscanf의 return은 정상적으로 받은 인자의 개수이다. 1개를 입력받아서 1개가 정상이다. 그러면 true로 출력코드가 실행된다.
	// while (fscanf(fp, "%s", words) != EOF) 이거랑 같은 코드다.
	{
		fprintf(stdout, "%s\n", words);
	}

	if (fclose(fp) != 0) // 파일이 정상적으로 잘 닫히면 0을 return한다. main 함수 return값과 유사하다.
	{
		fprintf(stderr, "Error closing file\n");
	}

	return 0;
}
