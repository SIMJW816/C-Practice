#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Gu_Num 25

void PrintPtr(const char** arr, int size);
void PrintFile(char** arr, const char* fname, int size);
void Swap(char** arr1, char** arr2);
void Bubble(char** arr, int size);
char** BuildGuNameArrFromFile(const FILE* fP);
void Free(char** arr, int size);

int main(void)
{
	FILE* fP;

	errno_t eNo = fopen_s(&fP, "guNames.txt", "rt");
	if (eNo) return -1;

	char** guNameArr = BuildGuNameArrFromFile(fP);
	fclose(fP);

	Bubble(guNameArr, Gu_Num);
	PrintPtr(guNameArr, Gu_Num);
	PrintFile(guNameArr, "guNamesSorted.txt", Gu_Num);
	Free(guNameArr, Gu_Num);

	return 0;
}

char** BuildGuNameArrFromFile(const FILE* fP)
{
	char guName[30] = "";
	int idx = 0;

	char** guArr = malloc(sizeof(char**) * Gu_Num);
	if (guArr == NULL)
	{
		printf("오류입니다...");
		exit(1);
	}

	while (fgets(guName, sizeof(guName), fP))
	{
		guArr[idx] = malloc(strlen(guName) + 1);
		if (guArr[idx] == NULL)
		{
			printf("오류입니다...");
			exit(1);
		}
		guName[strcspn(guName, "\n")] = 0;
		strcpy(guArr[idx], guName);

		idx++;
	}
	return guArr;
}

void Swap(char** arr1, char** arr2)
{
	char* temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

void Bubble(char** arr, int size)
{
	for (int i = 0, to = size - 1; i < size - 1; i++, to--)
		for (int j = 0; j < to; j++)
			if (strcmp(arr[j], arr[j + 1]) > 0)
				Swap(&arr[j], &arr[j + 1]);
}

void PrintPtr(const char** arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%s\n", arr[i]);
}

void PrintFile(char** arr, const char* fname, int size)
{
	FILE* fp;
	errno_t eNo = fopen_s(&fp, fname, "wt");
	if (eNo) return -1;

	for(int i = 0; i < size; i++)
		fprintf(fp,"%s\n", arr[i]);
	
	fclose(fp);
}
void Free(char** arr, int size)
{
	for (int i = 0; i < size; i++)
		free(arr[i]);
	free(arr);
}