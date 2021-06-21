#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool palindrome(char* arr);
int main() {
    int n;
    char** massiv;


    printf("Number=");
    scanf("%d", &n);

    massiv = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        massiv[i] = (char*)malloc(256 * sizeof(char));
        scanf("%s", massiv[i]);
    }

    for (int i = 0; i < n; i++) {
        if (palindrome(massiv[i])) printf("%s\n", massiv[i]);
    }

    for (int i = 0; i < n; i++) {
        free(massiv[i]);
    }
    free(massiv);



    return 0;
}
bool palindrome(char* arr) {
    int a = strlen(arr);
    for (int i = 0; i < a; i++) {
        if (arr[i] != arr[a - i - 1]) {
            return false;
        }
    }
    return true;
}