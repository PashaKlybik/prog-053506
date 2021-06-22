#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main()
    {
	system("chcp 1251");
	int i = 0;
	int mistakes = 0;
	char arr[80], ch;
	FILE* fp;
	fp = fopen("DATA.txt", "r");

	while (!feof(fp))
	{
		char d;
		fscanf_s(fp, "%c", &ch);

		if (i == 0)
		{
			arr[i] = toupper(ch);
			i++;
			continue;
		}
		else if (arr[i - 1] == '.')
		{
			arr[i] = toupper(ch);
			i++;
		}
		else if (arr[i - 1] == ' ' && ch == ' ')
		{

		}
		else
		{
			arr[i] = tolower(ch);
			i++;
		}
	}
	arr[i] = '\0';
	puts(arr);
	return 0;
	}