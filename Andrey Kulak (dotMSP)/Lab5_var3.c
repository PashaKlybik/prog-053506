//Task 5.1. Variant 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 1024

struct List
{
    struct List* next;
    struct List* prev;
    char c;
};

int palindromeCalc(struct List* list)
{
    if (!list) return 0;
    while (list)
    {
        if (list->c != list->next->c) return 0;
        list = list->next->next;
    }
    return 1;
}

void characterAddition(struct List** list, char c)
{
    struct List* head = (struct List*)calloc(1, sizeof(struct List));
    head->c = c;
    if (*list) {
        (*list)->prev = head;
    }
    head->prev = NULL;
    head->next = *list;
    *list = head;
}

void newList(struct List** list, char* string)
{
    unsigned long i, j;
    i = 0;
    j = strlen(string) - 1;
    while (i < j)
    {
        while (!((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) && i < j)
        {
            i++;
        }
        while (!((string[j] >= 'a' && string[j] <= 'z') || (string[j] >= 'A' && string[j] <= 'Z')) && i < j)
        {
            j--;
        }
        if (i == j) return;
        characterAddition(list, string[i]);
        characterAddition(list, string[j]);
        i++;
        j--;
    }
}

void listDel(struct List** list)
{
    while (*list)
    {
        struct List* temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}

int main(void) {
    char* s = (char*)calloc(sizeof(char), size + 1);
    struct ListItem* list = NULL;
    printf("Enter a string:\n");
    scanf("%[^\n]s", s);
    getchar();
    if (s[size] != 0)
    {
        printf("Invalid input\n", size);
        return -1;
    }
    newList(&list, s);
    if (palindromeCalc(list))
    {
        printf("The entered string is a palindrome\n");
    }
    else
    {
        printf("The entered string is NOT a palindrome\n");
    }
    free(s);
    listDel(&list);
    return 0;
}