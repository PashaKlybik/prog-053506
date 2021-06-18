//task 3.2 var 19

#ifndef functions_h
#define functions_h

#include <stdio.h>

void check(int *a);
void printField(int m, int n, int** field);
int change(int num, int m, int n, int boarderSecond, int** field);
void pcChoice(int m, int n, int *rndM, int *rndN, int** field);
void plChoice(int m, int n, int *mPlayer, int *nPlayer, int** field);
void choiceCheckM(int m, int *mPlayer);
void choiceCheckN(int n, int *nPlayer);

#endif

--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <time.h>

int main()
{
    int m, mPlayer, n, nPlayer, i, k, end = 0, result;
    int rndN, rndM;
    int** field;
    printf("Введите m: ");
    check(&m);
    printf("Введите n: ");
    check(&n);
    field = (int**) malloc( m * sizeof(int*));
    if (field == NULL)
        exit(1);
    for (i = 0; i < m; i++)
    {
        field[i] = (int*) malloc( n * sizeof(int));
        if (field[i] == NULL)
            exit(1);
    }
    for (i = 0; i < m; i++)
        for (k = 0; k < n; k++)
                field[i][k] = 1;
    field[m - 1][0] = 0;
    srand((int)time(NULL));
    
    printField(m, n, field);
    
    while (end != 1)
    {
        printf("Игрок: \n");
        choiceCheckM(m, &mPlayer);
        choiceCheckN(n, &nPlayer);
        plChoice(m, n, &mPlayer, &nPlayer, field);
        printf("Компьютер: ");
        pcChoice(m, n, &rndM, &rndN, field);
        printf("\nКомпьютер выбрал: %d",rndM);
        printf("\nКомпьютер выбрал: %d",rndN);

        printf("\nХод:\n");
        
        result = change(1, mPlayer, nPlayer, n, field);
        if (result == 1)
        {
            printf("Результат: Игрок проиграл\n");
            end = 1;
        }
        else
        {
            result = change(2, rndM, rndN, n, field);
            if (result == 2)
            {
                printf("Результат: Компьютер проиграл\n");
                end = 1;
            }
        }
        printField(m, n, field);
    }
    
    for (i = 0; i < m; i++)
        free(field[i]);
    free(field);
    return 0;
}

void check(int *a)
{
    int valid = 0;
    char inpStr[1024];
    char buffer = 0;
    while(!valid)
        {
            buffer = 0;
            if((scanf("%1023[^\n]%c",inpStr,&buffer) != 2) || buffer != '\n')
            {
                if(printf("Ввод не верен!\nПовторите ввод: "))
                    getchar();
            }
            else
            if((sscanf(inpStr,"%d%c",&*a,&buffer) != 1) || buffer != '\n')
                printf("Ввод не верен!\nПовторите ввод: ");
            else
                valid = 1;
        }
}

void printField(int m, int n, int** field)
{
    int i,k;
    for (i = 0; i < m; i++)
    {
        for (k = 0; k < n; k++)
            printf("%d ", field[i][k]);
        printf("\n");
    }
}

void pcChoice(int m, int n, int *rndM, int *rndN, int** field)
{
    int valid = 0;
    while(valid != 1)
    {
        *rndM = rand() % m;
        *rndN = rand() % n;
        if (field[*rndM][*rndN] != 2)
            valid = 1;
    }
}

void choiceCheckM(int m, int *mPlayer)
{
    int valid = 0;
    printf("Введите координату m пирога: ");
    check(&*mPlayer);
    while(valid != 1)
    {
        if (*mPlayer < 0 && *mPlayer >= m)
        {
            printf("Координата введена неверно! Повторите ввод!");
            check(&*mPlayer);
        }
        else
            valid = 1;
    }
}

void choiceCheckN(int n, int *nPlayer)
{
    int valid = 0;
    printf("Введите координату n пирога: ");
    check(&*nPlayer);
    while(valid != 1)
    {
        if (*nPlayer < 0 && *nPlayer >= n)
        {
            printf("Координата введена неверно! Повторите ввод!");
            check(&*nPlayer);
        }
        else
            valid = 1;
    }
}

void plChoice(int m, int n, int *mPlayer, int *nPlayer, int** field)
{
    int valid = 0;
    while(valid != 1)
    {
        if (field[*mPlayer][*nPlayer] == 2)
        {
            printf("Этот кусок уже съеден, повторите ввод!\n");
            choiceCheckM(m, &*mPlayer);
            choiceCheckN(n, &*nPlayer);
        }
        else
            valid = 1;
    }
}
#endif

int change(int num, int m, int n, int boarderSecond, int** field)
{
    if (m != 0)
    {
        if (field[m][n] != 0 && field[m - 1][n] != 0
            && field[m - 1][n + 1] != 0 && field[m][n + 1] != 0)
        {
            field[m][n] = 2;
            if (m - 1 >= 0)
                field[m - 1][n] = 2;
            if (m - 1 >= 0 && n+ 1 < boarderSecond)
                field[m - 1][n + 1] = 2;
            if (n+ 1 < boarderSecond)
                field[m][n + 1] = 2;
            return 0;
        }
        else
            return num;
    }
    else
    {
        field[m][n] = 2;
        field[m][n+1] = 2;
        return 0;
    }
        
}
