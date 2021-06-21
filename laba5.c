#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int element;
	struct node* next;
};
void EnterAndCheckInput(int* a)
{
	while (!scanf("%d",

		&(*a)))
	{
		printf("Неверный ввод, пожалуйста, повторите ввод :)\n");
		while (getchar() != '\n');
		printf("..новый ввод: ");
	}
}

void MemoryCheck(struct node* pointer)
{
	if (pointer == NULL)
	{
		printf("\nНедостаточно памяти :<");
		exit(1);
	}
}

struct node* AddElement(struct node* listRoot, int val)
{
	struct node* current = listRoot, * newNode;
	while (current->next != NULL)
	{
		current = current->next;
	}
	newNode = (struct node*)malloc(sizeof(struct node));
	MemoryCheck(newNode);
	newNode->element = val;
	newNode->next = NULL;
	current->next = newNode;
	return newNode;
}

struct node* Sort(struct node* listRoot)
{
	struct node* current = listRoot, * tmp = NULL, * prev = NULL;
	int flag = 0;
	do
	{
		flag = 0;
		current = listRoot;
		while (current->next != NULL)
		{
			if (current->element > current->next->element)
			{
				if (current == listRoot)
				{
					tmp = current;
					current = tmp->next;
					tmp->next = current->next;
					current->next = tmp;
					listRoot = current;
					flag = 1;
				}
				else
				{
					tmp = current;
					current = tmp->next;
					tmp->next = current->next;
					current->next = tmp;
					prev->next = current;
					flag = 1;
				}
			}
			prev = current;
			current = current->next;
		}
	} while (flag == 1);
	return listRoot;
}

void DeleteDuplicateElements(struct node* listRoot)
{
	struct node* current = listRoot, * placeholder;
	while (current != NULL && current->next != NULL)
	{
		if (current->element == current->next->element)
		{
			placeholder = current->next->next;
			free(current->next);
			current->next = placeholder;
		}
		current = current->next;
	}
}

struct node* PlusList(struct node* listPlusRoot, struct node* generalListRoot)
{
	struct node* listPlus = listPlusRoot, * generalList = generalListRoot;
	while (listPlus != NULL)
	{
		if (generalListRoot == NULL)
		{
			generalListRoot = (struct node*)malloc(sizeof(struct node));
			MemoryCheck(generalListRoot);
			generalListRoot->element = listPlus->element;
			generalListRoot->next = generalList;
		}
		else
			generalList = AddElement(generalListRoot, listPlus->element);
		listPlus = listPlus->next;
	}
	return generalListRoot;
}
void ShowList(struct node* listRoot)
{
	struct node* current;
	current = listRoot;
	while (current != NULL)
	{
		printf(" %d ", current->element);
		current = current->next;
	}
}

int main(int argc, char* argv[])
{

	system("chcp 1251");
	system("cls");

	struct node* list1Root = NULL, * list2Root = NULL;
	struct node* list1 = NULL, * list2 = NULL;

	int i = 0;
	int n1 = 0;
	printf("Введите кол-во элементов для первого списка = ");
	EnterAndCheckInput(&n1);
	printf("Введите элемент первого списка:\n");

	for (i = 0; i < n1; i++)
	{
		int x = 0;

		scanf("%d", &x);
		if (list1Root == NULL)
		{
			list1Root = (struct node*)malloc(sizeof(struct node));
			MemoryCheck(list1Root);
			list1Root->element = x;
			list1Root->next = list1;
		}
		else
			list1 = AddElement(list1Root, x);
	}

	int n2 = 0;
	printf("\nВведите кол-во элементов для второго списка = ");
	EnterAndCheckInput(&n2);
	printf("Введите элемент второго списка:\n");

	for (i = 0; i < n2; i++)
	{
		int x = 0;
		scanf("%d", &x);
		if (list2Root == NULL)
		{
			list2Root = (struct node*)malloc(sizeof(struct node));
			MemoryCheck(list2Root);
			list2Root->element = x;
			list2Root->next = list2;
		}
		else
			list2 = AddElement(list2Root, x);
	}

	system("cls");
	printf("\nПервый список:\n");
	list1Root = Sort(list1Root);
	ShowList(list1Root);
	printf("\nВторой список:\n");
	list2Root = Sort(list2Root);
	ShowList(list2Root);
	DeleteDuplicateElements(list1Root);
	DeleteDuplicateElements(list2Root);
	struct node* generalListRoot = NULL, * generalList = NULL;
	generalListRoot = PlusList(list1Root, generalListRoot);
	generalListRoot = PlusList(list2Root, generalListRoot);
	generalListRoot = Sort(generalListRoot);
	DeleteDuplicateElements(generalListRoot);
	printf("\nНовый список\n");
	ShowList(generalListRoot);
	printf("\n");

	free(list1Root);
	free(list2Root);
	return 0;
}
