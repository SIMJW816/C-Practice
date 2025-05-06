#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int sub = 0;
	int max = 0, min = 0, sum = 0;

	printf("Input Subject number (>=3): ");
	int eo = scanf("%d", &sub);

	if (eo == EOF) exit(1);

	while (sub < 3)
	{
		printf("Wrong number! input again: ");
		eo = scanf("%d", &sub);
		if (eo == EOF) exit(1);
	}

	int* grade = malloc(sizeof(int) * sub);

	for (int i = 0; i < sub; i++)
	{
		grade[i] = rand() % 100 + 1;
		printf("%d ", grade[i]);
	}

	for (int i = 0; i < sub; i++)
	{
		min = grade[0];

		if (max < grade[i])
			max = grade[i];
		else if (min > grade[i])
			min = grade[i];

		sum += grade[i];
	}

	printf("max: %d, min: %d, avg: %.1lf", max, min, (double)(sum - max - min)/(sub-2));
	
	free(grade);
	
	return 0;
}