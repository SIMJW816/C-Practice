#include "declarations.h"

int main(void)
{

	//struct Person p1 = { 23, "�����" };

	char* cities[] = { "new york", "tokyo",   "shanghai", "paris",   "bangkok",	"london",   "toronto", "seoul",    "sydney", "berlin" }; //���ڿ� ����� �ٲ� �� ���� ������ �ٸ� �迭�� ���ڿ��� �Ҵ��� �Ŀ� ����
	
	char** strPtrArr = BuildPtrArr(cities, City_Num);

	Cnvt2Upper(strPtrArr, City_Num);
	Sort(strPtrArr, City_Num);
	Print2File(strPtrArr, City_Num, "upperSortedCityNames.txt");
	PrintPtrStrArr(strPtrArr, City_Num);

	FreeMem(strPtrArr, City_Num);

	return 0;
}

//char cities1[][20] = { "new york", "tokyo",   "shanghai", "paris",  "bangkok", 	"london",   "toronto", "seoul",    "sydney", "berlin" }; //���� ũ�⸦ �����
	//cities[0][0] = 'N'; ���ڿ� ������ �迭�� �̷� ������ ������ �� �� cities�� ���ÿ� �Ҵ�, ���ڿ� ������� �����Ϳ� �Ҵ�
	//cities1[0][0] = 'N'; // 2���� ���� �迭���� ����!
	//printf("%s\n", cities1[0]);