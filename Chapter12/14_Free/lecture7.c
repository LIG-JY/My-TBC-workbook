#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* ptr_backup;
	printf("Dummy Output\n");
	{
		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));
		
		ptr_backup = ptr;  // backup

		free(ptr);
				
	}

	// what happens ?	
	//printf("%d %d\n", ptr_backup[0], ptr_backup[1]); -> 잃어버렸던 녀석 접근 가능
	printf("Dummy Output\n");

	return 0;
}
