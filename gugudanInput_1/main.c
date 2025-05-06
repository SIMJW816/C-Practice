#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int dan = 0;

	do
	{
		printf("input dan (0 for stop): ");
		scanf("%d", &dan);
		if (dan == 0) {
			printf("Wrong dan....\n");

			continue;
		}
		for (int i = 2; i <= 9; i++)
			printf("%d x %d = %d\n", dan, i, dan * i);

		printf("\n");
	} while (dan != 0);
	

	return 0;
}