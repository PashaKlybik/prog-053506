#include <stdio.h>
#include <stdlib.h>

void ToUpperCase(char* str) {
    int len = strlen(str);
    for(int i = 0;i < len;i++) if(str[i] >= 'a' && str[i] <= 'z')  str[i]-=32;
}

void ToLowerCase(char* str) {
    int len = strlen(str);
    for(int i = 0;i < len;i++) if(str[i] >= 'A' && str[i] <= 'Z')  str[i]+=32;
}

int IsUnique(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++)
            if(str[i] == str[j]) return 0;
    }

    return 1;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    printf("Введите кол-во матриц и кол-во слов в них через пробел\n")ж
    int n,m,k;
    scanf("%i %i", &n, &m);

    char sentence[50];
    fflush(stdin);

    printf("Введите слова:\n");
    char*** arrays = (char***)calloc(n, sizeof(char**));
    for(int i = 0;i < n; i++) {
            arrays[i] = (char**)calloc(m, sizeof(char*));
            for(int j = 0;j < m; j++) {
                printf("Слово под индексом[%i][%i]: ", i, j);
                fgets(sentence, 50, stdin);
                k = strlen(sentence);

                arrays[i][j] = (char*)calloc(k, sizeof(char));
                strcpy(arrays[i][j], sentence);
            }
    }

    printf("\nПреобразование матриц...\n\n");
    for(int i = 0;i < n; i++) {
            for(int j = 0;j < m; j++) {
                    if(IsUnique(arrays[i][j]) == 0)
                        ToLowerCase(arrays[i][j]);
                    else
                        ToUpperCase(arrays[i][j]);
            }
    }

    printf("Итог:\n");
    for(int i = 0;i < n; i++) {
            printf("\n");
            for(int j = 0;j < m; j++) {
                printf("%s", arrays[i][j]);
            }
    }


    return 0;
}
