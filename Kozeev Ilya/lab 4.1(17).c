//task 4.1 var 17

int LineLength(char _text[]);
int RemoveUnnecessary(char* _text);

-----------------------------------------------------------------

#include <stdio.h>
#include "Lab4.1_C_header.h"

int main()
{
    /*printf ("%c\n",90);*/
    char text[80];
    printf("Enter text:\n");
    scanf("%[^\n]s", text);

    /*---------------------------------------*/

    int unnecessoryCheck = RemoveUnnecessary(text);
    if (unnecessoryCheck == 1) 
    {printf("\nunnecessory removed\n");}
    else
    {printf("all is necessory\n");}
    
    /*---------------------------------------*/
    return 0;
}    

int LineLength(char _text[])
{
    int i = 0;
    
    while(_text[i])
    {i++;}

    return i;
}

int RemoveUnnecessary(char _text[])
{
    int temp = 0;
    int result = 0;
    int i;
    for (i = 0; i < LineLength(_text); i++)
    {
        if (_text[i] == '(')
        {
            printf("%c",_text[i]);
            i++;
            temp = i;
            
            while (_text[i] != ')')
            {
                i++;
                result=1;
            }

            if (i == LineLength(_text))
            {i = temp;}
        }
        printf("%c",_text[i]);
    }
    return result;
}