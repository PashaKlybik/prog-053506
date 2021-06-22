#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct stack {
    int info;
    struct stack* next;
} Stack;

Stack* AddNode(int info, Stack* beg) {
    Stack* t = (Stack*)calloc(1, sizeof(Stack));
    t->next = beg;
    t->info = info;
    return t;
}

void DelStack(Stack* beg) {
    Stack* p = beg, *d;

    while(p->next != NULL) {
        d = p;
        p = p->next;
        free(d);
    }

    free(beg);
}

Stack* InitStack() {
    Stack* beg = (Stack*)calloc(1, sizeof(Stack));
    int num, flag;

    beg->info = 0;
    beg->next = NULL;
    printf("Стек создан\n");
    printf("Теперь введите числа в стек ([Enter] после каждого числа), 'stop' - заканчивает ввод\n");
    do {
        printf("Введите целое число ");
        flag = scanf("%i", &num);
        if(flag == 1)
            beg = AddNode(num, beg);
        fflush(stdin);
    }while (flag == 1);

    return beg;
}

void ViewStack(Stack* beg) {
    Stack* p = beg;
    while(p->next!=NULL) {
        printf("%i ",p->info);
        p = p->next;
    }
}

Stack* ReverseStack(Stack* beg) {
    Stack *rev = (Stack*)calloc(1, sizeof(Stack));
    rev->next = NULL;
    rev->info = 0;

    while(beg->next != NULL)
    {
        rev = AddNode(beg->info, rev);
        beg = beg->next;
    }

    return rev;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Stack* beg = InitStack();
    printf("\n");
    printf("Ваш стек: ");
    ViewStack(beg);
    beg = ReverseStack(beg);
    printf("\nЕго перевернутая версия: ");
    ViewStack(beg);
    printf("\n");

    return 0;
}
