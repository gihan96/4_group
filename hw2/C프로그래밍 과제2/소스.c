#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
	char Title[20];
	char Author[20];
	char Press[20];
	int Page;
	int Price;
	char Borrow[20];
};

typedef struct Book Books;

Books B[5] = {
	{"Truth", "John", "Century", 300, 20000},
	{"Love", "Paul", "Goods", 200, 15000},
	{"Joy", "James", "Cookie", 250, 18000},
	{"Thanks", "Mark", "Saesong", 240, 21000},
	{"God", "Johnson", "Jungjo", 450, 35000}
};

void AddBorrow(Books* a, int Size);
void PrintList();
void PrintListBrrow();
void PrintListBooks(Books* a, int Size);
void SearchBook(Books* a, int Size);
void BorrowBook(Books* a, int Size);
void ReturnBook(Books* a, int Size);

int main(void)
{
	
	int ArySize = sizeof(B) / sizeof(B[0]);
	AddBorrow(B, ArySize);
	char search[20];
	while (1)
	{
		printf("-------------------------------------------\n");
		printf("%7s %10s %7s %7s %7s\n", "1��", "2��", "3��", "4��", "5��");
		printf("-------------------------------------------\n");
		printf("[���� ���]  [�˻�]  [����]  [�ݳ�]  [����]\n");
		printf("-------------------------------------------\n");
		printf("���� : ");
		gets(search);

		if (strcmp(search, "�������") == 0 || strcmp(search, "���� ���") == 0 || strcmp(search, "1") == 0)
		{
			PrintListBooks(B, ArySize);

		}
			

		else if (strcmp(search, "�˻�") == 0 || strcmp(search, "2") == 0)
		{
			SearchBook(B, ArySize);
			getchar();

		}
			

		else if (strcmp(search, "����") == 0 || strcmp(search, "3") == 0)
		{
			BorrowBook(B, ArySize);
			getchar();
		}

		else if (strcmp(search, "�ݳ�") == 0 || strcmp(search, "4") == 0)
		{
			ReturnBook(B, ArySize);
			getchar();
		}

		else if (strcmp(search, "����") == 0 || strcmp(search, "5") == 0)
		{
			printf("���α׷��� �����մϴ�.\n");
			system("pause");
			break;
		
		}

		else
			printf("�߸� �Է��߽��ϴ�. �ٽ� �Է��� �ּ���.\n");

			

	}
	return 0;

}


void AddBorrow(Books* a, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		strcpy(a[i].Borrow, "available");
	}
}
void PrintList()
{
	printf("%-10s %-10s %-10s %-10s %-10s\n", "Title", "Author", "Press", "Page", "Price");
	printf("%-10s %-10s %-10s %-10s %-10s\n", "----", "-----", "-----", "------", "----");
}

void PrintListBrrow()
{
	printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "Title", "Author", "Press", "Page", "Price", "borrow");
	printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "----", "-----", "-----", "------", "----", "-----");
}
void PrintListBooks(Books* a, int Size)
{
	PrintList();
	int i;
	for (i = 0; i < Size; i++)
	{		
		printf("%-10s %-10s %-10s %-10d %-10d\n", a[i].Title, a[i].Author, a[i].Press, a[i].Page, a[i].Price);
	}
	
	printf("\n");
}

void SearchBook(Books* a, int Size)
{
	char booktitle[20];
	printf("�˻��� ������ �����ϼ��� :  ");
	scanf("%s", booktitle);

	for (int i = 0; i < Size; i++)
	{
		if (_stricmp(booktitle, a[i].Title) == 0)
		{
			PrintListBrrow();
			printf("%-10s %-10s %-10s %-10d %-10d %-10s\n\n", a[i].Title, a[i].Author, a[i].Press, a[i].Page, a[i].Price, a[i].Borrow);
			return;
		}
	}

	printf("�Է��Ͻ� ������ ���� �����ϰ� ���� �ʽ��ϴ�.\n\n");
}

void BorrowBook(Books* a, int Size)
{
	char booktitle[20];
	printf("������ å�� �̸��� �����ϼ��� : ");
	scanf("%s", booktitle);


	for (int i = 0; i < Size; i++)
	{
		if (_stricmp(booktitle, a[i].Title) == 0)
		{
			if (_stricmp(a[i].Borrow, "available") == 0)
			{
				printf("���� �Ǿ����ϴ�.\n");
				strcpy(a[i].Borrow, "borrowing");
				PrintListBrrow();
				printf("%-10s %-10s %-10s %-10d %-10d %-10s\n\n", a[i].Title, a[i].Author, a[i].Press, a[i].Page, a[i].Price, a[i].Borrow);
				return;
			}

			else
			{
				printf("���� ���̶� ���� �� �� �����ϴ�.\n");
				PrintListBrrow();
				printf("%-10s %-10s %-10s %-10d %-10d %-10s\n\n", a[i].Title, a[i].Author, a[i].Press, a[i].Page, a[i].Price, a[i].Borrow);
				return;
			}
		}
	}

	printf("�Է��Ͻ� ������ ���� �����ϰ� ���� �ʽ��ϴ�.\n\n");
}

void ReturnBook(Books* a, int Size)
{
	char booktitle[20];
	printf("�ݳ��Ͻ� å�� �̸��� �����ϼ��� : ");
	scanf("%s", booktitle);


	for (int i = 0; i < Size; i++)
	{
		if (_stricmp(booktitle, a[i].Title) == 0)
		{
			if (_stricmp(a[i].Borrow, "borrowing") == 0)
			{
				printf("å�� �ݳ��Ǿ����ϴ�.\n");
				strcpy(a[i].Borrow, "available");
				PrintListBrrow();
				printf("%-10s %-10s %-10s %-10d %-10d %-10s\n\n", a[i].Title, a[i].Author, a[i].Press, a[i].Page, a[i].Price, a[i].Borrow);
				return;
			}

			else
			{
				printf("���� ���� ���� å�Դϴ�.\n");
				PrintListBrrow();
				printf("%-10s %-10s %-10s %-10d %-10d %-10s\n\n", a[i].Title, a[i].Author, a[i].Press, a[i].Page, a[i].Price, a[i].Borrow);
				return;
			}
		}
	}

	printf("�Է��Ͻ� ������ ���� �����ϰ� ���� �ʽ��ϴ�.\n\n");
}