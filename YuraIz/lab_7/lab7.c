//Task 6.2(27)

#include <stdio.h>
#include "doubly_linked_list.h"

int main() {
        List* list = (List*)calloc(1, sizeof(List));
        for(int i = 0; i < 10; i++) {
                enqueue(list, i);
        }
        printQueue(list);
        printf("\n");
}
