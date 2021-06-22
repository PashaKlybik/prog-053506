#include <stdio.h>

void convert(int num);

int main() {
	system("chcp 1251");
    int n, condition = 1, value;
    while (condition) {
        printf("Введите число: ");
		value = scanf("%d", &n);
        if (value == 1) {
            puts("Ваше число: ");
            toRoman(n);
            printf("\nВведите 0, чтобы выйти: \t");
            scanf("%d", &condition);
        } else
            fflush(stdin);
    }
    return 0;
}

void Convert(int num){

    char rom[13][3] = { "M\0", "CM\0", "D\0", "CD\0", "C\0", "XC\0", "L\0", "XL\0", "X\0", "IX\0", "V\0", "IV\0", "I\0"};
    int arabic[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i = 0; i < 13; i++) {
        while (num>=arabic[i]){
            printf("%s",rom[i]);
            num = num - arabic[i];
        }
    }
}
