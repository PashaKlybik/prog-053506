#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

struct Tree {
	int digit;
	struct Tree* left;
	struct Tree* right;
	struct Tree* parent;
};

struct Tree* root = NULL;

struct Tree* AddNode(int x, struct Tree* node, struct Tree* parent) {
	if (node == NULL) {
		node = (struct Tree*)malloc(sizeof(struct Tree));
		node->digit = x;
		node->left = NULL;
		node->right = NULL;
		node->parent = parent;
	}
	else {
		if (node->digit > x) {
			node->left = AddNode(x, node->left, node);
		}
		else {
			node->right = AddNode(x, node->right, node);
		}
	}
	return node;
}

void DeleteTree(struct Tree* node) {
	if (node != NULL) {
		DeleteTree(node->left);
		DeleteTree(node->right);
		free(node);
	}
}

struct Tree* FindMaxNode(struct Tree* node) {
	while (node->right) {
		node = node->right;
	}
	return node;
}

void Dedublicate(struct Tree* order_node, struct Tree* node_for_check) {
	if (order_node == NULL && node_for_check == NULL) {
		return;
	}
	if (node_for_check->left != 0) {
		Dedublicate(order_node, node_for_check->left);
	}
	if (node_for_check->right != 0) {
		Dedublicate(order_node, node_for_check->right);
	}
	if (order_node->digit == node_for_check->digit && order_node != node_for_check) {

		printf("Найден дубликат %d\n", node_for_check->digit);

		if (node_for_check->left && node_for_check->right) {
			Tree* Max = FindMaxNode(node_for_check->left);
			node_for_check->digit = Max->digit;
			Dedublicate(order_node, Max);
			return;
		}
		else if (node_for_check->left) {
			if (node_for_check == node_for_check->parent->left) {
				node_for_check->parent->left = node_for_check->left;
			}
			else {
				node_for_check->parent->right = node_for_check->left;
			}
		}
		else if (node_for_check->right) {
			if (node_for_check == node_for_check->parent->right) {
				node_for_check->parent->right = node_for_check->right;
			}
			else {
				node_for_check->parent->left = node_for_check->right;
			}
		}
		else {
			if (node_for_check == node_for_check->parent->left) {
				node_for_check->parent->left = NULL;
			}
			else {
				node_for_check->parent->right = NULL;
			}
		}
		free(node_for_check);
	}
}

void CheckTree(struct Tree* node) {
	if (node == NULL) {
		return;
	}
	if (node->left != 0) {
		CheckTree(node->left);
	}
	if (node->right != 0) {
		CheckTree(node->right);
	}
	Dedublicate(node, root);
}

void PrintTree(struct Tree* print, int level) {
	if (print) {
		if (print->right) {
			PrintTree(print->right, level + 1);
		}
		for (int i = 0; i < level; i++) {
			printf_s("   ");
		}
		printf_s("%d\n", print->digit);
		if (print->left) {
			PrintTree(print->left, level + 1);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");

	int number = 0, count = 0;

	printf_s("Fill the tree with numbers\n After entering the number, press enter\n Enter 0 to complete the entry\n");
	for (;;)
	{
		scanf_s("%d", &number);
		if (number == 0)
		{
			break;
		}
		else {
			root = AddNode(number, root, root);
			count++;
		}
	}
	PrintTree(root, count);
	CheckTree(root);
	PrintTree(root, count);
	DeleteTree(root);
	return 0;
}