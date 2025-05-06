#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int Fibo(int n)
//{
//	if (n == 1)
//		return 1;
//	else if (n == 2)
//		return 1;
//	else
//		return Fibo(n - 2) + Fibo(n - 1);
//}
//
//int main(void)
//{
//	int n = 0;
//	printf("input N (>= 3): ");
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//		printf("%d ", Fibo(i));
//
//	printf("\nFibonacci(n): %d\n", n, Fibo(n));
//
//	return 0;
//}

int main(void)
{
	int n, n_2 = 1, n_1 = 1, F = 0;

	printf("Input N(>= 3): ");
	scanf("%d", &n);

	while (n < 3)
	{
		printf("Wrong num.. input again: ");
		scanf("%d", &n);
	}

	printf("1 1 ");
	for (int i = 3; i <= n; i++)
	{
		F = n_1 + n_2;
		n_2 = n_1;
		n_1 = F;
		printf("%d ", F);
	}
	printf(": %d \n", F);


	return 0;
}