#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include<malloc.h>

typedef struct tree
{
    int data;
    struct tree* pLeft;
    struct tree* pRight;

} Node;

Node* add(Node* root, int data)
{
    if (root == NULL)
    {
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->data = data;
        tmp->pLeft = tmp->pRight = NULL;
        root = tmp;
        return root;
    }
    else
    {

        Node* root2 = root;
        Node* root3 = NULL;
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->data = data;

        while (root2 != NULL)
        {
            root3 = root2;
            if (data < root2->data)
                root2 = root2->pLeft;
            else
                root2 = root2->pRight;
        }

        tmp->pLeft = NULL;
        tmp->pRight = NULL;

        if (data < root3->data)
            root3->pLeft = tmp;
        else root3->pRight = tmp;
        return root;
    }
}

void pre_order(Node* root)
{

    if (root)
    {
        printf("%d ", root->data);
        pre_order(root->pLeft);
        pre_order(root->pRight);
    }
}

void in_orderA(Node* root)
{
    if (root)
    {
        in_orderA(root->pLeft);
        printf("%d ", root->data);
        in_orderA(root->pRight);
    }
}

void in_orderD(Node* root)
{
    if (root)
    {
        in_orderD(root->pRight);
        printf("%d ", root->data);
        in_orderD(root->pLeft);
    }
}

void post_order(Node* root)
{
    if (root)
    {
        post_order(root->pLeft);
        post_order(root->pRight);
        printf("%d ", root->data);
    }
}

void FreeTree(Node* root)
{
    if (!root) return;
    FreeTree(root->pLeft);
    FreeTree(root->pRight);
    free (root);
    return;
}

int main()
{
    system("chcp 1251");
    system("cls");
    char str[30];
    printf("Введите строку: ");
    gets(str);
    Node* Root = 0;

    printf("\nСтрока в символьном виде:\n");

    for(int i = 0 ;i < strlen(str);i++)
    {
        printf("%d ", str[i]);
    }

    Root = add(Root, str[0]);

    for (int i = 1; i < strlen(str); i++)
    {
        add(Root, str[i]);
    }

    printf("\n\nДерево в отсортироввнном по возрастанию виде:\n");
    in_orderA(Root);

    printf("\n\nДерево в отсортироввнном по убыванию виде:\n");
    in_orderD(Root);

    FreeTree(Root);
    _getch();
}
