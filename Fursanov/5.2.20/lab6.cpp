#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

typedef struct item
{
    int data;
    int count_node=1;
    int sum=0;
    struct item* left;
    struct item* right;
} Item;

void AddNode(int data, Item** node, int count_node, int sum)
{
    if (*node == NULL)
    {
        *node = (Item*)calloc(1, sizeof(Item));
        (*node)->data = data;
        (*node)->count_node = count_node;
        (*node)->sum = sum + (*node)->data;
        (*node)->left = (*node)->right = NULL;
    }
    else if (data < (*node)->data)
        AddNode(data, &(*node)->left, (*node)->count_node + 1,sum + (*node)->data);
    else if (data > (*node)->data)
        AddNode(data, &(*node)->right, (*node)->count_node + 1,sum + (*node)->data);
    else
        puts("такой элемент уже есть в дереве");
}

void Print_Max(Item* node, int max_node)
{
    if (node->left)
        Print_Max(node->left, max_node);
    if (node->count_node == max_node)
    {
        printf("%d ", node->sum);
    }
    if (node->right)
        Print_Max(node->right, max_node);
}

void Max(Item* node, Item** Max_Item, int &max_node)
{
    if (node->left)
        Max(node->left,Max_Item,max_node);
        if (max_node < (node)->count_node)
        {
            max_node = (node)->count_node;
            *Max_Item = (node);
        }
    if ((node)->right)
        Max(node->right,Max_Item,max_node);
}

void LeftOrder(Item* node)
{
    if (node->left)
        LeftOrder(node->left);
    printf("%d ", node->data);

    if (node->right)
        LeftOrder(node->right);
}

int main()
{
    srand(time(NULL));
    int TEST = 20;
    setlocale(LC_ALL, "Russian");
    int i;
    Item* head = NULL;

    printf("введите элементы дерева(целые числа). ввод прекращается введением символа 0\n");

    int e=-1;
    while (1)
    {
        while (scanf("%d", &e) == 0)
        {
            printf("Некорректный ввод. попробуйте ещё раз \n");
            while (getchar() != '\n') {}
        }
        if (e == 0)break;
        AddNode(e, &head, 1, 0);
    }

    LeftOrder(head);
    printf("\n");
    int max_node = 0;
    Item* Max_Item = NULL;
    Max(head, &Max_Item, max_node);
    printf("\nмаксимальное число узлов: %d\nсуммы значений на ветках с таким количеством узлов: ", max_node);
    Print_Max(head, max_node);
    printf("\n");
}
