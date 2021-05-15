/*      __  __                   ____
 *     / / / /_  __,___,____    /  _/____
 *    / /_/ / / / / __ / __ \   / / /_  /
 *    \__, / /_/ / /  / /_/ / _/ /   / /_
 *   /____/\____/_/   \___\_\/___/  /___/  https://github.com/yuraiz/
 *
 *   Queue header
 */

#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct ElementOfQueue {
        struct ElementOfQueue* prev;
        struct ElementOfQueue* next;
        int data;
} ElementOfQueue;

typedef struct Queue {
        struct ElementOfQueue* first;
        struct ElementOfQueue* last;
} Queue;

void init(Queue* queue) {
        queue->first = NULL;
        queue->last = NULL;
}

void enqueue(Queue* queue, int data) {
        ElementOfQueue* el = (ElementOfQueue*)malloc(sizeof(ElementOfQueue));
        el->data = data;
        el->prev = NULL;
        el->next = queue->last;
        queue->last = el;
        if(queue->first == NULL) {
                queue->first = el;
        }
}

int dequeue(Queue* queue) {
#ifdef _STDIO_H
        if(queue->first == NULL) {
                printf("queue is empty\n");
                exit(1);
        }
#endif
        int data = queue->first->data;
        ElementOfQueue* temp = queue->first;
        queue->first = queue->first->prev;
        free(temp);
        queue->first->next = NULL;
        return data;
}

#endif