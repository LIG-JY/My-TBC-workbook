#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ch;
	FILE* fr;	//TODO: file pointer to write 파일을 처리할 때 필요한 데이터 묶음(구조체)에 대한 포인터
	FILE* fw;  // write할 file 데이터 구조체에 대한 포인터


	/*
	typedef struct _iobuf
	{
		char*   _ptr;
		int _cnt;
		char*   _base;
		int _flag;
		int _file;
		int _charbuf;
		int _bufsiz;
		char*   _tmpfname;
	} FILE;
	*/
	
	const char* out_filename = "copy.txt". // file명 write용도
	
	unsigned long count = 0;

	if (argc != 2)  // 명령줄인수로 입력이 2개 이상 들어오도록 제한합니다.
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r")) == NULL)
		// argv[1]이라는(명령줄 인수로 파일 이름 받기) 이름을 갖는 파일을 읽어서 엽니다., fr이라는 구조체에 대한 포인터를 반환한다. 이게 NULL이면 파일 스트림을 열지 못했다는 뜻이다.
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(out_filename, "w")) == NULL). // write mode
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*
		fopen <mode strings> for text files
		- r: reading
		- w: creating-and-writing or over-writing (파일이 없으면 만들고, 있으면 덮어쓴다.)
		- a: appending or creating-and-writing
		- r+: both reading and writing
		- w+: reading and writing, over-writing or creating
		- a+: reading and writing, appending or creating
	*/

	while ((ch = fgetc(fr)) != EOF)  // fgetc는 데이터 스트림을 인자로 받아서 문자로 한 글자씩 받아오고 있다. (데이터 타입은 ch가 int형임) (ASCII)
	{
		fputc(ch, stdout);
		// stdout이 _Stream인데, 다른 Stream으로 바꿀 수 있다는 것을 생각합시다.
		count++;
	}

		while ((ch = fgetc(fw)) != EOF)  // fgetc는 데이터 스트림을 인자로 받아서 문자로 한 글자씩 받아오고 있다. (데이터 타입은 ch가 int형임) (ASCII)
	{
			fputc(ch, fw);
		// stdout이 _Stream인데, 다른 Stream으로 바꿀 수 있다는 것을 생각합시다.
		// fw가 가리키는 stream에 
		count++;
	}

	fclose(fr); // Stream 다 사용하면 닫아준다.
	fclose(fw);
	printf("File %s has %lu chracters\n", argv[1], count);

	return 0;
}

/*
//File Reading example
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
int main()
{
	int c;
	char file_name[] = "my_file.txt";//TODO: use scanf(...)
	return 0;
}
*/
