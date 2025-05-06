//#pragma once // ������Ͽ� �ִ� ������ �ѹ��� ������Ʈ�� ������ ��Ű�ڴٴ� �ǹ�, include guard
#ifndef DECLARATIONS_H // ���� ���Ե��� �ʴ´ٸ� ���Խ�Ų��. �ϳ��� ������� �� �� �ִ�. ���� ����� ������ �� ����
#define DECLARATIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>   /// toupper

#define	City_Num 10

struct Person
{
	int age;
	char name[50];
};

void PrintPtrStrArr(const char** arr, int size);
void Print2File(const char** guArr, const int size, const char* fName);
int	FreeMem(char** pArr, int size);
void Sort(char** strArr, int size);
void SwapPtrArr(char** str1, char** str2);
char** Cnvt2Upper(char** strArr, int size);
char** BuildPtrArr(char** strArr, int size);

#endif