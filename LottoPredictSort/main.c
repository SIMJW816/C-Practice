#include "declaration.h"

int main()
{
	FILE* fp;
	int	lotto_nums[LOTTO_MAX] = { 0, };
	int	num;

	if (!(fp = fopen("lotto_number.txt", "rt"))) return 1;

	fseek(fp, 0, SEEK_SET);

	while (fscanf(fp, "%d ", &num) != EOF)
		lotto_nums[num - 1]++;

	fclose(fp);

	for (int i = 0; i < LOTTO_MAX; i++)
	{
		printf("%2d (%d회): ", i + 1, lotto_nums[i]);
		PrintGraph(lotto_nums[i] / 2);
		printf("\n");
	}

	struct Lotto* lottoNumRank[LOTTO_MAX];
	BuildLottoNumWinFrequencyArr(lottoNumRank, lotto_nums, LOTTO_MAX);
	SortLottoNums(lottoNumRank, LOTTO_MAX);

	printf("\nLotto num win frequency rank: \n");
	PrintLottoNumWinFrequency(lottoNumRank, LOTTO_MAX);

	Store2File("winFrequencyRank.txt", lottoNumRank, LOTTO_MAX);

	FreeMem4Int(lottoNumRank, LOTTO_MAX);

	return 0;
}