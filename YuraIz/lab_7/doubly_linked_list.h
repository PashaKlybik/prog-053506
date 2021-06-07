/*      __  __                   ____
 *     / / / /_  __,___,____    /  _/____
 *    / /_/ / / / / __ / __ \   / / /_  /
 *    \__, / /_/ / /  / /_/ / _/ /   / /_
 *   /____/\____/_/   \___\_\/___/  /___/  https://github.com/YuraIz/
 *
 *   Include file for the doubly linked list
 */

#include <stdlib.h>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct ElementOfList {
        struct ElementOfList* prev;
        struct ElementOfList* next;
        int data;
} ElementOfList;

typedef struct List {
        struct ElementOfList* first;
        struct ElementOfList* last;
} List;

void addTo(List* list, int data, int index) {
        ElementOfList* current = list->first;
        while(index > 0) {
                current = current->next;
        }
        ElementOfList* el = (ElementOfList*)malloc(sizeof(ElementOfList));
        el->data = data;
        el->prev = current;
        el->next = current->next;
        current->next = el;
        el->prev->next = current;
}

int getAt(List* list, int data, int index) {
        ElementOfList* current = list->first;
        while(index > 0) {
                current = current->next;
        }
        return current->data;
}

void enqueue(List* list, int data) {
        ElementOfList* el = (ElementOfList*)malloc(sizeof(ElementOfList));
        el->data = data;
        el->prev = NULL;
        el->next = list->last;
        if(list->last != NULL) {
                list->last->prev = el;
        }
        list->last = el;
        if(list->first == NULL) {
                list->first = el;
        }
}

int dequeue(List* list) {
        if(list->first == NULL) {
#ifdef _STDIO_H
                printf("list is empty\n");
#endif
                exit(1);
        }

        int data = list->first->data;
        ElementOfList* temp = list->first;
        list->first = list->first->prev;
        free(temp);
        if(list->first != NULL) {
                list->first->next = NULL;
        } else {
                list->last = NULL;
        }
        return data;
}

#ifdef _STDIO_H
void printQueue(List* list) {
        ElementOfList* current = list->first;
        printf("<");
        while(current != NULL) {
                printf("%d ", current->data);
                current = current->prev;
        }
        printf(" <\n");
}
#endif

#endif //DOUBLY_LINKED_LIST_H