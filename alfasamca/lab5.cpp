#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<malloc.h> 

typedef struct node
{
    int num;
    struct node* next;
} Node;

typedef struct list
{
    Node* head;
    Node* top;
    int size;
} List;


void push(List* list, int num);
void print(List list);
void swap(List* list);
int main()
{
    List list = { NULL, NULL, 0 };

    for (int i = 0; i < 5; i++)
    {
        push(&list, i);
    }

    print(list);

    swap(&list);

    printf("\n");

    print(list);
}
void push(List* list, int num)
{
    Node* p = (Node*)malloc(sizeof(Node));

    p->num = num;
    p->next = NULL;

    if (list->head == NULL) {
        list->head = list->top = p;
    }
    else {
        list->top->next = p;
        list->top = p;
    }

    list->size++;
}
void print(List list)
{
    Node* p = list.head;

    while (p)
    {
        printf("%d ", p->num);
        p = p->next;
    }
}
void swap(List* list) {
    int i = 0, j = 0;

    Node* p = list->head;
    Node* e = list->head;
    Node* arrayPNext[5];
    Node* arrayNum[5];

    while (p != NULL)
    {
        arrayPNext[i] = p;
        arrayNum[i]->num = p->num;
        p = p->next;
        i++;
    }

    i--;

    p = list->head;

    while (p != NULL)
    {
        e = p;
        p = arrayPNext[i];
        p->num = arrayNum[j]->num;
        p = e->next;
        i--;
        j++;
    }
}