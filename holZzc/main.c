#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int num1 = 0;
	printf("Ȧ��(1) �Ǵ� ¦��(0)�� ���ϼ���: ");
	

	while (1)
	{
		int jud = scanf("%d", &num1);
		if (jud == EOF) break;

		srand(time(NULL));
		int num = (unsigned)rand();

		if (num % 2 == 0 && num1 == 0)
		{
			printf("�¾ҽ��ϴ�.");
			break;
		}
		else if (num % 2 == 1 && num1 == 1)
		{
			printf("�¾ҽ��ϴ�.");
			break;
		}
		else
			printf("Ʋ�Ƚ��ϴ�. �ٽ� Ȧ��(1) �Ǵ� ¦��(0)�� ���ϼ���: ");
	}
	rewind(stdin);

	return 0;
}