#include <stdio.h>

int  myError(int a, int b)
{
	rewind(stdin);
	if (a == EOF) return 0;
	else if (b < 10 || b > 100 || a == 0)
		return 1;
	else return 2;
}