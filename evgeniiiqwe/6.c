#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree
{
	struct tree*left,
		*right;
	char value[100];
} Tree;

void AddList(Tree** root, char* word)
{
	Tree * new_node = (Tree*)calloc(1, sizeof(Tree));
	strcpy(new_node->value, word);
	new_node->left = NULL;
	new_node->right = NULL;
	if ((*root) != NULL)
	{
		if (strcmp((*root)->value, new_node->value) > 0)
		{
			AddList(&(*root)->left, word);
		}
		else if (strcmp((*root)->value, new_node->value) < 0)
		{
			AddList(&(*root)->right, word);
		}
	}
	else
	{
		(*root) = new_node;
	}
}

void preorder(Tree* p) {
	if (p != NULL) {
        preorder(p->left);
        printf("%s\n", p->value);
        preorder(p->right);
	}
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	Tree* root = NULL;
	char* line;
	printf("Привет! Введи пожалуйста предложение (не больше 500 символов)\n");
	fgets(line, 500, stdin);

	printf("Конвертация предложения в бинарное дерево...\n");
	for (char *ptr = strtok(line, " ,!?"); ptr != NULL; ptr = strtok(NULL, " ,!?"))
		AddList(&root, ptr);

    printf("Итог:\n");
	preorder(root);

	return 0;
}
