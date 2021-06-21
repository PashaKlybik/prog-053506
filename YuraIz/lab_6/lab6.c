/* Task 5.2(11)
 * Develop functions for comparing and copying a binary tree.
 */

#include <stdio.h>
#include "tree.h"

int main() {
        Tree* tree = treeInit(50);
        for(int i = 128; i > 0; i /= 2) {
                for(int j = 0; j < 5000; j += i) {
                        //500000
                        treeAdd(tree, j);
                }
        }
        Tree* copy = treeCopy(treeFind(tree, 800));
        if(!treeCompare(treeFind(tree, 800), copy)) {
                printf("The copy is the same as the original\n");
        }
        treeFree(tree);
        treeFree(copy);
}