#include <stdio.h>
#include <malloc.h>
#include <math.h>

void PrintArr(char** ar,int column);
void DeEncryption(char** arrayC, int column, int Length,char str[]);

int main()
{
	char str[225];
	int column = 0;
	int counter=0;
	int n=0;
	char** arrayC;
	printf("Enter string: ");
	fgets(str, 225, stdin);
	int Length = strlen(str)-1;

	while (pow(column, 2) < Length)
	{
		column++;
	}
	
	arrayC = (char**)malloc(column * sizeof(char*));

	for (int i = 0; i < column; i++)
	{
		arrayC[i] = (char*)malloc(column * sizeof(char));
		for (int j = 0; j < column; j++)
		{
			arrayC[i][j] = ' ';
		}
	}

	while (counter!= Length)
	{
		//left
		for (int i = 0; i+n < column-n && counter<Length; i++, counter++)
		{
			arrayC[i+n][n] = str[counter];
		}
		//bot
		for (int i = 0; i + 1 + n < column-n&& counter < Length; i++,counter++)
		{
		
			arrayC[column-1 - n][i + 1 + n] = str[counter];
			
		}
		//right
		for (int i = 0; i + n + 1 < column-n && counter < Length; i++, counter++)
		{
			arrayC[column -2 -i-n][column-1 - n] = str[counter];
		}
		//top
		for (int i = 0,current=i+n+1; i + n + 1 <column -1-n && counter < Length; i++,counter++)
		{
			arrayC[n][column-1 - 1 - n-i] = str[counter];
		}
		n++;
	} 
	PrintArr(arrayC, column, Length);
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%c", arrayC[i][j]);
		}
	}
	printf("\nEnter string for deyncription: ");
		char DeEnc[225];
	fgets(DeEnc, 225, stdin);
	DeEncryption(arrayC, column, Length,DeEnc );
	return 0;
}

void PrintArr(char** ar,int column,int Length)
{
	int cnt = 0;
	for (int i = 0; i < column;i++)
	{
		for (int j = 0; j < column; j++)

		{
			printf("%c\t", ar[i][j]);
		}
		printf("\n");
	}
}

void DeEncryption(char** arrayC,int column,int Length,char str[])
{
	int n = 0;
	int counter=0;
	int cnt = 0;
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arrayC[i][j] = str[cnt];
			cnt++;
		}
	}
	while (counter != Length)
	{
		//left
		for (int i = 0; i + n < column - n && counter < Length; i++, counter++)
		{
			printf("%c", arrayC[i + n][n]);
		}
		//bot
		for (int i = 0; i + 1 + n < column - n && counter < Length; i++, counter++)
		{

			printf("%c", arrayC[column - 1 - n][i + 1 + n]);

		}
		//right
		for (int i = 0; i + n + 1 < column - n && counter < Length; i++, counter++)
		{
			printf("%c", arrayC[column - 2 - i - n][column - 1 - n]);
		}
		//top
		for (int i = 0, current = i + n + 1; i + n + 1 < column - 1 - n && counter < Length; i++, counter++)
		{
			printf("%c", arrayC[n][column - 1 - 1 - n - i]);
		}
		n++;
	}	
}