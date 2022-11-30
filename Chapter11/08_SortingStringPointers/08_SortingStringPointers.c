#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// strcmp()

void swap(char** xp, char** yp);	//Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main()
{
	/*printf("%d\n", strcmp("Apple", "Orange")); -> -1*/
	char* arr[] = { "Apple", "AppleBee", "Cherry", "Orange", "Pineapple" };
	int n = sizeof(arr) / sizeof(arr[0]);

	printStringArray(arr, n);

	selectionSort(arr, n);

	printStringArray(arr, n);
	return 0;
}

void printStringArray(char* arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%s\n", arr[i]);
		puts(arr[i]);  // 위 아래 동일
	}	
	printf("\n");
}

void swap(char** xp, char** yp)
{
	char* ptr = *xp;  // 문자열을 가리키는 포인터의 포인터(주소)에서 indirection하면 문자열의 첫번째 character을 가리키는 포인터
	*xp = *yp;  // 값을 indirection으로 찾아서 바꾼다.
	*yp = ptr;
}

void selectionSort(char* arr[], int n)
{
	int i, j, min_idx;
	
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n ; j++)
		{
			if (strcmp(arr[j], arr[min_idx]) < 0)
			{
				min_idx = j;
			}
		}
		swap(&arr[i], &arr[min_idx]);

		/*
		char* temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
		*/
	}

}
