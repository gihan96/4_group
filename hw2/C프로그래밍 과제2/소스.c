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
		printf("%7s %10s %7s %7s %7s\n", "1번", "2번", "3번", "4번", "5번");
		printf("-------------------------------------------\n");
		printf("[도서 목록]  [검색]  [대출]  [반납]  [종료]\n");
		printf("-------------------------------------------\n");
		printf("선택 : ");
		gets(search);

		if (strcmp(search, "도서목록") == 0 || strcmp(search, "도서 목록") == 0 || strcmp(search, "1") == 0)
		{
			PrintListBooks(B, ArySize);

		}
			

		else if (strcmp(search, "검색") == 0 || strcmp(search, "2") == 0)
		{
			SearchBook(B, ArySize);
			getchar();

		}
			

		else if (strcmp(search, "대출") == 0 || strcmp(search, "3") == 0)
		{
			BorrowBook(B, ArySize);
			getchar();
		}

		else if (strcmp(search, "반납") == 0 || strcmp(search, "4") == 0)
		{
			ReturnBook(B, ArySize);
			getchar();
		}

		else if (strcmp(search, "종료") == 0 || strcmp(search, "5") == 0)
		{
			printf("프로그램을 종료합니다.\n");
			system("pause");
			break;
		
		}

		else
			printf("잘못 입력했습니다. 다시 입력해 주세요.\n");

			

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
	printf("검색할 도서를 선택하세요 :  ");
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

	printf("입력하신 도서는 현재 보유하고 있지 않습니다.\n\n");
}

void BorrowBook(Books* a, int Size)
{
	char booktitle[20];
	printf("대출할 책의 이름을 선택하세요 : ");
	scanf("%s", booktitle);


	for (int i = 0; i < Size; i++)
	{
		if (_stricmp(booktitle, a[i].Title) == 0)
		{
			if (_stricmp(a[i].Borrow, "available") == 0)
			{
				printf("대출 되었습니다.\n");
				strcpy(a[i].Borrow, "borrowing");
				PrintListBrrow();
				printf("%-10s %-10s %-10s %-10d %-10d %-10s\n\n", a[i].Title, a[i].Author, a[i].Press, a[i].Page, a[i].Price, a[i].Borrow);
				return;
			}

			else
			{
				printf("대출 중이라 대출 할 수 없습니다.\n");
				PrintListBrrow();
				printf("%-10s %-10s %-10s %-10d %-10d %-10s\n\n", a[i].Title, a[i].Author, a[i].Press, a[i].Page, a[i].Price, a[i].Borrow);
				return;
			}
		}
	}

	printf("입력하신 도서는 현재 보유하고 있지 않습니다.\n\n");
}

void ReturnBook(Books* a, int Size)
{
	char booktitle[20];
	printf("반납하실 책의 이름을 선택하세요 : ");
	scanf("%s", booktitle);


	for (int i = 0; i < Size; i++)
	{
		if (_stricmp(booktitle, a[i].Title) == 0)
		{
			if (_stricmp(a[i].Borrow, "borrowing") == 0)
			{
				printf("책이 반납되었습니다.\n");
				strcpy(a[i].Borrow, "available");
				PrintListBrrow();
				printf("%-10s %-10s %-10s %-10d %-10d %-10s\n\n", a[i].Title, a[i].Author, a[i].Press, a[i].Page, a[i].Price, a[i].Borrow);
				return;
			}

			else
			{
				printf("대출 되지 않은 책입니다.\n");
				PrintListBrrow();
				printf("%-10s %-10s %-10s %-10d %-10d %-10s\n\n", a[i].Title, a[i].Author, a[i].Press, a[i].Page, a[i].Price, a[i].Borrow);
				return;
			}
		}
	}

	printf("입력하신 도서는 현재 보유하고 있지 않습니다.\n\n");
}