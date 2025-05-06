#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int WordNum(const char arr[], int leth)
{
	int cnt = 0;
	bool flag = false;

	for (int i = 0; i < leth; i++)
	{
		if (arr[i] != ' ')
		{
			if (!flag)
			{
				cnt++;
				flag = true;
			}
		}
		else
			flag = false;
	}
	return cnt;
}

int main(void)
{

	while (1)
	{
		char str[1000000] = { 0. };

		printf("Input your string: ");
		int rVal = scanf(" %[^\n]", str);

		if (rVal == EOF)
		{
			printf("Bye...\n");
			break;
		}

		int wordCnt = WordNum(str, strlen(str));
		printf("Word number: %d \n", wordCnt);
	}
	return 0;
}