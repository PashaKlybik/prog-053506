#ifndef CRIMINAL_LIST_H
#define CRIMINAL_LIST_H
#include "doubly_linked_list.h"
#include "criminal.h"

List* criminalList;

void newCriminalScreen() {
    Criminal* criminal = addCriminal();
    criminalList->add(criminalList, criminal);
}

void removeCriminalScreen() {
    char* name = NULL;
    printf("name of criminal to remove:\n");
    scanf("%s", name);
    int* index = ListFindByName(criminalList, name);
    if(index == NULL) {
        return;
    } else {
        criminalList->removeAt(criminalList, *index);
    }
}

void printCriminalScreen() {
    char* name = NULL;
    printf("name of criminal to print:\n");
    scanf("%s", name);
    int* index = ListFindByName(criminalList, name);
    if(index == NULL) {
        printf("Wrong name");
    } else {
        printCriminal(
                (Criminal*) criminalList->
                        elementAt(criminalList, *index));
    }
}

void printNamesScreen() {
    ElementOfList* current = criminalList->_last;
    if(current == NULL) {
        printf("Criminal list is empty\n");
    }
    while(current != NULL) {
        printf("%s\n", (char*) ((Criminal*) current->data)->fullName);
        current = current->_prev;
    }
}
#endif //CRIMINAL_LIST_H
