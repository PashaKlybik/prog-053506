#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Node 
{
    char* brand = (char*)malloc(100*sizeof(char));
    char* year = (char*)malloc(100 * sizeof(char));
    char* engine_capacity = (char*)malloc(100 * sizeof(char));
    char* mileage = (char*)malloc(100 * sizeof(char));
    char* condition = (char*)malloc(100 * sizeof(char));
    char* price = (char*)malloc(100 * sizeof(char));
    struct Node* next;
    struct Node* previous;
} Node;

void push(Node** head, char* brand, char* year, char* engine_capacity, char* mileage, char* condition)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->brand = brand;
    tmp->year = year;
    tmp->engine_capacity = engine_capacity;
    tmp->mileage = mileage;
    tmp->condition = condition;
    char* h = (char*)malloc(100 * sizeof(char));
    if(2021-atoi(year)<=3)
    sprintf(h, "%.2f", ((atof(engine_capacity) * 0.6) + 2500) * 1.15);
    else if (2021 - atoi(year) <= 10)
    {
        if (atof(engine_capacity) < 2500)
            sprintf(h, "%.2f", ((atof(engine_capacity) * 0.35)+2500)*1.15);
        else
            sprintf(h, "%.2f", ((atof(engine_capacity) * 0.6) + 2500) * 1.15);
    }
    else if(2021 - atoi(year) <= 14)
        sprintf(h, "%.2f", ((atof(engine_capacity) * 0.6) + 2500) * 1.15);
    else 
        sprintf(h, "%.2f", ((atof(engine_capacity) * 2) + 2500) * 1.15);
    tmp->price = h;
    tmp->next = (*head);
    if ((*head) != NULL)
    {
        tmp->previous = (*head)->previous;
        (*head)->previous = tmp;
    }
    else tmp->previous = NULL;
    (*head) = tmp;
}

Node* searchbrand(Node** head, char* brand, Node** search)
{
    while ((*head) != NULL)
    {
        if (strcmp((*head)->brand, brand) == 0)
            push(search, (*head)->brand, (*head)->year, (*head)->engine_capacity, (*head)->mileage, (*head)->condition);
        (*head) = (*head)->next;
    }
    return *search;
}

Node* searchcondition(Node** head, char* condition, Node** search)
{
    while ((*head) != NULL)
    {
        if (strcmp((*head)->condition, condition) == 0)
            push(search, (*head)->brand, (*head)->year, (*head)->engine_capacity, (*head)->mileage, (*head)->condition);
        (*head) = (*head)->next;
    }
    return *search;
}

Node* searchyear(Node** head, char* year, Node**search)
{
    while ((*head) != NULL)
    {
        if (strcmp((*head)->year, year)==0)
            push(search, (*head)->brand, (*head)->year, (*head)->engine_capacity, (*head)->mileage, (*head)->condition);
        (*head) = (*head)->next;
    }

    return *search;
}

Node* searchengine_capacity(Node** head, char* engine_capacity, Node** search)
{
    while ((*head) != NULL)
    {
        if (strcmp((*head)->engine_capacity, engine_capacity) == 0)
            push(search, (*head)->brand, (*head)->year, (*head)->engine_capacity, (*head)->mileage, (*head)->condition);
        (*head) = (*head)->next;
    }
    return *search;
}

Node* searchmileage(Node** head, char* mileage, Node** search)
{
    while ((*head) != NULL)
    {
        if (strcmp((*head)->mileage, mileage) == 0)
            push(search, (*head)->brand, (*head)->year, (*head)->engine_capacity, (*head)->mileage, (*head)->condition);
        (*head) = (*head)->next;
    }
    return *search;
}

Node* searchprice(Node** head, char* price, Node** search)
{
    while ((*head) != NULL)
    {
        if (strcmp((*head)->price, price) == 0)
            push(search, (*head)->brand, (*head)->year, (*head)->engine_capacity, (*head)->mileage, (*head)->condition);
        (*head) = (*head)->next;
    }
    return *search;
}

void pop(Node** head) 
{
    Node* prev = NULL;
    if (head == NULL) 
    {
        exit(-1);
    }
    prev = (*head);
    (*head) = (*head)->next;
    if((*head)!=NULL)
    (*head)->previous = NULL;
    free(prev);
}

int countLast(Node* head)
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

Node* getLast(Node* head) 
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

Node* getNth(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

void deleteNth(Node** head, int n) 
{
    if (n == 0)
    {
    pop(head);
    }
    else 
    {
        Node* prev = getNth(*head, n - 1);
        Node* elm = prev->next;
        prev->next = elm->next;
        prev = prev->next;
        if(elm->next!=NULL)
        {
            elm = elm->next;
            elm->previous = prev->previous->previous;
        }
    }
}

void swapstr(char*& a, char*& b)
{
    char* temp = (char*)malloc(100 * sizeof(char));
    temp = b;
    b = a;
    a = temp;

}

void swap(Node** a, Node** b)
{
    swapstr((*a)->brand, (*b)->brand);
    swapstr((*a)->condition, (*b)->condition);
    swapstr((*a)->engine_capacity, (*b)->engine_capacity);
    swapstr((*a)->mileage, (*b)->mileage);
    swapstr((*a)->year, (*b)->year);
    swapstr((*a)->price, (*b)->price);
}


void sortprise(Node** head)
{
    Node* tmp = (*head)->next;
    while ((*head)->next != NULL)
    {
        tmp = (*head)->next;
        while (tmp != NULL)
        {
            if (atoi(tmp->price) < atoi((*head)->price))
                swap(&tmp, head);
            tmp = tmp->next;
        }
        (*head) = (*head)->next;
    }
}

void sortyear(Node** head)
{
    Node* tmp = (*head)->next;
    while ((*head)->next != NULL)
    {
        tmp = (*head)->next;
        while (tmp != NULL)
        {
            if (atoi(tmp->year) < atoi((*head)->year))
                swap(&tmp, head);
            tmp = tmp->next;
        }
        (*head) = (*head)->next;
    }
}

void printLinkedList(Node* head,int com)
{
    Node* temp = head;
    Node* temp1 = head;
    Node* temp2 = head;
    int a = 0;
    int n = 0;
    while (1)
    {
        if (temp == NULL && a != 224)
        {
            system("cls");
            printf("список пуст");
        }
        else if(a!=224)
        {
            system("cls");
            printf("страница %d\n",n+1);
            printf("марка авто: %s\n",head->brand);
            printf("год выпуска авто: %s\n",head->year);
            printf("объёем двигателя: %s см.к.\n",head->engine_capacity);
            printf("пробег авто: %s км.\n",head->mileage);
            printf("состояние авто: %s\n",head->condition);
            printf("цена: %s $\n", head->price);
        }

        a = _getch();

        if (a == 77 && head != NULL)
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
            else if (head->previous == NULL) { n = countLast(temp); head = getLast(head); }
            else
            {
                n--;
                head = head->previous;
            }
        }
        else if (a == 27)return;
        else if (a == 45 && !com)
        {
            if (head != NULL)
            {
                printf("вы уверены что хотите удалить авто?");
                char f = _getch();
                if (f == 13)
                {
                    deleteNth(&temp, n);
                    n = 0; head = temp;
                }
                if (f == 27)continue;
            }
        }
        else if (a == 43 && !com)
        {
            system("cls");
            char** auto1 = (char**)malloc(6 * sizeof(char*));
            for (int i = 0; i < 5; i++)
            {
                if (i == 0)printf("введите марку авто\n");
                if (i == 1)printf("введите год выпуска\n");
                if (i == 2)printf("введите объём двигателя\n");
                if (i == 3)printf("введите пробег авто\n");
                if (i == 4)printf("введите состояние\n");
                auto1[i] = (char*)malloc(100 * sizeof(char));
                if (i > 0 && i < 4)
                {
                    float h = 0;
                    while (scanf("%f", &h) <= 0)
                    {
                        printf("Некорректный ввод. попробуйте ещё раз \n");
                        while (getchar() != '\n') {}
                    }
                    sprintf(auto1 [i], "%.2f",h);
                    getchar();
                }
                else
                {
                    fgets(auto1[i], 100, stdin);
                    for (int j = 0; j < 100; j++)
                        if (auto1[i][j] == '\n') { auto1[i][j] = '\0'; break; }
                }

            }
            push(&temp, auto1[0], auto1[1], auto1[2], auto1[3], auto1[4]);
            n++;
        }
        else if (a == 59 && !com)
        {
            system("cls");
            printf("esc-назад\nстрелка влево-предыдущая страница\nстрелка вправо-следующая страница\nминус-удалить авто\nплюс-добавить авто\nтаб-поиск\nстрелка вверх-сортировка бо году\nстрелка вниз-сортировка по цене");
            while (_getch() != 27);
        }
        else if (a == 59 && com)
        {
            system("cls");
            printf("esc-назад\nстрелка влево-предыдущая страница\nстрелка вправо-следующая страница");
            while (_getch() != 27);
        }
        else if (a == 72 && head != NULL && !com)
        {
            temp1 = temp;
            if (temp->next != NULL)
                sortyear(&temp1);
        }
        else if (a == 80 && head != NULL && !com)
        {
            temp1 = temp;
            if (temp->next != NULL)
            sortprise(&temp1);
        }
        else if (a == 9 && head != NULL && !com)
        {
            printf("Поиск по:\n1.Бренду\n2.Году выпуска\n3.Объему двигателя\n4.Пробегу\n5.Состояние\n6.Цене\n");
            int search1;
            char* sear = (char*)malloc(100 * sizeof(char));
            while (1)
            {
                search1 = _getch();
                if (search1 == 49)
                {
                    fgets(sear, 100, stdin);
                    for (int j = 0; j < 100; j++)
                        if (sear[j] == '\n') { sear[j] = '\0'; break; }
                    Node* search = NULL;
                    temp2 = temp;
                    printLinkedList(searchbrand(&temp2, sear, &search), 1); break;
                }
                else if (search1 == 50)
                {
                    fgets(sear, 100, stdin);
                    for (int j = 0; j < 100; j++)
                        if (sear[j] == '\n') { sear[j] = '\0'; break; }
                    Node* search = NULL;
                    temp2 = temp;
                    printLinkedList(searchyear(&temp2, sear, &search), 1); break;
                }
                else if (search1 == 51)
                {
                    fgets(sear, 100, stdin);
                    for (int j = 0; j < 100; j++)
                        if (sear[j] == '\n') { sear[j] = '\0'; break; }
                    Node* search = NULL;
                    temp2 = temp;
                    printLinkedList(searchengine_capacity(&temp2, sear, &search), 1); break;
                }
                else if (search1 == 52)
                {
                    fgets(sear, 100, stdin);
                    for (int j = 0; j < 100; j++)
                        if (sear[j] == '\n') { sear[j] = '\0'; break; }break;
                    Node* search = NULL;
                    temp2 = temp;
                    printLinkedList(searchmileage(&temp2, sear, &search), 1);
                }
                else if (search1 == 53)
                {
                    fgets(sear, 100, stdin);
                    for (int j = 0; j < 100; j++)
                        if (sear[j] == '\n') { sear[j] = '\0'; break; }
                    Node* search = NULL;
                    temp2 = temp;
                    printLinkedList(searchcondition(&temp2, sear, &search), 1); break;
                }
                else if (search1 == 54)
                {
                    fgets(sear, 100, stdin);
                    for (int j = 0; j < 100; j++)
                        if (sear[j] == '\n') { sear[j] = '\0'; break; }
                    Node* search = NULL;
                    temp2 = temp;
                    printLinkedList(searchprice(&temp2, sear, &search), 1); break;
                }
                else if (search1 == 27)break;
                else printf("такого запроса нет\n");
            }
        }
    }
    printf("\n");
}
