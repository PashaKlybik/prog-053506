﻿#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <locale.h>

struct Node
{
	int field;
	struct Node* next, * prev;
};
typedef struct Node Node;


int Equal(Node* headFirst, Node* headSecond)
{
	if (headFirst && headSecond)
	{
		Node* currentFirst, * currentSecond;
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

void Add(int number, Node* head)
{
	Node* newItem = (Node*)malloc(sizeof(Node));
	newItem->field = number;

	Node* current;
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newItem;
	newItem->next = NULL;
	newItem->prev = current;
}

Node* Fill(char number[])
{
	int Length = strlen(number) - 2;
	int check = Length;
	int num;
	int d = 10;
	Node* head = (Node*)malloc(sizeof(Node));
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
		default:printf("Wrong symbol will be skipped");
			break;
		}

		if (check == Length)
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

void Print(Node* head)
{
	Node* current;
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

void div(Node* head, int div)
{
	int counter = 0;
	int num = 0;
	int d = 1;
	int buf;
	Node* current;
	current = head;
	while (1)
	{
		if (current->next != NULL)
		{
			buf = current->field;
			buf = buf * d + num;
			if (buf >= div)
				while (buf >= div)
				{
					buf -= div;
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
			while (buf >= div)
			{
				buf -= div;
				num = buf;
				counter++;
			}
			d = d * 10;
			break;
		}
	}
	printf("Full divide: %d", counter);
	printf("\n");
	printf("Ost: %d", num);
	printf("\n");
}

void LongMulShort(Node* head, int mod)
{
	Node* current = head;
	int d = 10;
	int ones;
	int tens = 0;
	while (1)
	{
		if (current->next != NULL)
		{
			if ((current->field * mod) + tens >= d)
			{
				ones = ((current->field * mod) + tens) % d;
				tens = ((current->field * mod) + tens) / d;
				current->field = ones;
			}
			else
			{
				current->field = (current->field * mod) + tens;
				tens = 0;
			}
			current = current->next;
		}
		else
		{
			ones = ((current->field * mod) + tens) % d;
			tens = ((current->field * mod) + tens) / d;
			current->field = ones;
			if (tens > 0)
			{
				Node* temp = (Node*)malloc(sizeof(Node));
				temp->field = tens;
				current->next = temp;
				temp->next = NULL;
				temp->prev = current;
			}
			break;
		}
	}
}

void main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	Node* head2 = (Node*)malloc(sizeof(Node));
	int divNumber;
	char number1[100];
	char number2[100];
	int mod;
	setlocale(LC_ALL, "rus");
	printf("Введите первое число: ");
	fgets(number1, 100, stdin);
	head = Fill(number1);
	printf("Введите второе число: ");
	fgets(number2, 100, stdin);
	head2 = Fill(number2);
	printf("\n");
	int a = Equal(head, head2);
	printf("Сравнение: %d", a);
	printf("\n");
	printf(": Введите число для целочисленного деления:");
	scanf_s("%d", &divNumber);

	div(head, divNumber);
	div(head2, divNumber);

	printf("Введите число для получения остатка от деления: ");
	scanf_s("%d", &mod);

	LongMulShort(head, mod);
	Print(head);

	LongMulShort(head2, mod);
	Print(head2);
	Node* temp;

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
}



