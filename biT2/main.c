#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	int num = 0;

	printf("input num: ");
	scanf("%d", &num);

	for (int i = 31; i >= 0; i--)
	{
		if ((int)pow(2, i) & num)
			printf("%d", 1);
		else printf("%d", 0);

		if (i % 4 == 0) printf(" ");
	}

	return 0;
}