#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define SIZE 8

void CheckXY(int** a, int x1, int y1, int x, int y, int SIZE8 ,int d, int b )
{
    int warning = 0;
    int  i = y1, j = x1;
    while (i < SIZE8 && j < SIZE8)
    {
       // if (i != row - 1 && j != row - 1)
            if (a[i][j] == a[y][x])
            {
                printf("\nКороль в опасности от ферзя в координатах x: %d y: %d ", x1, y1);
                warning = 1;
            }
        if (warning)
            break;

        if (d == 0 && b == 0 && j > 0 && i > 0)
        {
            i--;
            j--;
        }
        else if (d == 1 && b == 0 && i <= 7 && j > 0)
        {
            i++;
            j--;
        }
        else if (d == 0 && b == 1 && i > 0 && j <= 7)
        {
            i--;
            j++;
        }
        else if (d == 1 && b == 1 && j <= 7 && i <= 7)
        {
            i++;
            j++;
        }
        else
            break;

    }
}

void CheckX(int** a, int x1, int y1, int x, int y, int SIZE8, int d)
{
    int warning = 0;
    int j = x1;
    while (j < SIZE8)
    {
        if (a[y1][j] == a[y][x])
        {
            printf("\nКороль в опасности от ферзя в координатах x: %d y: %d ", x1, y1);
            warning = 1;
        }
        if (warning)
            break;
        if (d == 0 && j > 0)
            j--;
        else if (d == 1 && j < 7)
            j++;
        else
            break;
    }
}

void CheckY(int** a, int x1, int y1, int x, int y, int SIZE8, int d)
{
    int warning = 0;
    int i = y1;
    while (i < SIZE8)
    {
        if (a[i][x1] == a[y][x])
        {
            printf("\nКороль в опасности от ферзя в координатах x: %d y: %d ", x1, y1);
            warning = 1;
        }
        if (warning)
            break;
        if (d == 0 && i > 0)
            i--;
        else if (d == 1 && i < 7)
            i++;
        else
            break;
    }
}


int main()
{
    system("chcp 1251");
    system("cls");
    int** a;
    int x, y, x1, y1, x2, y2;
    int warning = 0;
    int check = 0, check1 = 0;

    while (!check)
    {
        check1 = 0;
        printf("Введите координаты короля:");
        printf("\ny : ");
        scanf_s("%d", &y);
        printf("x : ");
        scanf_s("%d", &x);

        printf("\nВведите координаты первого ферзя:");
        printf("\ny1 : ");
        scanf_s("%d", &y1);
        printf("x1 : ");
        scanf_s("%d", &x1);

        printf("\nВведите координаты второго ферзя:");
        printf("\ny2 : ");
        scanf_s("%d", &y2);
        printf("x2 : ");
        scanf_s("%d", &x2);

        if (x > 7 || x1 > 7 || x2 > 7 || y > 7 || y1 > 7 || y2 > 7)
            printf("\nКоординаты фигур по х и у должны быть меньше 8\n\n");
        else
            check1 = 1;

        if (x == x1 && y == y1 || x == x2 && y == y2 || x1 == x2 && y1 == y2)
        {
            if (check1)
                printf("\nФигуры должны стоять в разных координатах!!!\n\n");
            else
                check = 1;
        }
        else
            if (check1)
                check = 1;
    }

    a = (int**)malloc(SIZE * sizeof(int*));

    for (int i = 0; i < SIZE; i++)
    {
        a[i] = (int*)malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++)
            a[i][j] = 0;
    }
    printf("\n");
    a[y][x] = 1;
    a[y1][x1] = 2;
    a[y2][x2] = 2;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n\n");
    }

    CheckXY(a, x1, y1, x, y, SIZE, 0, 0);
    CheckXY(a, x1, y1, x, y, SIZE, 1, 0);
    CheckXY(a, x1, y1, x, y, SIZE, 0, 1);
    CheckXY(a, x1, y1, x, y, SIZE, 1, 1);
    CheckXY(a, x2, y2, x, y, SIZE, 0, 0);
    CheckXY(a, x2, y2, x, y, SIZE, 1, 0);
    CheckXY(a, x2, y2, x, y, SIZE, 0, 1);
    CheckXY(a, x2, y2, x, y, SIZE, 1, 1);

    CheckX(a, x1, y1, x, y, SIZE, 1);
    CheckX(a, x1, y1, x, y, SIZE, 0);
    CheckX(a, x2, y2, x, y, SIZE, 1);
    CheckX(a, x2, y2, x, y, SIZE, 0);

    CheckY(a, x1, y1, x, y, SIZE, 1);
    CheckY(a, x1, y1, x, y, SIZE, 0);
    CheckY(a, x2, y2, x, y, SIZE, 1);
    CheckY(a, x2, y2, x, y, SIZE, 0);

    for (int i = 0; i < SIZE; i++)
    {
        free(a[i]);
    }
    free(a);
}
