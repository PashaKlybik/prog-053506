//ВАРИАНТ 4.2.2
//#include <stdio.h>
#include <iostream>
int main()
{
	char* string = (char*)calloc(255, 1);
	FILE* my_file;
	my_file = fopen("test.txt", "r");
	if (my_file == NULL)
	{
		printf("error");
	}
    while (fgets(string, 50, my_file) != NULL) {}
    printf("%s", string);
    fclose(my_file);
	int vlozhennost = 0;
	int max_vlozhennost = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == '(')
		{
			string[i] = '{';
			vlozhennost++;
			if (vlozhennost > max_vlozhennost)
			{
				max_vlozhennost = vlozhennost;
			}
		}
		if (string[i] == ')')
		{
			string[i] = '}';
			vlozhennost--;
		}
	}
	for (int i = 0; i < strlen(string); i++)
	{

		if (string[i] == '{')
		{
			vlozhennost++;
			if (vlozhennost == max_vlozhennost) string[i] = '(';
			if (vlozhennost == max_vlozhennost - 1) string[i] = '[';
		}
		if (string[i] == '}')
		{
			if (vlozhennost == max_vlozhennost) string[i] = ')';
			if (vlozhennost == max_vlozhennost - 1) string[i] = ']';
			vlozhennost--;
		}
	}
    printf("\n%s", string);
    free(string);
}
