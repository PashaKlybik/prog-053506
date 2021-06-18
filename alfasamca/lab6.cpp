#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define SIZE 256 
struct TNode
{
    char inf;
    struct TNode* Left;
    struct TNode* Right;
};

void PreOrder(struct TNode* root)
{
    if (root)
    {
        printf("%c", root->inf);
        PreOrder(root->Left);
        PreOrder(root->Right);
    }
}

void InOrder(struct TNode* root)
{
    if (root)
    {
        InOrder(root->Left);
        printf("%c", root->inf);
        InOrder(root->Right);
    }
}

void PostOrder(struct TNode* root)
{
    if (root)
    {
        PostOrder(root->Left);
        PostOrder(root->Right);
        printf("%c", root->inf);
    }
}

struct TNode* Add(char ch, struct TNode* root)
{
    if (root == NULL)
    {
        root = (TNode*)malloc(sizeof(TNode));
        root->inf = ch;
        root->Left = NULL;
        root->Right = NULL;
    }

    else if (ch < root->inf)
    {
        root->Left = Add(ch, root->Left);
    }

    else
    {
        root->Right = Add(ch, root->Right);
    }
    return root;
}

int Counter(struct TNode* root)
{
    if (!root)
    {
        return 0;
    }
    return root->Left == NULL && root->Right == NULL ? 1 : Counter(root->Left) + Counter(root->Right);
}

int main()
{
    int i = 0;
    char str[SIZE];
    printf("Enter your string:\n");
    gets_s(str);
    struct TNode* root = (TNode*)malloc(sizeof(TNode));
    root->Left = NULL;
    root->Right = NULL;
    root->inf = str[0];
    for (int i = 1; i < strlen(str); i++)
    {
        Add(str[i], root);
    }
    printf("Binary tree with inorder: ");
    InOrder(root);
    printf("\n");
    printf("Binary tree with preorder: ");
    PreOrder(root);
    printf("\n");
    printf("Binary tree with postorder: ");
    PostOrder(root);
    printf("\n");
    printf("Number of leaf: %d", Counter(root));
    return 0;
}
