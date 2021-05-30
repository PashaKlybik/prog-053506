/*
 * __  __                 ____
 * \ \/ /_  ___________ _/  _/___
 *  \  / / / / ___/ __ `// //_  /
 *  / / /_/ / /  / /_/ // /  / /_
 * /_/\__,_/_/   \__,_/___/ /___/  https://github.com/YuraIz/
 *
 * Tree header file
 */

#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

 //Tree by YuraIz
typedef struct Tree {
        struct Tree* lChild;
        struct Tree* rChild;
        int data;
} Tree;

//Init tree with data
Tree* treeInit(int data) {
        Tree* output = (Tree*)calloc(1, sizeof(Tree));
        output->data = data;
        return output;
}

//Add data to tree
void treeAdd(Tree* tree, int data) {
        while(1) {
                if(data < tree->data) {
                        if(tree->lChild == NULL) {
                                tree->lChild = treeInit(data);
                                return;
                        } else {
                                tree = tree->lChild;
                        }
                } else if(data > tree->data) {
                        if(tree->rChild == NULL) {
                                tree->rChild = treeInit(data);
                                return;
                        } else {
                                tree = tree->rChild;
                        }
                } else {
                        return;
                }
        }
}

//Returns pointer of tree with current data
Tree* treeFind(Tree* tree, int data) {
        while(tree != NULL) {
                if(tree->data == data) {
                        return tree;
                } else {
                        tree = (data < tree->data)
                                ? tree->lChild
                                : tree->rChild;
                }
        }
        return NULL;
}

//Returns pointer to a copy of current tree
Tree* treeCopy(Tree* tree) {
        if(tree == NULL) {
                return NULL;
        } else {
                Tree* copy = treeInit(tree->data);
                copy->lChild = treeCopy(tree->lChild);
                copy->rChild = treeCopy(tree->lChild);
                return copy;
        }
}

//Like a strcmp(), but for Tree
int treeCompare(Tree* tree1, Tree* tree2) {
        if(tree1 == NULL && tree2 == NULL) {
                return 0;
        } else if(tree1 == NULL) {
                return -1;
        } else if(tree2 == NULL) {
                return 1;
        } else if(tree1->data == tree2->data) {
                int result = treeCompare(tree2->lChild, tree2->lChild);
                if(result == 0) {
                        return treeCompare(tree2->rChild, tree2->rChild);
                } else {
                        return result;
                }
        } else if(tree1->data > tree2->data) {
                return 1;
        } else if(tree1->data < tree2->data) {
                return -1;
        }
}

//free() for each element of Tree
void treeFree(Tree* tree) {
        if(tree->lChild != NULL) {
                treeFree(tree->lChild);
        }
        if(tree->rChild != NULL) {
                treeFree(tree->rChild);
        }
        free(tree);
}


#endif