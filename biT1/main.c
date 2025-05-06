#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num = 0;

	printf("input num: ");
	scanf("%d", &num);

	for (int i = 31; i >= 0; i--)
	{
		printf("%d", num >> i & 1);
		if (i % 4 == 0) printf(" ");
	}

	return 0;
}