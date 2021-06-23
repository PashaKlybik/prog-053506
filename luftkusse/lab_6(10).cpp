#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int k = 0;
int i = 0;
int a[100];

struct Tnode {                
    char* word;                 
    struct Tnode* left;          
    struct Tnode* right;         
};

struct Tnode* addtree(struct Tnode* p, char* w) {
    int cond;
    
    if (p == NULL) {
        p = (struct Tnode*)malloc(sizeof(struct Tnode));
        p->word = _strdup(w);
        p->left = p->right = NULL;
    }
    cond = strcmp(w, p->word);
    if (cond < 0)
        p->left = addtree(p->left, w);
    else if(cond > 0)
        p->right = addtree(p->right, w);
    return p;
}

void freememory(struct Tnode* tree) {
    if (tree != NULL) {
        freememory(tree->left);
        freememory(tree->right);
        free(tree->word);
        free(tree);
    }
}

void treeprint(struct Tnode* p,int level) {
    
    if (p != NULL) {
        treeprint(p->right, level + 1);
        for (int i = 0; i <= level; i++) printf("  ");
        printf("%s\n", p->word);
        treeprint(p->left, level + 1);
        
     }
}

void preorder(struct Tnode* p)
{
    if(p != NULL)
    {
        printf("%s\n", p->word);
        preorder(p->left);
        preorder(p->right);
    }
}

int palindrom(char *s)
{
    int l, i;
    l = strlen(s);
    for (i = 0; i < l / 2; i++)
    {
        if (s[i] != s[l - 1 - i])
            return(0);
    }
    return(1);
}

void treePalindromeprint(struct Tnode* p) {

    if (p != NULL) {
        treePalindromeprint(p->left);
        if(palindrom(p->word))
        printf("%s\n", p->word);
        treePalindromeprint(p->right);
        
    }
}

int main() {
	system("chcp 1251");
    struct Tnode* root;
    char word[MAX];
    root = NULL;
    printf("Введите 'end' для выхода.\n");
    do {
        scanf_s("%s", word, MAX);
        if (isalpha(word[0]) && strcmp(word, "end") != 0)
            root = addtree(root, word);
    } while (strcmp(word,"end")!=0);   
    
    printf("\n");
    printf("Бинарное дерево: \n");
    treeprint(root,0);
    printf("\n");
    printf("Предзаказ: \n");
    preorder(root);
    printf("Все палиндромы в алфавитном порядке: \n");
    treePalindromeprint(root);
    printf("\n");
    freememory(root);
    return 0;
}