#include <stdio.h>
#include <conio.h>
#include < string.h >
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNING
//В текстовом файле содержится произвольный текст. Построить на
//его основе бинарное дерево поиска, каждый узел которого
//содержит слово. Вывести из дерева на печать слова, начинающиеся
//и заканчивающиеся на одну и ту же букву, упорядочив их по
//алфавиту. 
typedef struct tree tree;

struct tree
{
	int numberOfLetter;
	int wordSize;
	int lastNumber;
	char* Word;
	tree* left;
	tree* right;
	tree* parent;
};

void freemem(tree* head) {  //free tree
	if (head != NULL) {
		freemem(head->left);
		freemem(head->right);
		free (head);
	}
}

tree* Add(tree* head,char* word,int lettervalue,int size,tree* parent,int wordSize,int lastLet) // add by the number of letter in alp
{
	if (head == NULL)
	{
		tree* header = (tree*)malloc(sizeof(tree));
		header->Word = (char*)malloc(sizeof(char));
		header->numberOfLetter = lettervalue;
		header->wordSize = wordSize;
		header->lastNumber = lastLet;
		header->right = NULL;
		header->left = NULL;
		header->parent = parent;
		printf("\n");
		for (int i = 0; i < size; i++)
		{		
			header->Word[i] = word[i];
			printf("%c", header->Word[i]);
		}	
		return(header);
	}
	else
	{		
			if (head->numberOfLetter > lettervalue)
				head->left = Add(head->left, word, lettervalue, size,head,wordSize, lastLet);
			else
				head->right = Add(head->right, word, lettervalue, size,head,wordSize, lastLet);

			return(head);
	}
}

void Print(tree* head)  //printf words with same letters
{	
	if (head != NULL)
	{
		Print(head->left);
		if (head->numberOfLetter == head->lastNumber)
		{
			printf("\n");
			for (int i = 0; i < head->wordSize; i++)
			{
				printf("%c", head->Word[i]);
			}
		}
		Print(head->right);
	}
}

int main()
{
	FILE* file;
	char* array;
	char letters[26] = "abcdefghijklmnopqrstuvwxyz";
	char Bletters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	tree* head=NULL;

	if (file = fopen("Text.txt", "r") == NULL)
	{
		printf("Failed to open");
		return 0;
	}
	else
		file = fopen("Text.txt", "r");

	fseek(file, 0, SEEK_END); // seek to end of file
	long size = ftell(file); // get current file pointer
	fseek(file, 0, SEEK_SET);

	array = (char*)calloc(size, sizeof (char));

	char* word = (char*)calloc(size, sizeof(char));

	int ind = 0;
	while (!feof(file)) //read file
	{
		array[ind] = fgetc(file);
		ind++;
	}
	array[ind - 1] = '\0';

	fclose(file);


	for (int i=0; i < size; i++)
	{
		printf("%c", array[i]);
	}

	for (int cnt=0; cnt < size; cnt++) //check words and their letters in alp
	{
		if (array[cnt] == ' ' || array[cnt] == '.' || array[cnt] == ',')
		{
			int counterLetters=0;
			cnt++;
			while (array[cnt] != ' ' && array[cnt] != '\n' && array[cnt] != '.' && array[cnt] != ',' &&  array[cnt] != '\0')
			{
				word[counterLetters] = array[cnt];
				counterLetters++;
				cnt++;
			}
			cnt--;
			int lastNum = 0;

			for (int counter = 0; counter < 27; counter++)
			{				

				if (word[counterLetters - 1] == letters[counter])
				{
					lastNum = counter;
				}
				else
					if (word[counterLetters - 1] == Bletters[counter])
					{
						lastNum = counter;
					}
			}


			for (int counter=0; counter < 27; counter++)
			{		
				if (word[0] == letters[counter])
				{
					head = Add(head, word, counter, counterLetters,head,counterLetters, lastNum);
					break;
				}
				else
					if( word[0] == Bletters[counter])
					{
						head = Add(head, word, counter, counterLetters, head,counterLetters, lastNum);
							break;
					}

			}

		}
	}
	printf("\n \nWords with same letters: ");
	Print(head);
	freemem(head);
}