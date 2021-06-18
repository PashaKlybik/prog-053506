#include<stdio.h>
#include<stdlib.h>

char* Itob(int num, char* buffer, int base)
{
    if (!num)
        return '\0';

    char res;
    int i, LEN = strlen(buffer);
    if (num % base > 9) res = (char)(num % base - 10) + 'A';
    else res = (char)(num % base) + '0';

    for (i = LEN; i > -1; i--)
        buffer[i + 1] = buffer[i];
    buffer[0] = res;

    Itob(num / base, buffer, base);
    return buffer;
}


int main()
{
	system("chcp 1251");
    int b;
    long n;
    printf( "Введите n = ");
    scanf_s( "%ld",&n);
    printf( "Введите систему = ");
    scanf_s("%d", &b);
    char buf[80] = "";
    itob(n, buf, b);
    printf("Номер %ld в %d системе = %s\n", n,b,buf);
    return 0;
}