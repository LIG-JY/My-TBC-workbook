#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	// strcmp()

void swap(int* xp, int* yp);	//Note: Optional
void printArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main()
{
	int arr[] = { 65, 25, 12, 22, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, n);

	printArray(arr, n);
	return 0;
}

void printArray(char* arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;  // 값을 indirection으로 찾아서 바꾼다.
	*yp = temp;
}

void selectionSort(char* arr[], int n)
{
	int i, j, min_idx;
	
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n ; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		swap(&arr[i], &arr[min_idx]);
	}

}
