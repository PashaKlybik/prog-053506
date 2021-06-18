//#5.2(25)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Node
{
    struct Node* left;
    struct Node* middle;
    struct Node* right;
    int data;
};

struct Node* createNode(int data)
{
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->middle = NULL;
    tmp->right = NULL;
    return tmp;
}

struct Node* insert(struct Node* root, int data)
{
    if (!root)
        root = createNode(data);
    else if (root->data > data)
        root->left = insert(root->left, data);
    else if (root->data < data)
        root->right = insert(root->right, data);
    else if (root->data == data)
        root->middle = insert(root->middle, data);
    return root;
}

int numberLevels(struct Node* root);
int count(int x, int y, int z);
int main()
{
    struct Node* root = NULL;
    int x, n;
    printf("Set the number of nodes: "); scanf("%d", &n);
    printf("Random elements: ");
    for (int i = 0; i < n; i++) {
        x = rand() % 100 + 1;
        insert(&root, x);
        printf("%d ", x);
    }
    printf("\nThe number of levels in the tree is %d", numberLevels(root));
    return 0;
}
int numberLevels(struct Node* root) {
    if (!root)
        return 0;
    int left = numberLevels(root->left);
    int middle = numberLevels(root->middle);
    int right = numberLevels(root->right);
    return count(left, middle, right) + 1;
}
int count(int x, int y, int z)
{
    if (x >= y && x >= z)
        return x;
    else if (y >= x && y >= z)
        return y;
    else
        return z;
}