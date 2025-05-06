#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 20

void Swap(int** arr1, int** arr2);
void bubble(int* arr, int size);
void select(int* arr, int size);

int main(void)
{
	srand(time(NULL));
	int Rnum[n] = { 0, };
	int copy[n] = { 0, };

	for (int i = 0; i < n; i++)
		Rnum[i] = rand() % 200 - 100;
	memcpy(copy, Rnum, sizeof(int) * n);

	printf("Origanl: ");
	for (int i = 0; i < n; i++)
		printf("%d ", copy[i]);
	printf("\n");

	bubble(copy, n);
	printf("Bubble sort(Ascending): ");
	for (int i = 0; i < n; i++)
		printf("%d ", copy[i]);
	printf("\n");

	select(copy, n);
	printf("Selcet Sort(Descending): ");
	for (int i = 0; i < n; i++)
		printf("%d ", copy[i]);
	printf("\n");

	return 0;
}

void Swap(int* arr1, int* arr2)
{
	int temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

void bubble(int* arr, int size)
{
	for (int i = 0, to = size - 1; i < size - 1; i++, to--)
		for (int j = 0; j < to; j++)
			if (arr[j] > arr[j + 1])
				Swap(&arr[j], &arr[j + 1]);
}

void select(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
			if (arr[i] < arr[j])
				Swap(&arr[i], &arr[j]);
	}
}