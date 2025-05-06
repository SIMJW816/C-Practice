#include "declarations.h"

int main(void)
{

	//struct Person p1 = { 23, "심재욱" };

	char* cities[] = { "new york", "tokyo",   "shanghai", "paris",   "bangkok",	"london",   "toronto", "seoul",    "sydney", "berlin" }; //문자열 상수를 바꿀 수 없기 때문에 다른 배열에 문자열을 할당한 후에 변경
	
	char** strPtrArr = BuildPtrArr(cities, City_Num);

	Cnvt2Upper(strPtrArr, City_Num);
	Sort(strPtrArr, City_Num);
	Print2File(strPtrArr, City_Num, "upperSortedCityNames.txt");
	PrintPtrStrArr(strPtrArr, City_Num);

	FreeMem(strPtrArr, City_Num);

	return 0;
}

//char cities1[][20] = { "new york", "tokyo",   "shanghai", "paris",  "bangkok", 	"london",   "toronto", "seoul",    "sydney", "berlin" }; //열에 크기를 줘야함
	//cities[0][0] = 'N'; 문자열 포인터 배열은 이런 식으로 대입이 안 됨 cities는 스택에 할당, 문자열 상수등은 데이터에 할당
	//cities1[0][0] = 'N'; // 2차원 문자 배열에는 가능!
	//printf("%s\n", cities1[0]);