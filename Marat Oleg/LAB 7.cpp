#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "DL.h"
#pragma warning(disable: 4996)

Record rec;
names rec1;
bool a = false;

void menu6(void)
{
	while (1)
	{

		char nameoffaildel[15] = "del";
		setlocale(LC_ALL, "Russian");
		//system("cls");
		printf("======\n");
		printf(" 1)Удалить читателя 2)Посмотреть историю удалённых 3)  0)Назад\n");
		char menu = getch();

		system("cls");
		switch (menu)
		{
		case '1':
			fflush(stdin);
			printf("Фамилия удаляемого читателя:\n");
			gets(rec.surname);
			a = Delete(rec.surname, a);
			Display();
			break;
		case '2':
			DelPrint(rec, nameoffaildel);
			break;
		case '0':
			return;
			break;
		}
	}
}

void menu2(void)
{
	while (1)
	{
		setlocale(LC_ALL, "Russian");
		char k[15];
		int x;
		char nameoffile1[15] = "Books";
		fflush(stdin);
		printf("======\n");
		printf(" 1)Докупить экземпляры 2)Добавить новую книгу  0)Назад\n");
		char menu = getch();
		system("cls");
		switch (menu)
		{
		case '1':
		{
			printf("Введите название книги: ");
			scanf("%s", &k);
			printf("Введите количество экземпляров после докупки: ");
			printf("\n");
			scanf("%u", &x);
			printf("\n");
			namesPrint(rec1, k, x, nameoffile1);
			break;
		}
		case '2':
			Addname(rec1, nameoffile1);
			break;
		case '0':
			return;
			break;
		}
	}
}

void menu1(void)
{
	while (1)
	{
		setlocale(LC_ALL, "Russian");
		//system("cls");
		printf("======\n");
		printf(" 1)Поиск по имени 2)Поиск по фамилии 3)Поиск по номеру группы 4)Поиск по телефону 5)Поиск по email 6)Поиск по примечанию 0)Назад\n");
		char menu = getch();
		system("cls");
		switch (menu)
		{
		case '1':
			printf("Введите имя читателя:\n");
			scanf("%s", &rec.name);
			Search_name(rec.name);
			break;
		case '2':
			printf("Введите фамилию читателя:\n");
			scanf("%s", &rec.surname);
			Search_surname(rec.surname);
			break;
		case '3':
			printf("Введите номер группы читателя:\n");
			scanf("%s", &rec.group);
			Search_group(rec.group);
			break;
		case '4':
			printf("Введите телефон читателя:\n");
			scanf("%s", &rec.phone);
			Search_phone(rec.phone);
			break;
		case '5':
			printf("Введите email читателя:\n");
			scanf("%s", &rec.email);
			Search_email(rec.email);
			break;
		case '6':
			printf("Введите примечание читателя:\n");
			scanf("%s", &rec.annotation);
			Search_annotation(rec.annotation);
			break;
		case '0':
			return;
			break;
		}
	}
}

int main(void)
{

	char path[10] = "library";
	Date Nowdata;
	FILE* dbf;
	long numrecs, recnum;
	setlocale(LC_ALL, "Russian");
	dbf = OpenDB(path, &rec);
	if (!dbf)
	{
		printf("Cant open %s\n", path);
		exit(1);
	}
	numrecs = rec.custnum;
	for (recnum = 0; recnum <= numrecs; recnum++)
		if (ReadRecord(dbf, recnum, &rec))
		{
			numrecs++;
			Insert(rec);
		}
	fclose(dbf);
	Display();
	while (1)
	{
		setlocale(LC_ALL, "Russian");
		//system("cls");
		printf("==============================================================================\n");
		printf("   MENU:");
		printf("\n   1)Поиск читателя\n   2)Удалить читателя\n   3)Добавить читателя\n   4)Отчёт\n   5)Работать с книжками\n   6)Редактировать\n   0)Выход+Сохранение БД\n");
		printf("==============================================================================\n");
		char menu = getch();
		switch (menu)
		{
		case '1':
			menu1();
			break;
		case '2':
			menu6();
			break;
		case '3':
			GetNewRecord(&rec);
			Insert(rec);
			break;
		case '4':
			printf("Читателей : %d", numrecs - 1);
			printf("\n");
			printf("Общая стоимость книг : %d", PrintAllBooksPrice(rec1, "Books"));
			printf("\n");
			printf("Книг всего : %d", PrintAllBooks(rec1, "Books"));
			printf("\n");
			break;
		case '5':
			menu2();
			break;
		case '6':
			printf("Телефон читателя:\n");
			scanf("%s", &rec.phone);
			rec = Edit_custom(rec.phone);
			Display();
			break;
		case '0':
			fflush(stdin);
			Writeinfile();
			Clear();
			Display();
			exit(1);
			break;
		}
	}
	return 0;
}