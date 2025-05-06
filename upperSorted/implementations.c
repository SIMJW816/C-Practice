#define _CRT_SECURE_NO_WARNINGS

#include "declarations.h"

void PrintPtrStrArr(const char** arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%s\n", arr[i]);	/// 화면 출력시 이름 끝에 개행 문자 출력
}

void Print2File(const char** guArr, const int size, const char* fName) //const는 함수를 안전하게 만듦!
{
	FILE* pF = fopen(fName, "wt");

	for (int i = 0; i < size && guArr[i] != NULL; i++)
		fprintf(pF, "%s\n", guArr[i]);	/// append '\n'

	fclose(pF);
}

int	FreeMem(char** pArr, int size)
{
	for (int i = 0; i < size; i++)
		if (pArr[i] != NULL)	
			free(pArr[i]);

	free(pArr);

	return 0;
}

void Sort(char** strArr, int size)	// Bubble, ascending
{
	for (int i = 0, to = size - 1; i < size - 1; i++, to--)
		for (int j = 0; j < to; j++)
			if (strcmp(strArr[j], strArr[j + 1]) > 0)
				SwapPtrArr(&strArr[j], &strArr[j + 1]);
}

void SwapPtrArr(char** str1, char** str2)
{
	char* tmpStr;

	tmpStr = *str1;
	*str1 = *str2;
	*str2 = tmpStr;

}

char** Cnvt2Upper(char** strArr, int size)
{
	for (int i = 0; i < size; i++) {
		int  length = (int)strlen(strArr[i]);
		for (int j = 0; j < length; j++)
			strArr[i][j] = toupper(strArr[i][j]);
	}

	return  strArr;
}

char** BuildPtrArr(const char** strArr, int size)
{
	char** strPtrArr = malloc(sizeof(char*) * size);
	//memset(strPtrArr , 0, sizeof(char*) * size);  // good to try

	if (strPtrArr == NULL)	return NULL;

	for (int i = 0; i < size; i++) {
		int length = (int)strlen(strArr[i]);
		strPtrArr[i] = malloc(length + 1);
		//memset(strPtrArr[i], 0, length + 1);  // good to try

		if (strPtrArr[i] == NULL)	return NULL;
		//if (strPtrArr[strcspn(strPtrArr[i], " ")]) strPtrArr[i] = 0;
		strcpy(strPtrArr[i], strArr[i]);
	}

	return  strPtrArr;
}