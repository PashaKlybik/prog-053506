#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void Output(int** arr, int onesize)
{
    for (int i = 0; i < onesize; i++)
    {
        for (int j = 0; j < onesize; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

int Sort(int** arr2, int onesize)
{
    int tmp, temp, y, i = 0, j = 0;
    for (i = 0; i < onesize - 1; i++) 
    {
        for (j = 0; j < onesize - 1 - i && j < onesize - 1; j++)
        {
            tmp = j;
            for (y = j + 1; y < onesize - i && y < onesize; y++)
                if (arr2[i + y][y] < arr2[i + tmp][tmp])
                    tmp = y;
            temp = arr2[i + j][j]; 
            arr2[i + j][j] = arr2[i + tmp][tmp]; 
            arr2[i + tmp][tmp] = temp;
        }
    }
    for (i = 1; i < onesize - 1; i++) 
    {
        for (j = 0; j < onesize - 1 && j + i < onesize - 1; j++)
        {
            tmp = j;
            for (y = j + 1; y < onesize && y + i < onesize; y++)
                if (arr2[tmp][i + tmp] > arr2[y][i + y])
                    tmp = y;
            temp = arr2[j][j + i]; 
            arr2[j][j + i] = arr2[tmp][tmp + i]; 
            arr2[tmp][tmp + i] = temp;
        }

    }
    return arr2;
}
int main()
{

    int** b = NULL;  
    int i = 0, j = 0, size = 0;
    int tmp, temp, y;
	system("chcp 1251");
    system("cls");
    printf("Введите размерность матрицы: ");
    scanf_s("%d", &size);
    
    b = (int**)malloc(size * sizeof(int*));

    for (i = 0; i < size; i++)  
    {
        b[i] = (int*)malloc(size * sizeof(int));
        for (j = 0; j < size; j++)  
        {
            b[i][j] = rand() % (100 - 1 + 1) + 1;

        }
    }
    
    Output(b, size);
    Sort(b, size);
    printf("Матрица отсортированных элементов: \n");
    Output(b, size);
    
    for (i = 0; i < size; i++)  
        free(b[i]);   
    free(b);

    return 0;
}