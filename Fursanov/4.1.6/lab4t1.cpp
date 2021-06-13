#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int M, N=41;

	printf("Введите количество строк, которые хотите ввести\nМ = ");
	while (scanf("%d", &M) <= 0)
	{
		printf("Некорректный ввод. попробуйте ещё раз \n");
		while (getchar() != '\n') {}
		printf("Введите количество строк, которые хотите ввести\nМ = ");
	}
	getchar();
	printf("Введите %d строк, не превышающие %d символов\n", M, N-1);
	char**str= (char**)malloc(M * sizeof(char*));
	for (int i = 0; i < M; i++)
	{
			str[i] = (char*)malloc(N * sizeof(char));
			fgets(str[i], N, stdin);
			for (int j = 0; j < N; j++)
				if (str[i][j] == '\n') { str[i][j] = '\0'; break; }
	}
	putchar('\n');

	char* p, separator[] = " ,.!?;:";
	for (int i = 0; i < M; i++)
	{
		p = strtok(str[i], separator);
		while (p)
		{
			bool u = 1;
			for (int i = 0; i + 1 < strlen(p); i++)
				if (p[i + 1] < p[i])u = 0;
			if(u)puts(p);
			p = strtok(0, separator);
		}
	}

	return 0;
}