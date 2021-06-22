#include "list.h"

void init(LIST *l)
{
    l->head = NULL;
    l->tail = NULL;
}

void push_front(LIST *l, int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL)
        exit(EXIT_FAILURE);

    if (l->head == NULL)
    {
        temp->next = NULL;
        temp->value = data;

        l->head = l->tail = temp;
    }
    else if (l->head->next == NULL)
    {
        temp->next = l->tail;
        temp->prev = NULL;
        temp->value = data;

        l->head = temp;
        l->tail->prev = l->head;
    }
    else
    {
        temp->next = l->head;
        temp->prev = NULL;
        temp->value = data;

        l->head->prev = temp;
        l->head = temp;
    }
}

void push_back(LIST *l, int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL)
        exit(EXIT_FAILURE);

    if (l->head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        temp->value = data;

        l->head = l->tail = temp;
    }
    else if (l->head->next == NULL)
    {
        temp->next = NULL;
        temp->prev = l->head;
        temp->value = data;

        l->tail = temp;
        l->head->next = l->tail;
    }
    else
    {
        temp->next = NULL;
        temp->prev = l->tail;
        temp->value = data;
        l->tail->next = temp;
        l->tail = temp;
    }
}

int pop_front(LIST *l)
{
    int data;
    if (l->head == NULL)
    {
        printf("Empty!$!$!$\n");
        return -20;
    }
    else if (l->head == l->tail)
    {
        data = l->head->value;
        free(l->head);
        l->head = l->tail = NULL;
        return data;
    }
    else
    {
        NODE *temp;
        temp = l->head->next;
        temp->prev = NULL;
        data = l->head->value;
        free(l->head);
        l->head = temp;
        return data;
    }
}

void print(LIST *l)
{
    NODE *temp = l->head;
    while (temp != NULL)
    {
        printf("%d  ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void createRandomCrew(LIST *l, int len)
{
    int i, val = 1;
    for (i = 0; i < len; ++i)
    {
        push_back(l, val);
        val += rand() % 30;
    }
}

void insert(LIST *l, NODE *prev, int data)
{
    if (prev == NULL)
    {
        push_front(l, data);
        return;
    }

    if (prev == l->tail)
    {
        push_back(l, data);
        return;
    }
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL)
        exit(EXIT_FAILURE);

    temp->value = data;
    temp->next = prev->next;
    temp->prev = prev;
    NODE *tork = prev->next;
    tork->prev = temp;
    prev->next = temp;
}

void unity(LIST *l1, LIST *l2, LIST *main)
{
    while (l1->head != NULL)
    {
        push_back(main, pop_front(l1));
    }
    int data;
    NODE *temp;
    temp = l2->head;

    while (l2->head != NULL)
    {
        data = pop_front(l2);
        if (data == 1)
        {
            continue;
        }
        NODE *i;
        for (i = main->head; i; i = i->next)
        {
            if (i->prev == NULL)
            {
                continue;
            }

            if (data <= i->value)
            {
                insert(main, i->prev, data);
                break;
            }
        }
    }
}

void clear(LIST *list)
{
    NODE *li = list->head, *temp;
    while (li != NULL)
    {
        temp = li;
        li = li->next;
        free(temp);
    }

    list->head = NULL;
    list->tail = NULL;
}