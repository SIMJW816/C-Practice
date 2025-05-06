#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

extern int myError(int a, int b);

int main(void)
{
	int num;
	srand(time(NULL));
	int Rnum = rand() % 91 + 10;

	while (1)
	{
		printf("Your number(10 ~ 100): ");
		int jud = scanf("%d", &num);
		
		if (myError(jud, num) == 0) break;
		else if(myError(jud, num) == 1)
		{
			printf("Wrong input...");
			continue;
		}

		else if (Rnum == num)
		{
			printf("That's it!\n");
			srand(time(NULL));
			Rnum = rand() % 91 + 10;
		}
		else if (Rnum > num) printf("Bigger! ");
		else printf("smaller! ");
	}

	return 0;
}