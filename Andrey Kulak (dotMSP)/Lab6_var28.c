// Task 5.2. Variant 28

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORDAMT 100

struct tnode {
    char* word;
    struct tnode* left;
    struct tnode* right;
};

int k = 0;
int i = 0;
int a[100];

void clearMem(struct tnode* tree) {
    if (tree != NULL) {
        clearMem(tree->left);
        clearMem(tree->right);
        free(tree->word);
        free(tree);
    }
}

struct tnode* newTree(struct tnode* nd, char* c) {
    int cmpCondition;
    if (nd == NULL) {
        nd = (struct tnode*)malloc(sizeof(struct tnode));
        nd->word = _strdup(c);
        nd->left = nd->right = NULL;
    }
    cmpCondition = strcmp(c, nd->word);
    if (cmpCondition < 0)
        nd->left = newTree(nd->left, c);
    else if (cmpCondition > 0)
        nd->right = newTree(nd->right, c);
    return nd;
}

void displayTree(struct tnode* nd, int level) {
    if (nd != NULL) {
        displayTree(nd->right, level + 1);
        for (int i = 0; i <= level; i++) printf("  ");
        printf("%s\n", nd->word);
        displayTree(nd->left, level + 1);
    }
}

void orderChng(struct tnode* nd)
{
    if (nd != NULL)
    {
        printf("%s\n", nd->word);
        orderChng(nd->left);
        orderChng(nd->right);
    }
}

int palindromeCheck(char* s)
{
    int length, i;
    length = strlen(s);
    for (i = 0; i < length / 2; i++)
    {
        if (s[i] != s[length - 1 - i])
            return(0);
    }
    return(1);
}

void palindromeDisplay(struct tnode* nd) {

    if (nd != NULL) {
        palindromeDisplay(nd->left);
        if (palindromeCheck(nd->word))
            printf("%s\n", nd->word);
        palindromeDisplay(nd->right);

    }
}

int main() {
    struct tnode* root;
    char word[MAXWORDAMT];
    root = NULL;
    printf("Enter words(type 'end' last to stop the input):\n");
    do {
        scanf_s("%s", word, MAXWORDAMT);
        if (isalpha(word[0]) && strcmp(word, "end") != 0)
            root = newTree(root, word);
    } while (strcmp(word, "end") != 0);
    printf("\n");
    printf("Binary tree:\n");
    displayTree(root, 0);
    printf("Preorder:\n");
    orderChng(root);
    printf("Palindromes:\n");
    palindromeDisplay(root);
    printf("\n");
    clearMem(root);
    return 0;
}