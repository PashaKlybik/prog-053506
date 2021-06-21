/*
Lab 6(5.2) Variant 9
� ��������� ����� ���������� n ����� ����� � �������� ������� 
��������� (m ��� ������). ��������� �������� ������, � ������� 
������ ������������� ������ ������, � ���� �� ������ ������������ 
�������� �������������� ����� (�1� � ������� � ������� �������, 
�0� � ������� � ������ �������). 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#include "Tree.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* fileOpen = fopen("Numbers.txt", "r");
	size_t n, m;
	Tree* head = malloc(sizeof(Tree));
	head->left = NULL;
	head->right = NULL;
	scanf(fileOpen, "%d %d", &n, &m);
	head->data = NULL;
	char* buffer = malloc((m + 2) * sizeof(char*));
	fgets(buffer, m, fileOpen);
	for (size_t i = 0; i < n; i++)
	{
		fgets(buffer, m + 2, fileOpen);
		NewBranch(head, buffer, m);
	}

	while (1)
	{
		printf("1.������ �����\n 2.������������ �����\n 3. �������� �����\n");
		char choise = _getche();
		switch (choise) {
		case '1':
			PreOrder(head);
			break;
		case '2':
			InOrder(head);
			break;
		case '3':
			PostOrder(head);
			break;
		}
	}
	fclose(fileOpen);
	deleteTree(head);
	return 0;
}