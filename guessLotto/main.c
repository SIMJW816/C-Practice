#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));

	int LottoNum[6] = { 0, };
	int myNum[6] = { 0, };
	int cnt = 0, Rnum = 0;

	while (1)
	{
		printf("input 6 lotto num(1~45): ");

		for (int i = 0; i < 6; i++)
			scanf("%d", &myNum[i]);
			
		printf("Lotto nums: ");

		for (int i = 0; i < 6; i++)
		{
			Rnum = (unsigned)rand() % 45 + 1;
			LottoNum[i] = Rnum;
			printf("%d ", LottoNum[i]);
		}

		printf("\nMatched nums: ");

		cnt = 0;

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (LottoNum[i] == myNum[j])
				{
					printf("%d ", LottoNum[i]);
					cnt++;
				}
			}
		}
		printf(" -> %d num(s)\n", cnt);
	}
	return 0;
}