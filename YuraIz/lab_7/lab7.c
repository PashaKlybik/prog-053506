//Task 6.2(27)

#include <stdio.h>
#include "doubly_linked_list.h"

int main() {
        List* list = listInit(INT);
        for(int i = 0; i < 10; i++) {
                int* ptr = malloc(4);
                *ptr = i;
                listAdd(list, ptr);
        }
        printf("\n");
}
