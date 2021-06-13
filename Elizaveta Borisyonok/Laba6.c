////5.2(1)

#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct Node
{
	int count;
	struct Node* left;
	struct Node* right;
	struct Node* pNext;
	struct Node* pPrev;
} Node;

typedef struct line
{
	int size;
	Node* head;
	Node* top;
} Line;

void pushLine(Line* line, Node* object)
{
	Node* num = line->head;
	if (num == NULL)
	{
		line->head = object;
		line->top = object;
	}
	else
	{
		line->top->pNext = object;
		object->pPrev = line->top;
		line->top = object;
	}
	line->size++;
}

void printLine(Line* line)
{
	Node* num = line->head;
	while (num->pNext) {
		printf("%d\n", num->count);
		num = num->pNext;
	}
	printf("%d\n", num->count);
}

Node* search(Node* nod, int i)
{

	if (nod->count == i)
	{
		return nod;
	}

	if (nod->count > i)
	{
		if (nod->left)
		{
			return search(nod->left, i);
		}
		else
		{
			return NULL;
		}
	}

	if (nod->count  < i)
	{
		if (nod->right)
		{
			return search(nod->right, i);
		}
		else
		{
			return NULL;
		}
	}
}


int defineNode(Node* p)
{
	if (p->left || p->right)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void add(Node* nod, int num)
{
	Node* cheak = search(nod, num);
	if (cheak == NULL) {
		if (nod->count> num)
		{
			if (nod->left)
			{
				add(nod->left, num);
			}
			else
			{
				Node* p = (Node*)malloc(sizeof(Node));
				p->left = NULL;
				p->right = NULL;
				p->count = num;
				nod->left = p;
			}
		}
		else
		{
			if (nod->right)
			{
				add(nod->right, num);
			}
			else {
				Node* p = (Node*)malloc(sizeof(Node));
				p->left = NULL;
				p->right = NULL;
				p->count = num;
				nod->right = p;
			}
		}
	}

}

void Review(Node* nod)
{
	printf("%d\n", nod->count);

	if (nod->left) {
		Review(nod->left);
	}

	if (nod->right) {
		Review(nod->right);
	}
}

void Remove(Node* root, int index) {

	int def;
	Node* currant;
	Node* pred = root;
	currant = search(root, index);
	if (currant != NULL && currant != root)
	{
		pred = searchPrev(root, index, pred);
		def = defineNode(currant);
		Node* currantMaxElementInSubTree;
		Node* predtMaxElementInSubTree;

		if (def == 0)
		{
			removeList(currant, pred);
			free(currant);
		}
		else if (def == 1) {
			if (currant->left_child != NULL) {
				currantMaxElementInSubTree = findMax(currant->left_child);
			}
			else {
				currantMaxElementInSubTree = findMin(currant->right_child);
			}
			predtMaxElementInSubTree = currantMaxElementInSubTree;
			predtMaxElementInSubTree = searchPrev(root, currantMaxElementInSubTree->num, predtMaxElementInSubTree);
			if (currant != predtMaxElementInSubTree) {
				if (pred->left_child == currant) {
					pred->left_child = currantMaxElementInSubTree;
				}
				else if (pred->right_child == currant) {
					pred->right_child = currantMaxElementInSubTree;
				}

				if (currant->left_child) {
					predtMaxElementInSubTree->right_child = currantMaxElementInSubTree->left_child;
					currantMaxElementInSubTree->left_child = currant->left_child;
					currantMaxElementInSubTree->right_child = currant->right_child;
				}
				else {
					currantMaxElementInSubTree->right_child = currant->right_child;
					predtMaxElementInSubTree->left_child = NULL;
				}

			}
			else {
				if (pred->left_child == currant) {
					pred->left_child = currantMaxElementInSubTree;
				}
				else if (pred->right_child == currant) {
					pred->right_child = currantMaxElementInSubTree;
				}
				if (currant->left_child)
				{
					currantMaxElementInSubTree->right_child = currant->right_child;
				}
			}
			free(currant);
		}
	}
}


void Comb(Node* root1, Node* root2)
{
	Node* buf;
	buf = search(root1, root2->count);
	if (buf == NULL)
	{
		add(root1, root2->count);
	}
	if (root2->left)
	{
		Comb(root1, root2->left);
	}

	if (root2->right)
	{
		Comb(root1, root2->right);
	}
}



int main()
{
	Node root = { 1, NULL,NULL };
	add(&root, 23);
	add(&root, 34);
	add(&root, 45);
	add(&root, 56);
	add(&root, 62);
	add(&root, 74);
	add(&root, 84);
	add(&root, 9);
	add(&root, 10);
	add(&root, 11);
	add(&root, 12);
	add(&root, 13);
	add(&root, 154);
	add(&root, 15);

	Node root2 = { 10,NULL,NULL };
	add(&root2, 9);
	add(&root2, 84);
	add(&root2, 7);
	add(&root2, 6);
	add(&root2, 53);
	add(&root2, 4);
	add(&root2, 35);
	add(&root2, 2);
	add(&root2, 1);

	Line line = { NULL,NULL,0 };
	printf("Tree 1:\n------\n");
	Review(&root);

	printf("------\nTree 2:\n------\n");
	Review(&root2);

	printf("------\nGeneral Tree:\n------\n");
	Comb(&root, &root2);
	Review(&root);
}
