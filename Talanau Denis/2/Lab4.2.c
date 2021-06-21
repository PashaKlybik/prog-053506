
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
#include<malloc.h>

int main()
{
	system("chcp 1251");
	system("cls");
	FILE* ptrFile = fopen("text.txt", "r+");
	char** str;
	int i, j, number, add;
	fpos_t pos;

	str = (char**)malloc(100 * sizeof(char*));
	for (i = 0; i < 100; i++)
	{
		str[i] = (char*)malloc(82 * sizeof(char));
	}

	if (ptrFile == NULL)
	{
		perror("Ошибка открытия файла");
		getchar();
	}
	else
	{
		setbuf(ptrFile, NULL);
		fgetpos(ptrFile, &pos);

		i = 0;
		while (!feof(ptrFile))
		{
			fgets(str[i], 81, ptrFile);
			i++;
		}
		number = i;

		rewind(ptrFile);

		for (i = 0; i < number; i++)
		{
			if (strlen(str[i]) > 1)
				add = strlen(str[i]) - 1;
			else
				add = strlen(str[i]);

			add = (80 - add) / 2;
			for (j = 0; j < add; j++)
			{
				fputc(' ', ptrFile);
			}
			fputs(str[i], ptrFile);
		}


		for (i = 0; i < 100; i++)
		{
			free(str[i]);
		}

		free(str);
		fclose(ptrFile);
	}

	return 0;
}
