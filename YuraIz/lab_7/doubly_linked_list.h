// YuraIz realization of doubly linked list

#include <stdlib.h>

typedef
struct ElementOfList {
        struct ElementOfList* prev;
        struct ElementOfList* next;
        void* data;
} ElementOfList;

enum Type {
        INT,
        CHAR,
        STRING,
};

typedef struct List {
        ElementOfList* first;
        ElementOfList* last;
        enum Type type;
} List;

List* listInit(enum Type type) {
        List* list = (List*)calloc(1, sizeof(List));
        list->type = type;
        return list;
}

void listAdd(List* list, void* data) {
        list->last->next = (ElementOfList*)calloc(1, sizeof(ElementOfList));
        list->last->next->prev = list->last;
        list->last = list->last->next;
        list->last->data = data;
        if(list->first == NULL) {
                list->first = list->last;
        }
}

void* listGet(List* list, int index) {
        ElementOfList* current = list->first;
        while(index > 0) {
                current = current->next;
        }
        return current->data;
}

