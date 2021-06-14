#include <stdio.h>
#include <windows.h>

void Input(int *size)
{
    char check;
    int res;

    while (1)
    {
        scanf_s("%d", &res);
        check = getchar();
        if (check == '\n' && res >= 0)
            break;
        rewind(stdin);
    }
    *size = res;
}

void  BigSymb(char *wStr, int str)
{
    for (int i = 0; i < str; i++)
        if(wStr[i]<=122 && wStr[i]>= 97)
            wStr[i] = wStr[i] - 32;
}

int CheckArr(const char *symbArr, int str)
{
    for (int i = 0; i < str-1; i++)
        for (int j = i+1; j < str; j++)
            if (symbArr[i] == symbArr[j] || symbArr[i] == symbArr[j] - 32 || symbArr[i] == symbArr[j] + 32)
                return 1;
    return 0;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int str;
    printf("Введите количество строк: ");
    Input(&str);
    int col;
    printf("Введите количество столбцов: ");
    Input(&col);
    char matrix[100][100];

    for (int i = 0; i<str; i++)
    {
        for (int j = 0; j<col; j++)
        {
            printf("a[%d][%d] = ", i, j);
            gets_s(&matrix[i][j], 2);
        }
    }

    printf("\nВводные данные:\n");

    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    for (int i = 0; i< str; i++)
    {
        char *temp = (char *) malloc(col * sizeof(char));
        for (int j = 0; j < col; j++)
            temp[j] = matrix[i][j];

        if(CheckArr(temp, str) == 1)
        {
            BigSymb(temp, col);
            for (int j = 0; j < col; j++)
                matrix[i][j] = temp[j];
        }
    }

    printf("\nРезультат превращения:\n");

    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}