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

typedef struct ElementOfList ElementOfList;
struct ElementOfList {
    void* data;
    ElementOfList* _prev;
    ElementOfList* _next;
};

typedef struct List List;

struct List {
    ElementOfList* _first;
    ElementOfList* _last;

    //Functions
    void (* add)(List*, void* data);

    __attribute__((unused)) void (* addAt)(List*, void* data, int index);

    void (* removeAt)(List*, int index);

    void* (* elementAt)(List*, int index);
};

void* listElementAt(List* list, int index) {
    ElementOfList* current = list->_first;
    while(index-- > 0 && current != NULL) {
        current = current->_next;
    }
    if(current == NULL) {
        return NULL;
    } else {
        return current->data;
    }
}

void listAdd(List* list, void* data) {
    ElementOfList* element = (ElementOfList*) malloc(sizeof(ElementOfList));
    element->data = data;
    element->_next = NULL;
    element->_prev = list->_last;
    if(list->_last != NULL) {
        list->_last->_next = element;
    }
    list->_last = element;
    if(list->_first == NULL) {
        list->_first = list->_last->_prev;
    }
}

void listAddAt(List* list, void* data, int index) {
    ElementOfList* current = list->_first;
    while(index > 0 && current != NULL) {
        current = current->_next;
        index--;
    }
    ElementOfList* el = (ElementOfList*) malloc(sizeof(ElementOfList));
    el->data = data;
    el->_prev = current;
    if(current != NULL) {
        el->_next = current->_next;
        current->_next = el;
        el->_prev->_next = current;
    } else {
        el->_next = NULL;
    }
}

void listRemoveAt(List* list, int index) {
    ElementOfList* current = list->_first;
    while(index-- > 0 && current != NULL) {
        current = current->_next;
    }
    if(current != NULL) {
        current->_prev->_next = current->_next;
        current->_next->_prev = current->_prev;
        free(current);
    }
}

List* initList() {
    List* ptr = (List*) malloc(sizeof(List));
    ptr->_first = NULL;
    ptr->_last = NULL;
    ptr->add = listAdd;
    ptr->elementAt = listElementAt;
    ptr->addAt = listAddAt;
    ptr->removeAt = listRemoveAt;
    return ptr;
}

__attribute__((unused)) void freeList(List* list) {
    ElementOfList* current = list->_first;
    while(current != NULL) {
        current = current->_next;
        free(current->_prev);
    }
    free(list);
}

#include <string.h>
int* ListFindByName(List* list, char* name) {
    ElementOfList* current = list->_first;
    int* i = (int*) calloc(1, sizeof(int));
    while(current != NULL && !strcmp((char*) current, name)) *i++;
    return (current == NULL) ? NULL : i;
}

int* ListFindById(List* list, unsigned int id) {
    ElementOfList* current = list->_first;
    int* i = (int*) calloc(1, sizeof(int));
    while(current != NULL && *((unsigned int*)current) != id) *i++;
    return (current == NULL) ? NULL : i;
}

#endif //DOUBLY_LINKED_LIST_H