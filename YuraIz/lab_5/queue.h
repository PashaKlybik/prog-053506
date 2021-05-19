/*      __  __                   ____
 *     / / / /_  __,___,____    /  _/____
 *    / /_/ / / / / __ / __ \   / / /_  /
 *    \__, / /_/ / /  / /_/ / _/ /   / /_
 *   /____/\____/_/   \___\_\/___/  /___/  https://github.com/YuraIz/
 *
 *   Include file for the queue
 */

#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueData {
        int stackNumber;
        char action; // 'A' - adding, 'D' -deleting
        long data;
} QueueData;

typedef struct ElementOfQueue {
        struct ElementOfQueue* prev;
        struct ElementOfQueue* next;
        QueueData data;
} ElementOfQueue;

typedef struct Queue {
        struct ElementOfQueue* first;
        struct ElementOfQueue* last;
} Queue;

void enqueue(Queue* queue, QueueData data) {
        ElementOfQueue* el = (ElementOfQueue*)malloc(sizeof(ElementOfQueue));
        el->data = data;
        el->prev = NULL;
        el->next = queue->last;
        if(queue->last != NULL) {
                queue->last->prev = el;
        }
        queue->last = el;
        if(queue->first == NULL) {
                queue->first = el;
        }
}

QueueData dequeue(Queue* queue) {
        if(queue->first == NULL) {
#ifdef _STDIO_H
                printf("queue is empty\n");
#endif
                exit(1);
        }

        QueueData data = queue->first->data;
        ElementOfQueue* temp = queue->first;
        queue->first = queue->first->prev;
        free(temp);
        if(queue->first != NULL) {
                queue->first->next = NULL;
        }
        return data;
}

#ifdef _STDIO_H
void printQueue(Queue* queue) {
        ElementOfQueue* current = queue->last;
        printf(">");
        while(current != NULL) {
                printf(" %ld", current->data.data);
                current = current->next;
        }
        printf(" >\n");
}
#endif

#endif