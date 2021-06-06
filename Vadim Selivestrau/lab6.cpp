#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

//Структура, описывающая узел дерева
struct node
{
    char word[100];
    struct node* pleft;
    struct node* pright;
};

void treeremove(node* root);
struct node* Add(struct node* root, char* word);
int Check_Word(char* word);
void Find(struct node** Tree_1, struct node** Tree_2);
void Print_Tree(struct node* tree);

int main()
{
    struct node* root = NULL;
    char word[100];
    FILE* file;
    if (fopen_s(&file, "D:\\2sem\\C\\lab6\\test.txt", "r"))
    {
        printf("\nfile not found");
        char c = getchar();
        exit(-1);
    }
    while (fgets(word, 20, file))
    {
        root = Add(root, word);
    }
    fclose(file);
    struct node* Sorted_words = NULL;
    Find(&root, &Sorted_words);
    printf("Words begin and end with the same letter:\n\n");
    Print_Tree(Sorted_words);
    treeremove(root);
    return 0;
}

//Добавить узел в бинарное дерево поиска
struct node* Add(struct node* root, char* word)
{
    int temp;
    if (!root)
    {
        if (!(root = (struct node*)malloc(sizeof(struct node))))
        {
            printf("Error with memory allocation");
        }
        else {
            root->pleft = root->pright = NULL;
            strcpy_s(root->word, word);
        }
    }
    else if ((temp = strcmp(word, root->word)) < 0)
    {
        root->pleft = Add(root->pleft, word);
    }
    else
    {
        root->pright = Add(root->pright, word);
    }
    return root;
}

//функция для проверки слов начинающихся и оканчивающихся одной буквой
int Check_Word(char* word)
{
    char first = word[0];
    char last;
    int i;
    for (i = 0; word[i]; i++);
    last = word[i - 2];
    if (last == first) return 1;
    else return 0;
}

//функция для нахождения слов начинающихся и оканчивающихся одной буквой
void Find(struct node** Tree_1, struct node** Tree_2)
{
    if ((*Tree_1) != NULL)
    {
        Find(&(*Tree_1)->pleft, &(*Tree_2));
        if (Check_Word((*Tree_1)->word)) {
            (*Tree_2) = Add((*Tree_2), (*Tree_1)->word);
        }
        Find(&(*Tree_1)->pright, &(*Tree_2));
    }
}

//Обход дерева слева (вывод по алфавиту))
void Print_Tree(struct node* tree)
{
    if (tree->pleft)
    {
        Print_Tree(tree->pleft);
    }
    printf("%s\n", tree->word);
    if (tree->pright)
    {
        Print_Tree(tree->pright);
    }
}

// удаляет дерево
void treeremove(node* root)
{
    if (root != NULL)
    {
        treeremove(root->pleft);
        treeremove(root->pright);
        free(root);
    }
}
