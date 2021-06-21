#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
//Task 5.1 (11)

char** parse(char* input, char sep) {
        int length = 0;
        for(int i = 0; input[i] != '\0'; i++) {
                if(input[i] == sep) {
                        length++;
                }
        }
        char** output = (char**)calloc(length + 2, sizeof(char*));
        output[0] = input;
        output[length + 1] = NULL;
        for(int i = 0, j = 0; input[i] != '\0'; i++) {
                if(input[i] == sep) {
                        j++;
                        output[j] = &input[i + 1];
                }
        }
        return output;
}

void stackProcessing(Stack* first, int n, Queue* queue) {
        char* buff = malloc(128);
        QueueData temp;
        temp.data = 0;
        fgets(buff, 128, stdin);
        char** parsed = parse(buff, ' ');
        for(int i = 0; parsed[i] != NULL; i++) {
                sscanf(parsed[i], "%d%c", &temp.stackNumber, &temp.action);
                if(
                        temp.action == 'A' ||
                        temp.action == 'a'
                        ) {
                        sscanf(parsed[i], "%d%c%ld", &temp.stackNumber, &temp.action, &temp.data);
                }
                enqueue(queue, temp);
        }
        //printQueue(queue);

        free(buff);
        free(parsed);

        while(queue->first != NULL) {
                if(
                        queue->first->data.action == 'A' ||
                        queue->first->data.action == 'a'
                        ) {
                        push(
                                &first[queue->first->data.stackNumber - 1],
                                queue->first->data.data
                        );
                } else if(
                        queue->first->data.action == 'D' ||
                        queue->first->data.action == 'd'
                        ) {
                        if(first[queue->first->data.stackNumber - 1].top != NULL) {
                                pop(first + queue->first->data.stackNumber - 1);
                        }
                }
                dequeue(queue);
        }

        for(int i = 0; i < n; i++) {
                printf("Stack %d: ", i + 1);
                printStack(&first[i]);
        }

}

int main() {
        int n = 3;
        printf("n = ");
        scanf("%d", &n);
        Queue* queue = (Queue*)calloc(1, sizeof(Queue));
        Stack* stacks = (Stack*)calloc(n, sizeof(Stack));
        printf("1a5 - push item five to first stack\n1d pop first stack\n");
        while(1) {
                stackProcessing(stacks, n, queue);
        }

}
