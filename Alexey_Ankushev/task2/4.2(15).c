/*
Lab 4.2 (Variant 15)
В  заданном  текстовом  файле  подсчитать  частоту  использования 
каждого слова из словаря (другого текстового файла). 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Проверка словаря на существование + его запись в строку
char** Dictionary();

//Сравнение двух строк.
//Равны - 0
//Меньше - -1
//Больше - 1
int Equals(char* string1, char* string2);

//Возвращает порядковый номер слова из словаря
int WordIndex(char** vocabulary, char* string);

//Возвращает частоту использования слов из словаря.
void DictionaryEntries(char* text, int* arr, char** vocabulary);

int main() {
    char** vocabulary = Dictionary();
    int length;
    for (length = 0; vocabulary[length] != NULL; length++);
    int* arr = (int*)calloc(length, sizeof(int));

    FILE* textFile = fopen("FileData/Text.txt", "r");
    if (textFile == NULL) {
        printf("Файл Text.txt не существует\n");
        exit(1);
    }
    for (char buff[80]; fgets(buff, 80, textFile) != NULL;) {
        DictionaryEntries(buff, arr, vocabulary);
    }
    fclose(textFile);

    for (int i = 0; i < length; i++) {
        printf("%s: %2d\n", vocabulary[i], arr[i]);
    }

    for (int i = 0; vocabulary[i] != NULL; free(vocabulary[i++]));
    free(vocabulary);
    free(arr);
}

char** Dictionary() {
    const int BUFF_LENGTH = 16;
    int height = 32;
    FILE* vocabulary = fopen("FileData/Vocabulary.txt", "r");
    if (vocabulary == NULL) {
        printf("Файл Vocabulary.txt не существует\n");
        exit(1);
    }
    char** output = (char**)calloc(height, sizeof(char*));
    char* buff = (char*)malloc(BUFF_LENGTH);
    for (int i = 0; fgets(buff, BUFF_LENGTH, vocabulary) != NULL; i++) {
        for (int j = 0; j < BUFF_LENGTH; j++) {
            if (buff[j] == '\n') {
                buff[j] = '\0';
                break;
            }
        }
        output[i] = buff;
        buff = (char*)malloc(BUFF_LENGTH);
    }
    free(buff);
    fclose(vocabulary);
    return output;
}

int Equals(char* string1, char* string2) {
    for (int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++) {
        if (string1[i] < string2[i]) {
            return -1;
        }
        else if (string1[i] > string2[i]) {
            return 1;
        }
    }
    return 0;
}

int WordIndex(char** vocabulary, char* string) {
    static int length = 0;
    if (length == 0) {
        for (; vocabulary[length] != NULL; length++);
    }
    int first = 0, last = length;
    while (first != last) {
        int temp = Equals(string, vocabulary[(first + last) / 2]);
        if (temp == 0) {
            return (first + last) / 2;
        }
        else if (temp == 1) {
            first = (first + last) / 2;
        }
        else if (temp == -1) {
            last = (first + last) / 2;
        }
    }
    return -1;
}

void DictionaryEntries(char* text, int* arr, char** vocabulary) {
    char* word;
    for (int i = 0; text[i] != '\0'; i++) {
        if (i == 0 || text[i - 1] == ' ') {
            for (int j = 0; ; j++) {
                if (text[i + j] == ' ' || text[i + j] == '\n' || text[i + j] == '\0') {
                    word = (char*)malloc(j + 1);
                    for (int n = 0; n < j; n++) {
                        word[n] = text[i + n];
                    }
                    word[j] = '\0';
                    int result = WordIndex(vocabulary, word);
                    if (result != -1) {
                        arr[result]++;
                    }
                    free(word);
                    break;
                }
            }
        }
    }
}