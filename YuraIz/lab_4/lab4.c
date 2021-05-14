#include <stdio.h>
#include <stdlib.h>

void func(char* word, char sep) {
        int length = 0;
        while(word[length] != sep) {
                length++;
        }
        char last = word[length - 1];
        for(int i = length - 2; i >= 0;i--) {
                word[i + 1] = word[i];
        }
        word[0] = last;
        for(int i = 0; word[i] != sep; i++) {
                for(int j = i + 1; word[j] != sep; j++) {
                        if(word[i] == word[j]) {
                                word[j] = 1;
                        }
                }
        }
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

void function(char* text) {
        char** parsedText = parse(text, ' ');
        for(int i = 0; parsedText[i] != NULL; i++) {
                for(int j = 0; ; j++) {
                        if(
                                //separators
                                parsedText[i][j] == ' ' ||
                                parsedText[i][j] == '.' ||
                                parsedText[i][j] == ',' ||
                                parsedText[i][j] == '?' ||
                                parsedText[i][j] == '!' ||
                                parsedText[i][j] == '\0'
                                ) {
                                func(parsedText[i], parsedText[i][j]);
                                break;
                        }
                }
        }
        free(parsedText);
}

void func2(char* word, int length) {
        char last = word[length - 1];
        for(int i = length - 2; i >= 0;i--) {
                word[i + 1] = word[i];
        }
        word[0] = last;
        for(int i = 0; i < length; i++) {
                for(int j = i + 1; j < length; j++) {
                        if(word[i] == word[j]) {
                                word[j] = 1;
                        }
                }
        }
}

void function2(char* text) {
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
                                        text[i + j] == '\0'
                                        ) {
                                        //func(&text[i], text[i + j]);
                                        func2(&text[i], j);
                                        break;
                                }
                        }
                }
        }
}

int main() {
        char* text = (char*)malloc(64);
        sprintf(text, "this is a variant of text.");
        function2(text);
        printf("%s\n", text);
        free(text);
}