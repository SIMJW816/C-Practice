#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define Max_Str_Line_Len 2000
#define Max_Word_Len 50

bool isLetterOrNum(const char ch);
bool isLegalSpecialLetter(const char ch);
void FreeMem(char** pArr, int size);
void SwapPtrArr(char** str1, char** str2);
void Sort(char** strArr, int size);
void PrintArr(char** arr, int size);
void Print2File(const char** arr, const int size, const char* fName);
int ExtractWords(FILE* pF1, FILE * pF2);
char** BuildStrPtrArr(const FILE* pF);

int main(void)
{
	FILE* pOrgF, * pWordsF;

	errno_t errNo = fopen_s(&pOrgF, "orgStr.txt", "rt");
	errno_t errNo2 = fopen_s(&pWordsF, "words.txt", "wt");
	if (errNo || errNo2) return -1;
	int wordNum = ExtractWords(pOrgF, pWordsF);
	printf("**Word #: %d\n", wordNum);

	fclose(pOrgF);
	fclose(pWordsF);

	errNo = fopen_s(&pWordsF, "words.txt", "rt");
	if (errNo) return -1;
	char **strPtrArr = BuildStrPtrArr(pWordsF);
	if (strPtrArr == NULL) printf("memory NULL \n");

	fclose(pWordsF);

	Sort(strPtrArr, wordNum);
	//PrintArr(strPtrArr, wordNum);
	Print2File(strPtrArr, wordNum, "sortedWords.txt");
	FreeMem(strPtrArr, wordNum);

	return 0;
}

int ExtractWords(FILE* pF1, FILE* pF2) {
	char* pDelimeiters = " ,.;:\"?/\n\t()"; //\0값을 넣으면 안됨 뒤에 있는 제외할 문자가 무시
	//char* pDelimeiters = "/.\"\n";
	char* pNext = 0;

	char wdName[Max_Str_Line_Len] = { 0, };
	int wordNum = 0;

	while (fgets(wdName, sizeof(wdName), pF1) != NULL)
	{
		char* pToken = strtok_s(wdName, pDelimeiters, &pNext); // 파일에서 문자열 추출

		while (pToken != NULL) // 문자열에서 단어 추출
		{
			if (isLetterOrNum(*pToken))//세부조건
			{
				for (int i = 0; i < strlen(pToken); i++)
					if (!isLegalSpecialLetter(pToken[i]) && !isLetterOrNum(pToken[i]))
					{
						pToken[i] = '\0';
						break;
					}
				fprintf(pF2, "%s\n", pToken);
				wordNum++;
			}
			pToken = strtok_s(NULL, pDelimeiters, &pNext);
		}
	}
	fclose(pF2);	
	return wordNum;
}

bool isLetterOrNum(const char ch) {
	if ((ch >= 'A' && ch <= 'Z') ||
		(ch >= 'a' && ch <= 'z') ||
		(ch >= '0' && ch <= '9')) 
		return true;
	else 
		return false;
}

bool isLegalSpecialLetter(const char ch) {
	if ((ch == '_' || ch == '-' || ch == '\''))
		return true;
	else
		return false;
}

char** BuildStrPtrArr(const FILE* pF)
{
	char dictName[Max_Word_Len] = "";
	int idx = 0;

	char** dictArr = (char**)malloc(sizeof(char*) * Max_Str_Line_Len);
	//memset(guArr, 0, sizeof(char*) * Max_Str_Line_Len); 
	if (dictArr == NULL) return NULL;

	while (fgets(dictName, sizeof(dictName), pF) != NULL && idx < Max_Str_Line_Len)
	{
		
		if (dictArr[idx] == NULL)
		{
			printf("오류입니다....\n");
			exit(1);
		}

		dictName[strcspn(dictName, "\n")] = 0;
		//dictName[strlen(dictName) - 1] = 0; 위에 것과 같은 동작
		dictArr[idx] = malloc(strlen(dictName) + 1);
		strcpy(dictArr[idx], dictName);

		idx++;
	}
	return dictArr;
}

void FreeMem(char** pArr, int size)
{
	for (int i = 0; i < size; i++)
		free(pArr[i]);
	free(pArr);
}


void SwapPtrArr(char** str1, char** str2) {

	char* temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void Sort(char** strArr, int size) {
	for (int i = 0, to = size - 1; i < size - 1; i++, to--)
		for (int j = 0; j < to; j++)
			if ((strcmp(strArr[j], strArr[j + 1])) > 0)
				SwapPtrArr(&strArr[j], &strArr[j + 1]);
}

void PrintArr(char** arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%s\n", arr[i]);
}

void Print2File(const char** arr, const int size, const char* fName) {
	FILE* fp;
	errno_t eNo = fopen_s(&fp, fName, "wt");
	if (eNo) return -1;

	fseek(fp, 0, SEEK_SET);
	
	for (int i = 0; i < size && arr[i] != NULL; i++)
		fprintf(fp, "%s\n", arr[i]);

	fclose(fp);
}