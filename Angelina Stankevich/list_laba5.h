#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int value;
    struct node *next, *prev;
} NODE;

typedef struct list
{
    NODE *head, *tail;
} LIST;

void init(LIST *l);

void push_front(LIST *l, int data);

void push_back(LIST *l, int data);

int pop_front(LIST *l);

void print(LIST *l);

void createRandomCrew(LIST *l, int len);

void insert(LIST *l, NODE *prev, int data);

void unity(LIST *l1, LIST *l2, LIST *main);

void clear(LIST *l);