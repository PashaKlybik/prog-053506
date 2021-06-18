#include <stdio.h>
#include <malloc.h>
 
#define MaxStrings 80
#define MaxChars 1000
 
void main()
{
 int maxWord=0;
 char Word[MaxChars];
 char maxWordC[MaxChars];
 int cntWord=0;
 int Sentence=0;
 int maxSentence = 0;
 char Enter = '\n';
 char text[MaxStrings][MaxChars];
 printf("Enter Text(Dont forget to enter (.) at the end of raw) and press (q) to exit:\n");
 for (int column = 0, raw = 0; column < MaxChars && text[raw][column-1] != 'q' && raw<MaxStrings; column++)
 {
  text[raw][column] = getchar();
  if (text[raw][column] == Enter)
  {
   text[raw + 1][0] = ' ';
   if (maxSentence < column)
   {
    maxSentence = column;
    Sentence = raw;
   }
   column = 0;
   raw++;
  }
 
  if (text[raw][column] != ' '&& text[raw][column] != ',' && text[raw][column] != '.' && text[raw][column] != ':')
  {
   Word[cntWord] = text[raw][column];
   cntWord++;
  }
   else
   {
    if (maxWord < cntWord)
    {
     maxWord = cntWord;
     for (int i = 0; i < maxWord; i++)
     {
      maxWordC[i] = Word[i];
     }
      
    }
    cntWord = 0;
   }
 
 }
 printf("Max Word: ");
 for (int i = 0; i < maxWord; i++)
 {
   printf("%c", maxWordC[i]);
 }
 printf("\nMax Sentence: ");
 for (int i = 1; i < maxSentence; i++)
 {
  printf("%c", text[Sentence][i]);
 }
}