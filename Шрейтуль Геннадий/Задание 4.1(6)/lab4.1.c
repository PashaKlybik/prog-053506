//#4.1(6)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int strlen(char* str);
int main()
{
	int count;
	printf("Enter the number of lines: "); scanf("%d", &count);
	char** str = (char**)malloc(count * sizeof(char*));
	for (int i = 0; i <= count; i++)
	{
		str[i] = (char*)malloc(100 * sizeof(char));
	}
	char** strnew = (char**)malloc(count * sizeof(char*));
	for (int i = 0; i <= count; i++)
	{
		strnew[i] = (char*)malloc(100 * sizeof(char));
	}
	printf("\nEnter the string: \n"); 
	for (int i = 0; i <= count; i++)
		gets(str[i]);
	for (int i = 0; i <= count; i++)
	{
		str[i][strlen(str[i])] = ' ';
		int tmp = 0;
		for (int j = 0; j < 100; j++)
		{
			if (str[i][j] == ' ')
			{
				strnew[i][j] = ' ';
				for (int z = tmp; z < j; z++)
				{
					if (str[i][z] < str[i][z + 1])
					{
						strnew[i][z] = str[i][z];
						if (str[i][z + 2] == ' ')
						{
							strnew[i][z + 1] = str[i][z + 1];
							strnew[i][z + 2] = ' ';
							break;
						}
					}
					else
					{
						for (int d = tmp; d < j; d++)
							strnew[i][d] = ' ';
						break;
					}	
				}
				tmp = j + 1;
			}
		}
		strnew[i][tmp] = '\0';
	}
	printf("\nModified string: \n");
	for (int i = 1; i <= count; i++)
	{
		if (strnew[i][0] != ' ')
			printf("%s\n", strnew[i]);
	}
	return 0;
}
int strlen(char* str)
{
	int res = 0;
	while (str[res] != '\n' && str[res] != '\0' && str[res] != ' ')
		res++;
	return res;
}