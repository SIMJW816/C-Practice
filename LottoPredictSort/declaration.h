#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define	LOTTO_MAX	45

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lotto //사용자 정의 자료형: struct , 기본 자료형: int, double, char
{		//Lotto는 태그 이름
	int lottoNum; //멤버 이름
	int frequency;
};

int FreeMem4Int(struct Lotto* pArr[], int size);
int BuildLottoNumWinFrequencyArr(struct Lotto* lottoNumArr[], const int lottoNums[], int size);
void Store2File(char* fname, struct Lotto* ptrArr[], int size);
void PrintGraph(int num);
void PrintLottoNumWinFrequency(struct Lotto* ptrArr[], int size);
void SwapLottoNums(struct Lotto** i, struct Lotto** j);
void SortLottoNums(struct Lotto* ptrArr[], int size);