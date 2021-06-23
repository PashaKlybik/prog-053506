#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

void Delete(int** matrix, int index, int* n, int m) {
    *n -=1;
    for(int i = 0; i < m; i++)
        for(int j = index; j < (*n); j++)
            matrix[j][i] = matrix[j + 1][i];

}

void InitValues(int** matrix, int n, int m) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 2;
        }
}

void DisplayMatrix(int** matrix, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

void FindTheSame(int** matrix, int* n, int m) {
    for(int i = 0; i < *n; i++) {
        int* f = matrix[i];
        int isDelete = 0;
        for(int j = i + 1;j < *n;j++) {
            int* s = matrix[j];
            for(int h = 0; h < m; h++) {

                if(f[h] != s[h]) break;
                if(h == m - 1) {
                    Delete(matrix, j, n, m);
                    isDelete = 1;
                    j--;
                }
            }
        }

        if(isDelete == 1) {
            Delete(matrix, i, n, m);
            i--;
        }
    }
}

int CompareRows(int* row1,int* row2, int size) {
    for(int i = 0; i < size; i++) {
        if(row1[i] > row2[i]) return 1;
        else if (row1[i] < row2[i]) return -1;
    }

    return 0;
}

void SortByBinary(int** arr, int n, int m)
{
    int* temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (CompareRows(arr[j], arr[j + 1], m) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));

    int n, m;
    printf("Введите размер матрицы(через пробел два числа): ");
    scanf("%i %i", &n, &m);
    fflush(stdin);

    int** matrix = (int**)calloc(n, sizeof(int*));
    for(int i = 0;i < n; i++) matrix[i] = (int*)calloc(m, sizeof(int));

    InitValues(matrix, n , m);
    printf("Матрица ДО проверки на схожесть строк: \n");
    DisplayMatrix(matrix, n , m);

    FindTheSame(matrix, &n , m);

    printf("\n");
    printf("Матрица ПОСЛЕ проверки на схожесть строк: \n");
    DisplayMatrix(matrix, n , m);

    SortByBinary(matrix, n, m);

    printf("\n");
    printf("Матрица ПОСЛЕ сортировки строк: \n");
    DisplayMatrix(matrix, n , m);

    return 0;
}
