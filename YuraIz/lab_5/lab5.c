#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
//Task 5.1 (11)

void stackProcessing(Stack* stacks, int n, Queue* queue) {
        char* buff = malloc(64);
        QueueData temp;
        while(scanf("%d%c%ld", &temp.stackNumber, &temp.action, &temp.data)) {
                enqueue(queue, temp);
        }

}

int main() {
        Queue* queue = (Queue*)calloc(1, sizeof(Queue));

}
