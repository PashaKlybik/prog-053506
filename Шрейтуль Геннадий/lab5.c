//#5.1(25)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int data;
	struct Stack* pNext;
};

struct Stack* head = NULL;

void push(int value);
void pop();
int size();
void show();
void reverseStack();
int main()
{
	int value, n;
	printf("Enter the number of elements in the stack: \n"); scanf("%d", &n);
	if (n > 0)
	{
		printf("Enter value (integer type): \n");
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &value);
			push(value);
		}
		printf("\nStack:\n");
		show();
		printf("Reverse stack:\n");
		reverseStack();
	}
	else
		printf("The number of elements must be greater than zero");
	return 0;
}

void push(int value)
{
	struct Stack* tmp;
	tmp = (struct Stack*)malloc(sizeof(struct Stack));
	if (tmp == NULL)
	{
		printf("Stack overflow");
		return;
	}
	else
	{
		tmp->data = value;
		tmp->pNext = head;
		head = tmp;
	}
}

void pop()
{
	struct Stack* tmp = head;
	if (head == NULL)
	{
		printf("Stack underflow");
		return;
	}
	else
	{
		head = head->pNext;
		tmp->pNext = NULL;
		free(tmp);
	}
}

int size()
{
	struct Stack* tmp = head;
	int i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->pNext;
		i++;
	}
	return i;
}

void show()
{
	struct Stack* tmp = head;
	if (head == NULL)
	{
		printf("Stack underflow");
		return;
	}
	else
	{
		int i = 0;
		while (tmp != NULL)
		{
			printf("Stack[%d] = %d\n", i, tmp->data);
			tmp = tmp->pNext;
			i++;
		}
		printf("\n");
	}
}

void reverseStack()
{
	struct Stack* tmp = head;
	int* time = (int*)malloc(sizeof(int) * size());
	if (head != NULL)
	{
		for (int i = 0; i < size(); i++)
		{
			time[i] = tmp->data;
			tmp = tmp->pNext;
		}
		for (int i = 0; i < size() / 2; i++)
		{
			time[i] = time[i] + time[size()-i- 1];
			time[size()-i-1] = time[i] - time[size()-i-1];
			time[i] = time[i] - time[size()-i-1];
		}
		head->data = time[size()-1];
		for (int i = 0; i < size(); i++)
			printf("Stack[%d] = %d\n", i, time[i]);
	}
	else
	{
		printf("Stack underflow\n");
		return;
	}
}