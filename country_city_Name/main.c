#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define Name_Len 50


void Print1(char (*arr)[Name_Len], int size);
void Print2(char** arr, int size);
void Swap1(char (*arr1)[Name_Len], char (*arr2)[Name_Len]);
void Bubble1(char (*arr)[Name_Len], int size);
void Swap2(char **arr1, char **arr2);
void Bubble2(char** arr, int size);

int main(void)
{
	char  nations[][Name_Len] = { "unIted StAtes", "sOuTh aFrIcA", "new ZeALand", "jaPan", "BrAZil", "doMinICan rePUbliC", "cAnAdA", "unITed aRAb EMirAtes", "soUTh KoReA", "sAuDi arAbiA" };

	char* cities[] = { "nEw YoRk", "ToKyO", "lOnDon", "paRiS", "sYDNeY", "baNgKoK", "mEXiCo CiTy", "beRLiN", "LoS aNgeLeS", "cApE ToWn" };

	int size1 = (sizeof(nations)) / Name_Len;
	int size2 = (sizeof cities) / sizeof(char*);
	
	Bubble1(nations, size1);
	Print1(nations, size1);

	printf("\n");

	Bubble2(cities, size2);
	Print2(cities, size2);

	return 0;
}

void Print1(char (*arr)[Name_Len], int size)
{
	for (int i = 0; i < size; i++)
		printf("%s\n", arr[i]);
}
void Print2(char **arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%s\n", arr[i]);
}
void Swap1(char (*arr1)[Name_Len], char (*arr2)[Name_Len])
{
	char temp[Name_Len];
	strcpy(temp, *arr1);
	strcpy(*arr1, *arr2);
	strcpy(*arr2, temp);
	
}
void Bubble1(char (*arr)[Name_Len], int size)
{
	for (int i = 0, to = size - 1; i < size - 1; i++, to--)
		for (int j = 0; j < to; j++)
			if (strcmp(arr[j], arr[j + 1]) > 0)
				Swap1(&arr[j], &arr[j + 1]);
}
void Swap2(char **arr1, char **arr2)
{
	char *temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;

}
void Bubble2(char** arr, int size)
{
	for (int i = 0, to = size - 1; i < size - 1; i++, to--)
		for (int j = 0; j < to; j++)
			if (strcmp(arr[j], arr[j + 1]) > 0)
				Swap2(&arr[j], &arr[j + 1]);
}