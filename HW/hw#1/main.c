#include <stdio.h>

int Max(int* pArr, int size);
int Min(int* pArr, int size);
void Sorting(int* pArr, int size);

int main(void)
{
	int b[] = {20, 34, 12, 24, 54, 91, 9, 40, 81, 10};
	int ArySize = sizeof(b) / sizeof(int);
	int MaxNun = Max(b, ArySize);
	int MinNum = Min(b, ArySize);

	printf("최대값 : %d\n", MaxNun);
	printf("최소값 : %d\n", MinNum);
	Sorting(b, ArySize);
	return 0;

}

int Max(int* pArr, int size)
{
	int p = *pArr;
	for (int i = 0; i < size; i++)
		if (p < *(pArr + i))
			p = *(pArr + i);
	return p;
}
int Min(int* pArr, int size)
{
	int p = *pArr;
	for (int i = 0; i < size; i++)
		if (p > *(pArr + i))
			p = *(pArr + i);
	return p;
}
void Sorting(int* pArr, int size)
{
	int p = *pArr;
	int i, j;
	printf("[정렬 전 배열]\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", *(pArr + i));
	}
	printf("\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size - 1 - i; j++)
			if (*(pArr + j) < *(pArr + j + 1))
			{
				p = *(pArr + j);
				*(pArr + j) = *(pArr + j + 1);
				*(pArr + j + 1) = p;
			}

	printf("[정렬 후 배열]\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", *(pArr + i));
	}


	
}