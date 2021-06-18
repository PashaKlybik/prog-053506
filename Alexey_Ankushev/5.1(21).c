/*
Lab 5.1 Variant 21
 —оздать тип данных ћногоразр€дное число. –азработать следующие 
функции: 
Х  Equal()  Ц  сравнение  двух  многоразр€дных чисел (возвращает 0, 
если числа равны, 1 Ц если первое число больше, -1 Ц если второе 
число больше); 
Х  LongModShort()  Ц  возвращает  остаток  от  делени€ 
многоразр€дного числа на короткое число типа int; 
Х  LongDivShort() Ц возвращает результат целочисленного делени€ 
многоразр€дного числа на короткое число типа int; 
Х  LongMulShort()  Ц  возвращает  результат  умножени€ 
многоразр€дного числа на короткое число типа int.  
ƒл€  хранени€  многоразр€дного  числа  использовать  динамический 
двунаправленный список. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <malloc.h>


typedef struct List List;

int Equal(List* headFirst, List* headSecond);
List* Fill(int numer);
void Add(int number, List** head);
void Output(List* head);
void LongModDivShort(List* head);
void LongMulShort(List* head, int mul);


struct List
{
	int field;
	struct List* next, * prev;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	List* head = (List*)malloc(sizeof(List));
	List* head2 = (List*)malloc(sizeof(List));
	int divNumber;
	char number1[100];
	char number2[100];
	int mod;
	int mul;
	int equalNum;
	printf("¬ведите первое число: ");
	fgets(number1, 100, stdin);
	head = Fill(number1);
	printf("¬ведите второе число: ");
	fgets(number2, 100, stdin);
	head2 = Fill(number2);
	printf("\n");
	system("cls");
	List* temp;
	while (1) {
		printf("1. —равнение\n2.ƒеление\n3.”множение\n4.¬ыход");
		char key = _getche();
		switch (key) {
		case 49:
			system("cls");
			equalNum = Equal(head, head2);
			if (equalNum == 1) {
				printf("%s > %s\n", number1, number2);
			}
			if (equalNum == 0) {
				printf("%s = %s\n", number1, number2);
			}
			if (equalNum < 0) {
				printf("%s < %s\n", number1, number2);
			}
			_getche();
			system("cls");
			break;
		case 50:
			system("cls");
			printf("¬ведите число дл€ делени€: ");
			scanf_s("%d", &divNumber);

			LongModDivShort(head, divNumber);
			LongModDivShort(head2, divNumber);
			_getche();
			system("cls");
			break;
		case 51:
			system("cls");
			printf("¬ведите число дл€ умножени€: ");
			scanf_s("%d", &mod);

			LongMulShort(head, mod);
			Output(head);

			LongMulShort(head2, mod);
			Output(head2);

			_getche();
			system("cls");
			break;
		case 52:
			system("cls");
			while (head)
			{
				temp = head;
				head = head->next;
				free(temp);
			}

			while (head2)
			{
				temp = head2;
				head2 = head2->next;
				free(temp);
			}
			system("cls");
			return 0;
			break;
		}
	}
}

int Equal(List* headFirst, List* headSecond)
{
	if (headFirst && headSecond)
	{
		List* currentFirst, * currentSecond;
		currentFirst = headFirst;
		currentSecond = headSecond;
		int cntFirst = 0;
		int cntSecond = 0;
		while (currentFirst->next != NULL)
		{
			cntFirst++;
			currentFirst = currentFirst->next;
		}

		while (currentSecond->next != NULL)
		{
			cntSecond++;
			currentSecond = currentSecond->next;
		}

		if (cntFirst > cntSecond)
			return 1;
		else
		{
			if (cntFirst < cntSecond)
				return -1;
		}
		while (1)
		{
			if (currentFirst->field > currentSecond->field)
			{
				return 1;
				break;
			}
			else
			{
				if (currentFirst->field < currentSecond->field)
				{
					return -1;
					break;
				}
				else
				{
					if (currentFirst->prev == NULL || currentSecond->prev == NULL)
					{
						if (currentFirst->prev == NULL && currentSecond->prev == NULL)
						{
							return 0;
							break;
						}
						else
						{
							if (currentFirst->prev == NULL)
							{
								return -1;
								break;
							}
							else
							{
								return 1;
								break;
							}
						}
					}
				}
			}
			currentFirst = currentFirst->prev;
			currentSecond = currentSecond->prev;
		}
	}
}

void Add(int number, List* head)
{
	List* newItem = (List*)malloc(sizeof(List));
	newItem->field = number;

	List* current;
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newItem;
	newItem->next = NULL;
	newItem->prev = current;
}

List* Fill(char number[])
{
	int check = strlen(number) - 2;
	//int check = Length;
	int num;
	int d = 10;
	List* head = (List*)malloc(sizeof(List));
	while (check >= 0)
	{
		switch (number[check])
		{
		case '0': num = 0; break;
		case '1': num = 1; break;
		case '2': num = 2; break;
		case '3': num = 3; break;
		case '4': num = 4; break;
		case '5': num = 5; break;
		case '6': num = 6; break;
		case '7': num = 7; break;
		case '8': num = 8; break;
		case '9': num = 9; break;
			break;
		}

		if (check == strlen(number) - 2)
		{
			head->field = num;
			head->next = NULL;
			head->prev = NULL;
		}
		else
		{
			Add(num, head);
		}
		check--;
	}
	return head;
}

void Output(List* head)
{
	List* current;
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	while (current->prev != NULL)
	{
		printf("%d", current->field);
		current = current->prev;
	}
	printf("%d\n", current->field);
}

void LongModDivShort(List* head, int divNumber)
{
	int counter = 0;
	int num = 0;
	int d = 1;
	int buf;
	List* current;
	current = head;
	while (1)
	{
		if (current->next != NULL)
		{
			buf = current->field;
			buf = buf * d + num;
			if (buf >= divNumber)
				while (buf >= divNumber)
				{
					buf -= divNumber;
					num = buf;
					counter++;
				}
			else
				num = buf;
			d = d * 10;
			current = current->next;
		}
		else
		{
			buf = current->field;
			buf = buf * d + num;
			while (buf >= divNumber)
			{
				buf -= divNumber;
				num = buf;
				counter++;
			}
			d = d * 10;
			break;
		}
	}
	printf("÷елочисленное деление: %d\n", counter);
	printf("ќстаток: %d\n", num);
}

void LongMulShort(List* head, int multy)
{
	List* current = head;
	int d = 10;
	int ones;
	int tens = 0;
	while (1)
	{
		if (current->next != NULL)
		{
			if ((current->field * multy) + tens >= d)
			{
				ones = ((current->field * multy) + tens) % d;
				tens = ((current->field * multy) + tens) / d;
				current->field = ones;
			}
			else
			{
				current->field = (current->field * multy) + tens;
				tens = 0;
			}
			current = current->next;
		}
		else
		{
			ones = ((current->field * multy) + tens) % d;
			tens = ((current->field * multy) + tens) / d;
			current->field = ones;
			if (tens > 0)
			{
				List* temp = (List*)malloc(sizeof(List));
				temp->field = tens;
				current->next = temp;
				temp->next = NULL;
				temp->prev = current;
			}
			break;
		}
	}
}
