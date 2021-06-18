//Task 1.2(8)

#include <stdio.h>

int main() {
    int number;
    printf("please, enter 4-digit number\n");
    scanf("%d", &number);
    if(number >= 10000) {
        printf("error, this is not a 4-digit number\n");
    } else {
        printf("%04d\n", number % 100 * 100 + number / 100);
    }
}
