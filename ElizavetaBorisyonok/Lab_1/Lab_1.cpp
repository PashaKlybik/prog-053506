

//1.2(5)

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
	system("chcp 1251 & cls");
	int N;
	
	printf("N = ");
	scanf_s("%d",&N);

	printf("Возрастающая:\n");

	for (int i = 1; i <= N; i++)
	{
	    printf("%d\n", i);
	}

	printf("Убывающая:\n");

	for (int i(N); i >= 1; i--)
	{
		printf("%d\n", i);
	}
}




