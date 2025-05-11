#include "declaration.h"

int FreeMem4Int(struct Lotto* pArr[], int size)
{
	for (int i = 0; i < size; i++)
		if(pArr[i] != NULL)
			free(pArr[i]);

	return 0;
}							   //struct Lotto **lottoNumArr 이중 포인터로 받아도 됨
int BuildLottoNumWinFrequencyArr(struct Lotto* lottoNumArr[], 
	const int lottoNums[], int size)
{
	for (int i = 0; i < size; i++)
	{
		lottoNumArr[i] = malloc(sizeof(struct Lotto));
		lottoNumArr[i]->lottoNum = i + 1;
		lottoNumArr[i]->frequency = lottoNums[i];
	}
	return 0;
}
void Store2File(char* fname ,struct Lotto* ptrArr[], int size)
{

	FILE* fp = fopen(fname, "wt");
	if (fp == NULL) return;

	for (int i = 0; i < size; i++)
		fprintf(fp, "%2d (%d)\n", ptrArr[i]->lottoNum, ptrArr[i]->frequency);
	fclose(fp);
}
void PrintGraph(int num)
{
	for (int i = 0; i < num; i++)
		printf("-");
}
void PrintLottoNumWinFrequency(struct Lotto* ptrArr[], int size)
{
	for (int i = 0; i < LOTTO_MAX; i++)
	{
		printf("%2d (%d회): ", ptrArr[i]->lottoNum, ptrArr[i]->frequency);
		PrintGraph(ptrArr[i]->frequency / 2);
		printf("\n");
	}
}
void SwapLottoNums(struct Lotto** i, struct Lotto** j)
{
	struct Lotto* temp = *i;
	*i = *j;
	*j = temp;
}
void SortLottoNums(struct Lotto* ptrArr[], int size)
{
	for (int i = 0, to = size - 1; i < size - 1; i++, to--)
		for (int j = 0; j < to; j++)
			if (ptrArr[j]->frequency < ptrArr[j + 1]->frequency)
				SwapLottoNums(&ptrArr[j], &ptrArr[j + 1]);
}