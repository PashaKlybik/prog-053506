#include "stdio.h"
#include "stdlib.h"
#include "windows.h"

int tabs = 0;


typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
}
TreeNode;


void AddNode(int data, TreeNode **node)
{
    if (*node == NULL)
    {
        *node = (TreeNode*)calloc(1, sizeof(TreeNode));
        (*node)->data = data;
        (*node)->left = (*node)->right = NULL;
    }
    else
    {
        if (data > (*node)->data)
            AddNode(data, &(*node)->left);
        else if (data < (*node)->data)
            AddNode(data, &(*node)->right);
        else printf("Элемент %d уже существует\n", (*node)->data);

    }

}

void ViewTree(TreeNode *node)
{
    if (node == NULL)
        return;

    tabs += 5;

    ViewTree(node->left);
    for (int i = 0; i < tabs; i++) printf(" ");
    printf("%d\n", node->data);
    ViewTree(node->right);
    tabs -= 5;
}

void clearMemory(TreeNode *node)
{
    if (node != NULL)
    {
        clearMemory(node->left);
        clearMemory(node->right);
        free(node->data);
        free(node);
    }
}

int TreeHeight(TreeNode* node)
{
    if (node == 0)
        return 0;
    int left, right;

    if (node->left != NULL)
        left = TreeHeight(node->left);
    else
        left = -1;

    if (node->right != NULL)
        right = TreeHeight(node->right);
    else
        right = -1;

    int max = left > right ? left : right;
    return max + 1;

}

int heightNode(TreeNode* root, int h)
{
    if (root == NULL)
        return 0;
    if (h == 0)
        return 1;

    return heightNode(root->left, h - 1) + heightNode(root->right, h - 1);
}

void numNodes(TreeNode* root)
{
    int k = TreeHeight(root);
    for (int i = 0; i < k + 1; i++)
        printf("Элементов на уровне %d: %d\n", i, heightNode(root, i));
}

void sort(int* arr, int k)
{
    int tmp;
    for(int i=0;i<k;i++)
        for(int j=i+1;j<k;j++)
            if(arr[j] < arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
}

void balance(int* arr, int start, int end, TreeNode **root)
{
    int mid = (start + end) / 2;
    AddNode(arr[mid], &(*root));
    if (mid > start)
        balance(arr, start, mid - 1, &(*root)->right);
    if (mid < end)
        balance(arr, mid + 1, end, &(*root)->left);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int mas[100];
    char buffer[128];
    TreeNode *root = NULL;

    FILE *fp = fopen("input.txt", "r");
    int k = 0;

    if (!fp)
        exit(1);

    while (!feof(fp))
    {
        if (fgets(buffer, 128, fp))
            if (atoi(buffer) != 0)
            {
                mas[k] = atoi(buffer);
                k++;
            }
    }
    sort(mas, k);
    balance(mas, 0, k - 1, &root);
    printf("Полученное дерево:\n");
    ViewTree(root);
    numNodes(root);
    fclose(fp);
    clearMemory(root);
    return 0;
}