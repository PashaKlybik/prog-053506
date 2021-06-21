#include <stdio.h>
#include <stdlib.h>
//Task 4.1 (15)

/* Converts of the word as follows:
 * 1. transfers the last letter to the top of the word
 * 2. leaves in the word only the first entry of each letter
 */
void wordConverter(char* word, int length) {
        char last = word[length - 1];
        for(int i = length - 2; i >= 0;i--) {
                word[i + 1] = word[i];
        }
        word[0] = last;
        for(int i = 0; i < length; i++) {
                for(int j = i + 1; j < length; j++) {
                        if(word[i] == word[j]) {
                                word[j] = '\a';
                        }
                }
        }
}

//Do word conversation with wordConverter for all string
void stringConverter(char* text) {
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
                                        wordConverter(&text[i], j);
                                        break;
                                }
                        }
                }
        }
}

int main() {
        char* text = (char*)malloc(32);
        sprintf(text, "this is a variant of text.");
        printf("Do you want to enter text manually? ");
        char answer = getchar();
        setbuf(stdin, NULL);
        if(
                answer == 'Y' ||
                answer == 'y'
                ) {
                printf("Your text:\n");

                fgets(text, 32, stdin);
        } else {
                printf("%s\n", text);
        }
        stringConverter(text);
        printf("\r\r\r%s\n", text);
        free(text);
}
