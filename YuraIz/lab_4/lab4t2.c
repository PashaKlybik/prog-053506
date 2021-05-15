#include <stdio.h>
#include <stdlib.h>

char** scanVocabulary() {
        int height = 16;
        char** output = calloc(height, sizeof(char*));
        FILE* vocabulary = fopen("./lab4t2-data/vocabulary", "r");
        char* buff = (char*)malloc(32);
        if(!vocabulary) {
                printf("file doesn't exist\n");
                exit(1);
        }
        int i;
        for(i = 0; fgets(buff, 32, vocabulary) != NULL; i++) {
                for(int j = 0; j < 32; j++) {
                        if(buff[j] == '\n') {
                                buff[j] = '\0';
                                break;
                        }
                }
                output[i] = buff;
                buff = (char*)malloc(32);
        }
        output[i] = NULL;
        free(buff);
        fclose(vocabulary);
        return output;
}

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

int find(char** vocabulary, char* string) {
        for(int i = 0; vocabulary[i] != NULL; i++) {
                if(compareStrings(string, vocabulary[i]) == 0) {
                        return i;
                }
        }
        return -1;
}

char** parse(char* input, char sep) {
        int length = 0;
        for(int i = 0; input[i] != '\0'; i++) {
                if(input[i] == sep) {
                        length++;
                }
        }
        char** output = (char**)calloc(length + 2, sizeof(char*));
        output[0] = input;
        output[length + 1] = NULL;
        for(int i = 0, j = 0; input[i] != '\0'; i++) {
                if(input[i] == sep) {
                        j++;
                        output[j] = &input[i + 1];
                }
        }
        return output;
}

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
                                        word = (char*)malloc(j);
                                        for(int n = 0; n < j; n++) {
                                                word[n] = text[i + n];
                                        }
                                        word[j] = '\0';
                                        arr[find(vocabulary, word)]++;
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
        char buff[80];
        while(fgets(buff, 80, textFile) != NULL) {
                stringFinder(buff, arr, vocabulary);
        }

        for(int i = 0; i < length; i++) {
                printf("%10s: %2d\n", vocabulary[i], arr[i]);
        }


        fclose(textFile);
        free(arr);
        for(int i = 0; vocabulary[i] != NULL; i++) {
                free(vocabulary[i]);
        }
        free(vocabulary);
}