#include <stdlib.h>
#include <stdio.h>

//-------------------------List Working-------------------
struct Spisok {
	int Data;
	Spisok* next;
} *begin, * end;

void init(Spisok** begin, Spisok** end, int Data) {
	Spisok* buffer = (Spisok*)calloc(1, sizeof(Spisok));
	buffer->Data = Data;
	buffer->next = NULL;
	if (*begin == NULL) {
		*begin = *end = buffer;
	}
	else {
		(*end)->next = buffer;
		*end = buffer;
	}
}

void CheckForRepeat(Spisok** begin, Spisok **end, int checking) {
	Spisok* pointer = *begin;
	bool IsRepeat = false;
	if (pointer == NULL) {
		init(begin, end, checking);
		return;
	}
	while (pointer != NULL) {
		if (pointer->Data == checking) IsRepeat = true;
		pointer = pointer->next;
	}
	if (IsRepeat == false) {
		init(begin, end, checking);
		return;
	}
	else {
		printf("This number is already in list...\n");
		system("pause");
	}
}

void View(Spisok** begin) {
	Spisok* pointer = *begin;
	if (pointer == NULL) return;
	while (pointer != NULL) {
		printf("\t %d \t|", pointer->Data);
		pointer = pointer->next;
	}
	printf("\n");
}

void DeleteAll(Spisok** begin) {
	Spisok* buffer;
	while (*begin != NULL) {
		buffer = *begin;
		*begin = (*begin)->next;
		free(buffer);
	}
}
//----------------------------------------------

//-----------------Tree Working-----------------
struct Tree {
	int Id;
	Tree* left, * right;
} *root;

Tree* List(int Id) {
	Tree* buf = (Tree*)calloc(1, sizeof(Tree));
	buf->Id = Id;
	buf->left = buf->right = NULL;
	return buf;
}

void AddToTree(Tree* root, int Id) {
	Tree* prey = root, * pointer = root;
	while (pointer != NULL) {
		prey = pointer;
		if (Id < pointer->Id) pointer = pointer->left;
		else pointer = pointer->right;
	}
	pointer = List(Id);
	if (Id < prey->Id) prey->left = pointer;
	else prey->right = pointer;
}

void Tree_View(Tree* tree, int level) {
	if (tree) {
		printf("[%d level] %d\n", level, tree->Id);
		Tree_View(tree->left, level + 1);
		Tree_View(tree->right, level + 1);
	}
}

void DeleteTree(Tree* root) {
	if (root == NULL) return;
	else if (root != NULL) {
		DeleteTree(root->left);
		DeleteTree(root->right);
		delete root;
	}
}

void DeleteLeftNodesNegativeDataFromTree(Tree*root, int massive[], int i) {
	Tree* Delete = root;
	while (Delete != NULL && Delete->Id > 0) {
		if (Delete->Id > 0) Delete = Delete->left;
	}
	if (Delete == NULL) return;
	if (Delete->left != NULL) {
		DeleteTree(Delete->left);
		for (int j = 0; j <= i; ++j) {
			if (massive[j] < Delete->Id) massive[j] = 0;
		}
	}
	DeleteLeftNodesNegativeDataFromTree(Delete->right, massive, i);
} 

Tree* DeletePartTree(Tree* root, int Id) {
	Tree* Delete = root, * PreyForDelete = root, * Reverse, * PreyForReverse;
	while (Delete != NULL && Delete->Id != Id) {
		PreyForDelete = Delete;
		if (Delete->Id > Id) Delete = Delete->left;
		else if (Delete->Id < Id) Delete = Delete->right;
		else if (Delete == NULL) {
			system("pause");
			return root;
		}
	}
	if (Delete->left == NULL && Delete->right == NULL) {
		if (PreyForDelete->left == Delete) PreyForDelete->left = NULL;
		else if (PreyForDelete->right == Delete) PreyForDelete->right = NULL;
		delete Delete;
		return root;
	}
	else if (Delete->left == NULL) Reverse = Delete->right;
	else if (Delete->right == NULL) Reverse = Delete->left;
	else {
		PreyForReverse = Delete;
		Reverse = Delete->left;
		while (Reverse->right != NULL) {
			PreyForReverse = Reverse;
			Reverse = Reverse->right;
		}
		if (PreyForReverse == Delete) Reverse->right = Delete->right;
		else {
			Reverse->right = Delete->right;
			PreyForReverse->right = Reverse->left;
			Reverse->left = Delete->left;
		}
	}
	if (Delete == root) root = Reverse;
	else if (Delete->Id < PreyForDelete->Id) PreyForDelete->left = Reverse;
	else PreyForDelete->right = Reverse;
	delete Delete;
	return root;
}

//Модуль списка в дереве
void TransferDataFromListToTree(Spisok** begin, Tree** root) {
	DeleteTree(*root);
	Spisok* pointer = *begin;
	if (pointer == NULL) return;
	while (pointer != NULL) {
		if (*root == NULL) *root = List(pointer->Data);
		else AddToTree(*root, pointer->Data);
		pointer = pointer->next;
	}
}
//----------------------

//----------------------------------------------

int main() {
	int menu = 0;
	while (menu != 9) {
		printf("[0] -> List\n[1] -> Tree\n[9] -> Exit\n\nYour Choice: ");
		scanf_s("%d", &menu);
		switch (menu)
		{
			case 0: {
				while (menu != 9) {
					system("cls");
					printf("[0] -> Add to List\n[1] -> View List\n[2] -> Clear List\n[9] -> Back to Main Menu\n\nYour Choice: ");
					scanf_s("%d", &menu);
					switch (menu)
					{
						case 0: {
							system("cls");
							int buflist;
							printf("Input integer in list: "); scanf_s("%d", &buflist);
							CheckForRepeat(&begin, &end, buflist);
							break;
						}
						case 1: {
							system("cls");
							View(&begin);
							system("pause");
							break;
						}
						case 2: {
							DeleteAll(&begin);
							break;
						}
						default: system("cls");
						break;
					}
				}
				menu = 0;
				break;
			}
			case 1: {
				while (menu != 9) {
					system("cls");
					printf("[0] -> Form Tree\n[1] -> View Tree\n[2] -> Delete All Tree\n[3] -> Delete All Negative Nodes\n[9] -> Back to Main Menu\n\nYour Choice: ");
					scanf_s("%d", &menu);
					switch (menu)
					{
						case 0: {
							TransferDataFromListToTree(&begin, &root);
							break;
						}
						case 1: {
							system("cls");
							Tree_View(root, 0);
							system("pause");
							break;
						}
						case 2: {
							DeleteTree(root);
							break;
						}
						case 3: {
							Spisok* pointer = begin;
							int i = 0;
							int massive[255];
							while (pointer != NULL) {
								if (pointer->Data < 0) { massive[i] = pointer->Data; i++; }
								pointer = pointer->next;
							}
							for (int j = 0; j < i; ++j) {
								DeletePartTree(root, massive[j]);
							}
							break;
						}
						default: system("cls");
							break;
					}
				}
				menu = 1;
				break;
			}
			default:
				break;
		}
	}
}