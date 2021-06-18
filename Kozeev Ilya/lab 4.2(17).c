//task 4.2 var 17

int ShowPseudoRussian (char _text[]);
int LineLength(char _text[]);

-----------------------------------------------------------------

#include <stdio.h>
#include "Lab4.2_C_header.h"

int main(void)
{
     FILE *labFile;
     labFile = fopen("LabFile.txt", "r+");
     if(!labFile)
     { 
         printf("file not found");
         return -1; 
     }

    /*---------------------------------------*/

     char vasia[100];
     /*fscanf(labFile, "%s", vasia);*/
     fgets(vasia, 100, labFile);
     ShowPseudoRussian (vasia);

     /*---------------------------------------*/

     fclose(labFile);
}

int LineLength(char _text[])
{
    int i = 0;

    while(_text[i])
    {i++;}

    return i;
}

int ShowPseudoRussian (char _text[])
{
     int i, temp = 0;
     for (i = 0; i < LineLength(_text); i++)
     {
          switch (_text[i])
          {
          case 'A':
          case 'B':
          case 'E':
          case 'K':
          case 'M':
          case 'H':
          case 'O':
          case 'P':
          case 'C':
          case 'T':
          case 'X':
          case ' ':
          printf("%c",_text[i]);
          temp = 1;
          break;
          }
     }
     return temp;
}