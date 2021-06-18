//#4.2(6)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int strlen(char* str);
int main()
{
	FILE *S1 = fopen("openfile.txt", "w"), *S2 = fopen("savefile.txt", "w");
	int count, sdvig = 0;
	char str2[100], str3[100];
    printf("Enter the number of lines: "); scanf("%d", &count);
	char** str = (char**)malloc(count * sizeof(char*));
	for (int i = 0; i <= count; i++)
	{
		str[i] = (char*)malloc(100 * sizeof(char));
	}
	printf("\nEnter the string: \n");
	for (int i = 0; i <= count; i++)
		gets(str[i]);
	for (int i = 1; i <= count; i++)
		fprintf(S1, "%s\n", str[i]);
	fclose(S1);
	S1 = fopen("openfile.txt", "r");
	int i = 0;
	printf("\nChanged lines: \n");
	while (i < count)
    {
		fgets(str2, 100, S1);
		str2[strlen(str2)] = '\0';
		for(int i = 0; i < strlen(str2); i++)
			str3[i] = str2[i];
		str3[strlen(str2)] = '\0';
		sdvig++;
		if (str2 == NULL)
		{
			if (feof(S1) != 0)
				break;
		}
		int j = 0;
		while (j < sdvig)
		{
			for (int d = 0; d < strlen(str2); d++)
				str2[d] = str3[d];
			char tmp = str2[strlen(str2) - 1];
			for (int z = 1; z < strlen(str2); z++)
				str3[z] = str2[z - 1];
			str3[0] = tmp;
			j++;
		}
		fprintf(S2, "%s\n", str3);
		printf("%s\n", str3);
		i++;
   }
	fclose(S1);
	fclose(S2);
	return 0;
}
int strlen(char* str)
{
	int res = 0;
	while (str[res] != '\n' && str[res] != '\0' && str[res] != ' ')
		res++;
	return res;
}