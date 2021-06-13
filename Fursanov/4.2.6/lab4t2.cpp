#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>

void switch_char(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    long sWidth = 0, sLen = 40;
    int a = 1;
    FILE* myfile;
    if ((myfile = fopen("Spisok.txt", "r")) == NULL)
    {
        printf("Не удалось открыть файл");
        getchar();
        return 0;
    }
    char ch, ** str = (char**)malloc(sizeof(char*));
    ch=0; 
    int count = 0;
    str[0] = (char*)malloc (sLen * sizeof(char));
    while (ch != -1)
    {
        while ((ch = fgetc(myfile)) != '\n')
        {
            if (ch == -1)break;
            str[sWidth][count] = ch;
            count++;
            if(count>=sLen)
            str[sWidth] = (char*)realloc(str[sWidth],  (sLen*(a++)) * sizeof(char));
        }
        str[sWidth][count] = '\0';
        for (int k = 0; k < sWidth+1; k++)
        for (int i = 0; i<count; i++)
        {
            switch_char(str[sWidth][i], str[sWidth][count - 1]);
        }
        str = (char**)realloc(str, (1 + (++sWidth)) * sizeof(char*));
        str[sWidth] = (char*)malloc(sLen * sizeof(char));
        count = 0; a = 1;
    }
    fclose(myfile);
    for (int i = 0; i < sWidth; i++)
        puts(str[i]);
    return 0;
}