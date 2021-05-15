//task 4.1 var21
#include <stdio.h>
#include <locale.h>
#include <string.h>
void ItoB(int n, char s[16], int b)
{
    int i = 0,buf=n;
    for (;n>0;) {
        buf = n % b;
        n = n / b;
        if (buf < 10)
            s[i] = buf+48;
        else if (buf == 10)
            s[i] = 'A';
        else if (buf == 11)
            s[i] = 'B';
        else if (buf == 12)
            s[i] = 'C';
        else if (buf == 13)
            s[i] = 'D';
        else if (buf == 14)
            s[i] = 'E';
        else if (buf == 15)
            s[i] = 'F';
        i++;
    }
    s[i] = '\0';
    char bufm;
    int size = strlen(s);
    for (int i = 0; i < size/2; i++) {
        bufm = s[i];
        s[i] = s[size - 1 - i];
        s[size - 1 - i] = bufm;
    }
    puts(s);
}
int main()
{
    int n, b, cheack = 0;
    char s[16];
    setlocale(LC_ALL, "rus");
    printf("Введите n: ");
    scanf_s("%d", &n);
    printf("Введите b: ");
    scanf_s("%d", &b);
    if (b < 2 || b>16)
        cheack = 1;
    if (cheack == 0) {
        ItoB(n, s, b);
    }
    else{
        printf("Не правильный ввод");
    }

}

