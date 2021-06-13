#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    char* brand = (char*)malloc(100 * sizeof(char));
    char* year = (char*)malloc(100 * sizeof(char));
    char* engine_capacity = (char*)malloc(100 * sizeof(char));
    char* mileage = (char*)malloc(100 * sizeof(char));
    char* condition = (char*)malloc(100 * sizeof(char));
    char* price = (char*)malloc(100 * sizeof(char));
    struct Node* next;
    struct Node* previous;
} Node;

void printLinkedList(Node* head, int com);
void push(Node** head, char* brand, char* year, char* engine_capacity, char* mileage, char* condition);

typedef struct Node1
{
    char* FIO = (char*)malloc(100 * sizeof(char));
    char* contacts = (char*)malloc(100 * sizeof(char));
    char* desired_brand = (char*)malloc(100 * sizeof(char));
    char* year = (char*)malloc(100 * sizeof(char));
    char* engine_capacity = (char*)malloc(100 * sizeof(char));
    char* mileage = (char*)malloc(100 * sizeof(char));
    char* finance = (char*)malloc(100 * sizeof(char));
    struct Node1* next;
    struct Node1* previous;
} Node1;

Node* search1(Node1* head1, Node* head, Node** search)
{
    while (head != NULL)
    {
        if (strcmp(head1->desired_brand, head->brand) == 0 && atoi(head1->year)>= atoi(head->year) && atoi(head1->engine_capacity) <= atoi(head->engine_capacity) && atoi(head1->mileage)>= atoi(head->mileage) && atoi(head1->finance) >= atoi(head->price))
            push(search, head->brand, head->year, head->engine_capacity, head->mileage, head->condition);
        head = head->next;
    }
    return *search;
}

void search2(Node1* head1, Node* head, Node* headtmp)
{
    float total = 0;
    while (head1 != NULL)
    {
        head = headtmp;
        while (head != NULL)
        {
            if (strcmp(head1->desired_brand, head->brand) == 0 && atoi(head1->year) >= atoi(head->year) && atoi(head1->engine_capacity) <= atoi(head->engine_capacity) && atoi(head1->mileage) >= atoi(head->mileage) && atoi(head1->finance) >= atoi(head->price))
            {
                char* h = (char*)malloc(100 * sizeof(char));
                sprintf(h, "%.2f", atof(head->price)*3/23);
                total += atof(h);
                printf("%s-%s $\n", head1->FIO, h);
                break;
            }
            head = head->next;
        }
        head1 = head1->next;
    }
    printf("заработок со всех клиентов:\n%.2f $", total);
}

void push1(Node1** head, char* FIO, char* contacts, char* desired_brand, char* year, char* engine_capacity, char* mileage, char* finance)
{
    Node1* tmp = (Node1*)malloc(sizeof(Node1));
    tmp->FIO = FIO;
    tmp->contacts = contacts;
    tmp->desired_brand = desired_brand;
    tmp->year = year;
    tmp->engine_capacity = engine_capacity;
    tmp->mileage = mileage;
    tmp->finance = finance;
    tmp->next = (*head);
    if ((*head) != NULL)
    {
        tmp->previous = (*head)->previous;
        (*head)->previous = tmp;
    }
    else tmp->previous = NULL;
    (*head) = tmp;
}

void pop1(Node1** head)
{
    Node1* prev = NULL;
    if (head == NULL)
    {
        exit(-1);
    }
    prev = (*head);
    (*head) = (*head)->next;
    if ((*head) != NULL)
        (*head)->previous = NULL;
    free(prev);
}

Node1* getLast1(Node1* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    while (head->next)
    {
        head = head->next;
    }
    return head;
}

int countLast1(Node1* head)
{
    int count = 0;
    if (head == NULL)
    {
        return 0;
    }
    while (head->next)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node1* getNth(Node1* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

void deleteNth1(Node1** head, int n)
{
    if (n == 0)
    {
        pop1(head);
    }
    else
    {
        Node1* prev = getNth(*head, n - 1);
        Node1* elm = prev->next;
        prev->next = elm->next;
        prev = prev->next;
        if (elm->next != NULL)
        {
            elm = elm->next;
            elm->previous = prev->previous->previous;
        }
    }
}

void printLinkedList1(Node1* head, int com, Node* head1)
{
    Node1* temp = head;
    Node1* temp1 = head;
    Node1* temp2 = head;
    int a = 0;
    int n = 0;
    while (1)
    {
        if (temp == NULL && a != 224)
        {
            system("cls");
            printf("список пуст");
        }
        else if (a != 224)
        {
            system("cls");
            printf("страница %d\n", n + 1);
            printf("ФИО клиента: %s\n", head->FIO);
            printf("номер телефона клиента: %s\n", head->contacts);
            printf("желаемая марка авто: %s\n", head->desired_brand);
            printf("желаемый год выпуска авто не позднее: %s\n", head->year);
            printf("желаемый объёем двигателя не менее: %s см.к.\n", head->engine_capacity);
            printf("желаемый пробег авто не более: %s км.\n", head->mileage);
            printf("финансы клиента: %s $\n", head->finance);

        }

            a = _getch();

            if (a == 77)
            {
                if (temp == NULL);
                else if (head->next == NULL) { n = 0; head = temp; }
                else
                {
                    n++;
                    head = head->next;
                }
            }
            else if (a == 75 && head != NULL)
            {
                if (temp == NULL);
                else if (head->previous == NULL) { n = countLast1(temp); head = getLast1(head); }
                else
                {
                    n--;
                    head = head->previous;
                }
            }
            else if (a == 27 && head != NULL)return;
            else if (a == 45 && head != NULL && !com)
            {
                if (temp == NULL)printf;
                else
                {
                    deleteNth1(&temp, n);
                    n = 0; head = temp;
                }
            }
            else if (a == 13 && head != NULL && !com)
            {
                Node* search = NULL;
                printLinkedList(search1(head, head1, &search), 1);
            }
            else if (a == 43 && !com)
            {
                system("cls");
                char** klient1 = (char**)malloc(8 * sizeof(char*));
                for (int i = 0; i < 7; i++)
                {
                    klient1[i] = (char*)malloc(100 * sizeof(char));
                    fgets(klient1[i], 100, stdin);
                    for (int j = 0; j < 100; j++)
                        if (klient1[i][j] == '\n') { klient1[i][j] = '\0'; break; }

                }
                push1(&temp, klient1[0], klient1[1], klient1[2], klient1[3], klient1[4], klient1[5], klient1[6]);
                n++;

            }
            else if (a == 59)
            {
                system("cls");
                printf("esc-назад\nстрелка влево-предыдущая страница\nстрелка вправо-следующая страница\nenter-подбор подходящих авто");
                while (_getch() != 27);
            }
    }
    printf("\n");
}