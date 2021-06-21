#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* pNext;
    struct Node* pPrev;
}Node;

typedef struct Queue
{
    struct Node* head;
    struct Node* tail;
}Queue;

typedef struct List
{
    struct Node* head;
    struct Node* tail;
}List;

void queue_push( Queue* q, int number);
int pop(Queue* q);
void list_push(List* list, Queue* queue1, Queue* queue2);
void output(List list);
void deleteList(List* list);


int main()
{
    system("chcp 1251");
    system("cls");
    Queue q1, q2;
    q1.tail = q1.head = q2.tail = q2.head = NULL;

    for (int i = 0, j = 9; i < 9 ; i++,j++)
    {
        queue_push(&q1, i);
        queue_push(&q2, j);
    }

    List list;
    list.tail = list.head = NULL;
    list_push(&list, &q1, &q2);

    printf("\nДвусвязный список: ");
    output(list);

    deleteList(&list);
    return 0;
}

void queue_push(Queue* q, int number)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->pNext = NULL;
    tmp->data = number;
    tmp->pNext = tmp->pPrev = NULL;
    if (q->head == NULL && q->tail == NULL)
    {
        q->head = q->tail = tmp;
    }
    else
    {
        q->tail->pNext = tmp;
        q->tail->pNext->pPrev = q->tail;
        q->tail = tmp;
    }

}

void list_push(List* list, Queue* q1, Queue* q2)
{
    while (q1->head)
    {
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->data = pop(&(*q1));
        if (list->head == NULL && list->tail == NULL)
        {
            list->head = list->tail = tmp;
        }
        else
        {
            list->tail->pNext = tmp;
            list->tail->pNext->pPrev = list->tail;
            list->tail = tmp;
        }
    }
    while (q2->head)
    {
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->data = pop(&(*q2));
        list->tail->pNext = tmp;
        list->tail->pNext->pPrev = list->tail;
        list->tail = tmp;
    }
    list->tail->pNext = NULL;
}

void output(List list)
{
    Node* tmp = list.head;
    while (tmp->pNext!=NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->pNext;
    }
}

int pop(Queue* q)
{
    Node* tmp = q->head;
    if (q->head->pNext == NULL && q->head->pPrev == NULL)
    {         //if node is the last
        int a = tmp->data;
        q->head = q->tail = NULL;
        tmp = NULL;
        free(tmp);
        return a;
    }
    else
    {
        q->head = q->head->pNext;
        q->head->pPrev->pNext = NULL;
        q->head->pPrev = NULL;
        int a = tmp->data;
        tmp = NULL;
        free(tmp);
        return a;
    }
}

void deleteList(List* list)
{
    while (list->head)
    {
        Node* tmp = list->head;
        if (list->head->pNext == NULL && list->head->pPrev == NULL)
        {     //if node is the last
            list->head = list->tail = NULL;
            tmp = NULL;
            free(tmp);
        }
        else
        {
            list->head = list->head->pNext;
            list->head->pPrev->pNext = NULL;
            list->head->pPrev = NULL;
            tmp = NULL;
            free(tmp);
        }
    }
}
