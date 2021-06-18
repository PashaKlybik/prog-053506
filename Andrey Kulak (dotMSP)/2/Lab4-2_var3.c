//Task 4.2. Variant 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int atoi(char s)
{
	return s;
}

int main()
{
	FILE* output;
	int i = 0, amt = 0, arr[200];
	float sum = 0;
	char s[256];
	printf("Text must be entered in the .txt file first");
	if ((output = fopen("C:\\Users\\andre\\source\\repos\\PlainCLab4-2\\Text.txt", "r")) == NULL)
	{
		perror("Unable to access the file");
		exit(0);
	}
	printf("Text contained in the file: ");
	while (fgets(s, 256, output) != NULL)
	{
		fputs(s, output);
		printf("%s", s);
	}	
	while (s[i] != '\0')
	{
		if (s[i] > 47 && s[i] < 58 || s[i] == 45)
		{
			arr[amt] = atoi(s[i]);
			amt++;
		}
		i++;
	}
	for (int i = 0; i < amt; i++)
	{
		sum += arr[i];
	}
	printf("\nAverage of the entered numbers = %f", sum / amt);
	return 0;
}