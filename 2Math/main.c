#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	double a, b, c;
	double root1 = 0 , root2 = 0;

	printf("2차방정식 입력(A*x*x + B*x + c = 0): ");
	scanf("%lf%lf%lf", &a, &b, &c);
	double Dis = (b * b) - (4 * a * c);

	if (Dis > 0)
	{
		root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		root2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

		printf("result: %.1lf, %.1lf\n", root1, root2);
	}
	else if (Dis == 0)
	{
		root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);

		printf("result: %.1lf\n", root1);
	}
	else
		printf("허근\n");

	return 0;
}