/*
4.1 (Variant 15)
— клавиатуры вводитс€ многострочный текст. –аспечатать слова из
текста, преобразовав их следующим образом:
Х  перенести последнюю букву в начало слова;
Х  оставить в слове только первые вхождени€ каждой буквы.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void DeleteSimilarChar(char* word, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (word[i] == word[j]) {
                word[j] = ' ';
            }
        }
    }
}
void CharTransfer(char* word, int length) {
    char last = word[length - 1];
    for (int i = length - 2; i>=0; i--) {
        word[i+1] = word[i];
    }
    word[0] = last;
}

int main() {
    setlocale(LC_ALL, "Russian");
    char* text = (char*)malloc(40);
    printf("¬ведите текст:\n");
    fgets(text, 40, stdin);

    int i = 0;
    while (text[i] != '\0') {
        if (i == 0 || text[i - 1] == ' ') {
            for (int j = 0; ; j++) {
                if (text[i + j] == ' ' || text[i + j] == '\n' || text[i + j] == '\0') 
                {
                    CharTransfer(&text[i], j);
                    DeleteSimilarChar(&text[i], j);
                    break;
                }
            }
        }
        i++;
    }

    printf("%s\n", text);
    free(text);
}