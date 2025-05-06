#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define Menu_num 5
#define Name_Len 50

void Swap(char* arr1, char* arr2);
void Trans(char (*arr1)[Name_Len], char (*arr2)[Name_Len], int size);
void Print(char* arr, char (**arr1)[], int size);

int main(void)
{

	char  sellerArr[][Name_Len] = { "Black Bean Sauce Noodle",
	"Spicy Seafood Noodle Soup",
	"Extra Spicy Seafood Noodle Soup",
	"Udong",
	"Spicy Black Bean Sauce Noodles with Seafood"
	};

	char  guestArr[][Name_Len] = { "5,000 won",
		"6,000 won",
		"8,000 won",
		"7,500 won",
		"10,000 won"
	};

	printf("** Before:\n");
	Print("-------Seller has------", sellerArr, Menu_num);
	Print("-------Guest has------", guestArr, Menu_num);

	Trans(sellerArr, guestArr, Menu_num);
	printf("\n** After: \n");
	Print("-------Seller has------", sellerArr, Menu_num);
	Print("-------Guest has------", guestArr, Menu_num);

	return 0;
}
void Swap(char(*arr1)[Name_Len], char(*arr2)[Name_Len])
{
	char temp[Name_Len] = { 0, };
	strcpy(temp, *arr1);
	strcpy(*arr1, *arr2);
	strcpy(*arr2, temp);
}

void Trans(char (*arr1)[Name_Len], char (*arr2)[Name_Len], int size)
{
	for (int i = 0; i < size; i++)
		Swap(&arr1[i], &arr2[i]);
}

void Print(char* arr, char (*arr1)[Name_Len], int size)
{
	printf("%s\n", arr);

	for (int i = 0; i < size; i++)
		printf("%s\n", arr1[i]);
}