#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char fruit_name; // stores only one character

	printf("What is your favorite fruit?"\n);

	scanf("%c", &fruit_name); // becareful with &(ampersand)

	/* �� ampersand�� ����ϳ���? 
	scanf�� fruit_name memory������ �Է¹��� ���� �־��ݴϴ�.
	���� fruit_name�տ� ampersand�� �ٿ��� �ּҷ� ��ȯ���ִ� ���Դϴ�.
	�� ��ǻ�ʹ� furit_name�̶�� char_type ������ �޸� �ּҿ� ���� �ְ� �˴ϴ�.*/

	printf("You like %c!\n", fruit_name);

	return 0;
}