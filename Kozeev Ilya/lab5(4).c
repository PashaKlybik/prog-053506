//task 5.1 var 4

#ifndef TASK_H
#define TASK_H

typedef struct item 
{
    int digit;
    struct item *next;
    struct item *prev;
} Item;

typedef struct mnumber 
{
    Item *head;
    Item *tail;
    int n;
} MNumber;

MNumber CreateMNumber(char *initStr);

unsigned long long int ReverseNumber(unsigned long long int number);

unsigned long long int ToOctal(unsigned long long int number);

void AddDigit(MNumber *number, int digit);

void PrintMNumber(MNumber number);

unsigned long long int NumberToDec(MNumber n1);

#endif

------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>
#include <string.h>
#include "tree.h"

#ifndef TEST

int main()
{
    MNumber a = CreateMNumber("123456789123456789");
    
    PrintMNumber(a);
    printf("Number in octal: %llu\n", ToOctal(NumberToDec(a)));
    
    return 0;
}

#endif

MNumber CreateMNumber(char initStr[])
{
    MNumber number = {NULL, NULL, 0};
    int n;
    for (n = strlen(initStr)-1; n >= 0; n--)
        AddDigit(&number, initStr[n]-'0');
    return number;
}

void AddDigit(MNumber *number, int digit)
{
    Item *p = (Item *)malloc(sizeof(Item));
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

unsigned long long int NumberToDec(MNumber n1)
{
    Item *p1 = n1.head;
    unsigned long long int number = 0,rev;
    while(p1)
    {
        number = number * 10 + p1->digit; 
        p1 = p1->next;      
    }  
    rev = ReverseNumber(number);
    return rev;   
}

void PrintMNumber(MNumber number)
{
    Item *p = number.tail;
    printf("\nNumber: ");
    while (p)
    {
        printf("%d", p->digit);
        p = p->prev;
    }
} 

unsigned long long int ReverseNumber(unsigned long long int number)
{
    unsigned long long int revnum = 0;
    while (number > 0) 
    {
        revnum = revnum*10 + number%10;
        number = number/10;
    }   
    return revnum;
}
unsigned long long int ToOctal(unsigned long long int number)
{
    unsigned long long int dst = 0;
    int i = 0, counter = 0;
    
    while (number)
    {
        if (counter != 0)
        {
            dst *= 10;
        }
        dst += number % 8 ;
        number /= 8;
        counter++;
    }
    return ReverseNumber(dst);
}