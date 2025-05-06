//#pragma once // 헤더파일에 있는 내용을 한번만 프로젝트에 포함을 시키겠다는 의미, include guard
#ifndef DECLARATIONS_H // 만약 포함되지 않는다면 포함시킨다. 하나의 블록으로 할 수 있다. 여러 블록을 포함할 수 있음
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