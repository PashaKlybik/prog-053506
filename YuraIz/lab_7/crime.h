#ifndef CRIME_H
#define CRIME_H

#include "doubly_linked_list.h"
#include "criminal_list.h"

typedef struct Crime {
    unsigned int id;
    char* place;
    char* participant;
    char* effects;
    char* comments;
} Crime;

Crime* initCrime() {
    return (Crime*) calloc(1, sizeof(Crime));
};

Crime* addCrime() {
    static unsigned int lastId = 0;
    Crime* crime = initCrime();
    crime->id = lastId++;
    printf("place: ");
    removeEndL(fgets(crime->place = (char*) malloc(20), 20, stdin));

    Criminal* participant = NULL;
    while(participant == NULL) {
        printf("participant: ");
        removeEndL(fgets(crime->participant = (char*) malloc(20), 20, stdin));
        participant = (Criminal*) criminalList->elementAt(criminalList, *ListFindByName(criminalList, crime->participant));
        if(participant == NULL) {
            puts("that criminal doesn't exist");
        }
    }
    printf("effects: ");
    removeEndL(fgets(crime->effects = (char*) malloc(20), 20, stdin));
    printf("comments: ");
    removeEndL(fgets(crime->comments = (char*) malloc(20), 20, stdin));
    participant->linksToTheListOfCrimes->add(participant->linksToTheListOfCrimes, &crime->id);
}

void printCrime(Crime* crime) {
    printf("place: %s\n participant: %s\n effects: %s\n comments: %s\n",
           crime->place, crime->participant, crime->effects, crime->comments);
}

void freeCrime(Crime* crime) {
    free(crime->place);
    free(crime->effects);
    free(crime->comments);
    free(crime->participant);
}

#endif //CRIME_H
