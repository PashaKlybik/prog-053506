#include <stdio.h>
#include <windows.h>
#include <malloc.h>

void Filling (int **arr, int str, int col)
{
    for (int i = 0; i<str; i++)
    {
        for (int j = 0; j<col; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void ShowArr(int **arr, int str, int col)
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%5d ", arr[i][j]);

        printf("\n");
    }
}

int CheckElem(int **arr, int col, int num, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (num == arr[i][col])
        {
            arr[i][col] = NULL;
            return 1;
        }
    }
    return 0;
}

int Check(int **arr, int str, int col)
{
    int *temp;
    int schet = 0;
    temp = (int *) malloc(str * sizeof(int));
    int pair = 0;
    for (int i = 0; i < col-1; i++)
    {
        for(int y = i+1; y < col; y++)
        {
            for (int h = 0; h < str; h++)
                temp[h] = arr[h][y];

            for (int j = 0; j < str; j++)
            {
                if (CheckElem(arr, y, arr[j][i], str) == 1)
                    schet++;

                if (schet == col)
                {
                    schet = 0;
                    pair++;
                }
            }

            for (int h = 0; h < str; h++)
                arr[h][y] = temp[h];
        }
    }
    return pair;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int str;
    printf("Введите количество строк: ");
    scanf("%d", &str);
    int col;
    printf("Введите количество столбцов: ");
    scanf("%d", &col);
    int *matrix;
    matrix = (int**)malloc(str * sizeof(int*));
    for (int i = 0; i<str; i++)  // цикл по строкам
        matrix[i] = (int *) malloc(col * sizeof(int));
    printf("\n");
    Filling(matrix, str, col);
    printf("\n");
    ShowArr(matrix, str, col);
    printf("\nКоличество пар схожих столбцов: ");
    printf("%d", Check(matrix, str, col));
    return 0;
}
