#include <stdio.h>
#include <stdlib.h>

char** scanVocabulary() {
        int height = 16;
        char** output = calloc(height, sizeof(char*));
        FILE* vocabulary = fopen(".//lab4t2-data//vocabulary", "r");
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

int main() {
        char** vocabulary = scanVocabulary();
        for(int i = 0; vocabulary[i] != NULL; i++) {
                printf("%s\n", vocabulary[i]);
        }
        printf("%d\n", find(vocabulary, "melon"));
        for(int i = 0; vocabulary[i] != NULL; i++) {
                free(vocabulary[i]);
        }
        free(vocabulary);
}