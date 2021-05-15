#include <stdio.h>
#include <stdlib.h>

// Returns vocabulary
char** scanVocabulary() {
        const int BUFF_LENGTH = 16;
        int height = 32;
        FILE* vocabulary = fopen("./lab4t2-data/vocabulary", "r");
        if(vocabulary == NULL) {
                printf("file doesn't exist\n");
                exit(1);
        }
        char** output = (char**)calloc(height, sizeof(char*));
        char* buff = (char*)malloc(BUFF_LENGTH);
        for(int i = 0; fgets(buff, BUFF_LENGTH, vocabulary) != NULL; i++) {
                for(int j = 0; j < BUFF_LENGTH; j++) {
                        if(buff[j] == '\n') {
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

/* Comparing two strings:
 * if string1 == string2 returns 0
 * if string1 < string2 returns -1
 * if string1 > string2 returns 1
 */
int compareStrings(char* string1, char* string2) {
        for(int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++) {
                if(string1[i] < string2[i]) {
                        return -1;
                } else if(string1[i] > string2[i]) {
                        return 1;
                }
        }
        return 0;
}

/* Returns index of word in vocabulary
 * if word doesn't exist returns -1
 */
int modernFind(char** vocabulary, char* string) {
        static int length = 0;
        if(length == 0) {
                for(; vocabulary[length] != NULL; length++);
        }
        int first = 0, last = length;
        while(first != last) {
                int temp = compareStrings(string, vocabulary[(first + last) / 2]);
                if(temp == 0) {
                        return (first + last) / 2;
                } else if(temp == 1) {
                        first = (first + last) / 2;
                } else if(temp == -1) {
                        last = (first + last) / 2;
                }
        }
        return -1;
}

// Returns count of uses each words in vocabulary
void stringFinder(char* text, int* arr, char** vocabulary) {
        char* word;
        for(int i = 0; text[i] != '\0'; i++) {
                if(i == 0 || text[i - 1] == ' ') {
                        for(int j = 0; ; j++) {
                                if(
                                        //separators
                                        text[i + j] == ' ' ||
                                        text[i + j] == '.' ||
                                        text[i + j] == ',' ||
                                        text[i + j] == '?' ||
                                        text[i + j] == '!' ||
                                        text[i + j] == '\n' ||
                                        text[i + j] == '\0'
                                        ) {
                                        word = (char*)malloc(j + 1);
                                        for(int n = 0; n < j; n++) {
                                                word[n] = text[i + n];
                                        }
                                        word[j] = '\0';
                                        int result = modernFind(vocabulary, word);
                                        if(result != -1) {
                                                arr[result]++;
                                        }
                                        free(word);
                                        break;
                                }
                        }
                }
        }
}

int main() {
        char** vocabulary = scanVocabulary();
        int length;
        for(length = 0; vocabulary[length] != NULL; length++);
        int* arr = (int*)calloc(length, sizeof(int));

        FILE* textFile = fopen("./lab4t2-data/text", "r");
        if(textFile == NULL) {
                printf("file doesn't exist\n");
                exit(1);
        }
        for(char buff[80]; fgets(buff, 80, textFile) != NULL;) {
                stringFinder(buff, arr, vocabulary);
        }
        fclose(textFile);

        for(int i = 0; i < length; i++) {
                printf("%10s: %2d\n", vocabulary[i], arr[i]);
        }

        for(int i = 0; vocabulary[i] != NULL; free(vocabulary[i++]));
        free(vocabulary);
        free(arr);
}