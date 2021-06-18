#ifndef CRIME_LIST_H
#define CRIME_LIST_H

#include "doubly_linked_list.h"
#include "crime.h"

List* crimeList;


void newCrimeScreen() {
    Crime* crime = addCrime();
    crimeList->add(criminalList, crime);
}

void removeCrimeScreen() {
    unsigned int id = 0;
    printf("id of crime to remove:\n");
    scanf("%ud", &id);
    int* index = ListFindById(criminalList, id);
    if(index == NULL) return;
    char* criminalName = ((Crime*) crimeList->elementAt(crimeList, *index))->participant;
    int* index2 = ListFindByName(crimeList, criminalName);
    if(index2 != NULL) {
        Criminal* participant = criminalList->elementAt(criminalList, *index2);
        int* index3 = ListFindById(participant->linksToTheListOfCrimes, id);
        if(index3 != NULL) {
            participant->linksToTheListOfCrimes->removeAt(participant->linksToTheListOfCrimes, *index3);
        }
    }
    criminalList->removeAt(criminalList, *index);
}

void printCrimeScreen() {
    unsigned int id = 0;
    printf("id of crime to print:\n");
    scanf("%ud", &id);
    int* index = ListFindById(criminalList, id);
    if(index == NULL) {
        printf("Wrong id");
    } else {
        printCrime(crimeList->elementAt(crimeList, *index));
    }
}

void printIdsScreen() {
    ElementOfList* current = crimeList->_first;
    if(current == NULL) {
        printf("Crime list is empty\n");
    }
    while(current != NULL) {
        printf("%ud\n", ((Crime*) current->data)->id);
        current = current->_next;
    }
}

#endif //CRIME_LIST_H
