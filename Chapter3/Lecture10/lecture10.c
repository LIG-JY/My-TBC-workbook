#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char c = 'A';
	char d = 65;// d = 'A' (ASCII변환 시 대응됩니다.)
    char f = '*';

    printf("%c %hdd\n", c, c);
    printf("%c %hdd\n", d, d);
    /* 각각 %c formatspecifier은 문자, %hdd formatspecifier은 정수로 출력합니다.*/
    printf("%c %hdd\n", f, f);

    printf("%c \n", c+1);
    /* 문자와 정수를 혼용해서 사용할 수 있습니다. 문자 c에 1을 더했습니다. 이 경우 A의 다음 B를 출력합니다. */

    char a = '\a'; // \a는 2개의 문자가 합쳐저서 하나의 문자처럼 기능을 합니다. escapesequence alram
    printf("%c", a); // 위에서 정의한 변수를 출력합니다. 소리가 나는 코드.
    printf("/07"); // 바로 문자열에 아스키코드 8진수 7을 입력해도 됩니다.
    printf("/x7"); // 바로 문자열에 아스키코드 16진수 7을 입력해도 됩니다.

    float salary;
    // printf("$______");
    printf("$______\b\b\b\b\b\b"); // 커서를 백슬래시 하는 escapesequence
    scanf("%f", &salary); // salary에 사용자가 입력합니다.

    printf("AB\tCDEF\n");
    printf("ABC\tDEF\n"); // tab으로 줄을 맞출 수 있습니다.


	printf("\\ \'HA+\' \"Hello\" \?\n");

	return 0;
}
