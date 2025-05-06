#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int num1 = 0;
	printf("홀수(1) 또는 짝수(0)를 정하세요: ");
	

	while (1)
	{
		int jud = scanf("%d", &num1);
		if (jud == EOF) break;

		srand(time(NULL));
		int num = (unsigned)rand();

		if (num % 2 == 0 && num1 == 0)
		{
			printf("맞았습니다.");
			break;
		}
		else if (num % 2 == 1 && num1 == 1)
		{
			printf("맞았습니다.");
			break;
		}
		else
			printf("틀렸습니다. 다시 홀수(1) 또는 짝수(0)를 정하세요: ");
	}
	rewind(stdin);

	return 0;
}