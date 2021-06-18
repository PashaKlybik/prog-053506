#pragma once

typedef struct Tree
{
	char* data;
	struct Tree* left;
	struct Tree* right;
} Tree;

char* NewText(Tree* head, char s, size_t m)
{
	size_t text_size = 2;
	if (head->data != NULL)
		text_size += strlen(head->data);
	char* res = malloc(text_size * sizeof(char));
	res[text_size - 1] = '\0';
	res[text_size - 2] = s;
	int pos = text_size - 3;
	while (pos >= 0)
	{
		if (head->data != NULL)
		{
			for (int i = strlen(head->data) - 1; i >= 0 && pos >= 0; i--)
			{
				res[pos--] = head->data[i];
			}
		}
		if (pos < 0)
			break;
		res[pos--] = '0';
	}
	return res;
}

void ChangeBranch(Tree** head, char s, size_t m)
{
	if (s == '\n')
		return;
	if (s == '0')
	{
		if ((*head)->left == NULL) {
			(*head)->left = malloc(sizeof(Tree));
			(*head)->left->data = NewText(*head, s, m);
			(*head)->left->left = NULL;
			(*head)->left->right = NULL;
		}
		*head = (*head)->left;
	}
	else
	{
		if ((*head)->right == NULL) {
			(*head)->right = malloc(sizeof(Tree));
			(*head)->right->data = NewText(*head, s, m);
			(*head)->right->left = NULL;
			(*head)->right->right = NULL;
		}
		*head = (*head)->right;
	}
}
void NewBranch(Tree* head, char* data, size_t m)
{
	Tree* currentNode = head;
	for (int i = 0; i < strlen(data); i++)
	{
		ChangeBranch(&currentNode, data[i], m);
	}
}
void PreOrder(Tree* head)
{
	if (head == NULL)
		return;
	if (head->data == NULL)
		printf("Start\n");
	else
		printf("%s\n", head->data);
	PreOrder(head->left);
	PreOrder(head->right);
}
void InOrder(Tree* head)
{
	if (head == NULL)
		return;
	InOrder(head->left);
	if (head->data == NULL)
		printf("Start\n");
	else
		printf("%s\n", head->data);
	InOrder(head->right);
}
void PostOrder(Tree* head)
{
	if (head == NULL)
		return;
	PostOrder(head->left);
	PostOrder(head->right);
	if (head->data == NULL)
		printf("Start\n");
	else
		printf("%s\n", head->data);
}
void deleteTree(Tree* head)
{
	if (head == NULL)
		return;
	if (head->left != NULL)
		deleteTree(head->left);
	if (head->right != NULL)
		deleteTree(head->right);
	free(head->data);
	free(head);
}