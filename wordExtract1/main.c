#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Wd_num 300
#define St_Len 3000
#define Wd_Len 20

bool Exist(char (*wordArr)[Wd_Len], int cnt, char* pStr);
void Swap(char (*arr1)[Wd_Len], char (*arr2)[Wd_Len]);
void Bubble(char (*arr)[Wd_Len], int size);
void Print(char (*arr)[Wd_Len], int size);

int main(void)
{
	
	char strArrOrg[] = "Myanmar military denounced as 'inhumane' for continuing airstrikes after devastating earthquake Military accused of 'taking advantage' of biggest earthquake in a century to weaken rebel forces. Myanmar's military junta has continued bombing parts of the war-torn country even after the most powerful earthquake in over a century left hundreds dead and millions displaced. The 7.7-magnitude earthquake struck central Myanmar on Friday and sent powerful jolts into neighbouring China and Thailand. At least 1,700 people have been confirmed dead in Myanmar alone, 3,400 were injured and over 300 remained missing, the military-run government said on Sunday, as it continued to assess the full extent of the disaster. The earthquake was the biggest to hit Myanmar since 1912, according to the United States Geological Survey, and has devastated civilian infrastructure including the main highway running up the spine of the country. Many of the worst-hit areas have still not been reached by official agencies, with most rescue efforts being conducted by local residents removing rubble by hand. Across the border in Bangkok, rescuers raced to find survivors trapped under the rubble of a 33-storey skyscraper. At least 17 people have been killed in the Thai capital with 32 injured and 83 still missing as of Sunday evening. \"The UN special rapporteur on Myanmar, Tom Andrews\", said at least three government airstrikes were carried out on the largely rebel-controlled Sagaing region, the epicentre of the earthquake, hours after it struck on Friday. \"I'm calling upon the junta to just stop, stop any of its military operations. This is completely outrageous and unacceptable,\"he told BBC Burmese.";
	char strArrCpy[St_Len] = { 0, };

	printf("** String length: %zu\n", strlen(strArrOrg));
	memcpy(strArrCpy, strArrOrg, sizeof(strArrCpy) - 1);

	char* pDel = " ?-\t\n,.\'\"";
	char* pNext = 0;

	char* pToken = strtok_s(strArrCpy, pDel, &pNext);
	int longLen = 0, wordCnt = 0, orgWordCnt = 0;
	char* pLongStr = 0;

	char wordArr[Wd_num][Wd_Len] = { "", };

	while (pToken != NULL)
	{
		orgWordCnt++;

		if (!Exist(wordArr, wordCnt, pToken))
		{
			strcpy(wordArr[wordCnt++], pToken);

			int len = 0;
			if (longLen < (len = strlen(pToken)))
			{
				longLen = len;
				pLongStr = pToken;
			}
		}
		pToken = strtok_s(NULL, pDel, &pNext);
	}
	
	printf("Total words(duplicates): %d\n", orgWordCnt);
	printf("Total words(Unique words): %d\n", wordCnt);
	printf("Longest word: %s (%d) \n\n", pLongStr, longLen);

	printf("Before: \n");
	Print(wordArr, wordCnt);

	Bubble(wordArr, wordCnt);

	printf("\n\nAfter: \n");
	Print(wordArr, wordCnt);

	return 0;
}

bool Exist(char (*wordArr)[Wd_Len], int cnt, char* pStr)
{
	for (int i = 0; i < cnt; i++)
	{
		if (strcmp(wordArr[i], pStr) == 0)
			return true;
	}
	return false;
}

void Swap(char (*arr1)[Wd_Len], char (*arr2)[Wd_Len])
{
	char temp[Wd_Len];
	strcpy(temp, *arr1);
	strcpy(*arr1, *arr2);
	strcpy(*arr2, temp);
}

void Bubble(char (*arr)[Wd_Len], int size)
{
	for(int i = 0, to = size - 1; i < size - 1; i++, to--)
		for(int j = 0; j < to; j++)
			if(strcmp(arr[j], arr[j + 1]) > 0)
				Swap(&arr[j], &arr[j + 1]);
}

void Print(char (*arr)[Wd_Len], int size)
{
	for (int i = 0; i < size; i++)
		printf("%s ", arr[i]);
}