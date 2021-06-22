#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>

int minus = 0;

typedef struct list
{
    int digit;
    struct list* next;
    struct list* prev;
}
List;

typedef struct RazNum
{
    List* head;
    List* tail;
    int n;
}
Num;

Num CreateNum(char *initStr);
void PrintNum(Num number);
void DeleteNum(Num *number);

void AddDigit(Num *number, int digit);
Num Base10toBase8(Num n1);
void CheckMinus(const char *str);

void CheckMinus(const char *str)
{
    if (str[0] == '-')
        minus = 1;
}

void DeleteNum(Num* number)
{
    List* temp;
    while (number->n != 0)
    {
        temp = number->tail;
        number->tail = number->tail->prev;
        number->n--;
        if (number->n != 0)
        {
            number->tail->next = NULL;
        }
        else if (number->n == 0)
        {
            number->head = number->tail = NULL;
            number->n = 0;
        }
        free(temp);
    }
}

Num CreateNum(char *initStr)
{
    Num number = {NULL, NULL, 0 };
    for (int i = strlen(initStr) - 1; i >= 0; i--)
    {
        if (initStr[i] != '-')
        {
            AddDigit(&number, initStr[i] - '0');
        }
    }
    return number;
}

void AddDigit(Num *number, int digit)
{
    List* p = (List*)malloc(sizeof(List));
    p->digit = digit;
    p->next = p->prev = NULL;
    if (number->head == NULL)
        number->head = number->tail = p;
    else
    {
        number->tail->next = p;
        p->prev = number->tail;
        number->tail = p;
    }
    number->n++;
}

int From10to8(int number)
{
    int ost, zeloe = 1, arr[100];
    int i = 0, l = 0;
    while (zeloe != 0)
    {
        zeloe = number/8;
        ost = number%8;
        number = zeloe;
        arr[i] = ost;
        i++, l++;
    }
    number = 0;
    for (int i = l-1; i >= 0; i--)
    {
        number *= 10;
        number += arr[i];
    }
    return number;
}

Num Base10toBase8(Num n1)
{
    List* p1 = n1.head;
    int pos = 0, s1, s = 5, i = 0;
    int arr1[s], arr2[s];
    while (p1)
    {
        s1 = p1->digit; p1 = p1->next;
        arr1[i] = s1;
        i++;
    }
    int ii = i;
    for (int j = 0; j < ii; j++, i--)
    {
        arr2[j] = arr1[i-1];
    }
    int value = 0;
    for (size_t i = 0; i < ii; ++i)
    {
        value *= 10;
        value += arr2[i];
    }
    if (minus == 1)
    {
        printf("Your number in Base10 = -%d", value);
    }
    else printf("Your number in Base10 = %d", value);


    value = From10to8(value);
    Num sum = CreateNum("");
    AddDigit(&sum, value);
    return sum;
}

void PrintNum(Num number)
{
    List* p = number.tail;
    while (p)
    {
        printf("%d", p->digit);
        p = p->prev;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    printf("Введите десятичное число: ");
    char str[200];
    gets_s("%c", &str);
    CheckMinus(str);
    Num a = CreateNum(str);
    printf("\n");

    Num c = Base10toBase8(a);
    if (minus == 1)
    {
        printf("\nРезультат в восьмеричном формате = -");
    }
    else printf("\nРезультат в восьмеричном формате = ");
    PrintNum(c);
    printf("\n");

    DeleteNum(&a);
    DeleteNum(&c);
    return 0;
}