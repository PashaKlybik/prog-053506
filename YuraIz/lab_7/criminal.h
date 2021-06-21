#ifndef CRIMINAL_H
#define CRIMINAL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Criminal {
    char* fullName;
    char* nickname;
    float height;
    float weight;
    char* hairColor;
    char* specialSigns;
    char* citizenship;
    char* knowledgeOfLanguages;
    char* typeOfCrime;
    char* involvementInTerroristOrganizations;
    List* linksToTheListOfCrimes; //List of crimes ID's
    //List* linksToTheListOfCriminalOrganizations;
} Criminal;

void removeEndL(char* string) {
    int i = 0;
    while(string[++i] != '\n' && string[i] != '\0');
    string[i] = '\0';
}

Criminal* addCriminal() {
    Criminal* criminal = (Criminal*) malloc(sizeof(Criminal));
    printf("--Criminal adding screen--\n");
    printf(" full name: ");
    removeEndL(fgets(criminal->fullName = (char*) malloc(20), 20, stdin));
    printf("nickname: ");
    removeEndL(fgets(criminal->nickname = (char*) malloc(20), 20, stdin));
    printf("height: ");
    scanf("%f", &criminal->height);
    printf("weight: ");
    scanf("%f", &criminal->weight);
    getchar();
    printf("special signs: ");
    removeEndL(fgets(criminal->specialSigns = (char*) malloc(20), 20, stdin));
    printf("hair color: ");
    removeEndL(fgets(criminal->hairColor = (char*) malloc(20), 20, stdin));
    printf("citizenship: ");
    removeEndL(fgets(criminal->citizenship = (char*) malloc(20), 20, stdin));
    printf("knowledge of languages: ");
    removeEndL(fgets(criminal->knowledgeOfLanguages = (char*) malloc(20), 20, stdin));
    printf("type of crime: ");
    removeEndL(fgets(criminal->typeOfCrime = (char*) malloc(20), 20, stdin));
    printf("involvement in terrorist organizations: ");
    removeEndL(fgets(criminal->involvementInTerroristOrganizations = (char*) malloc(20), 20, stdin));

    return criminal;
}

void printCriminal(Criminal* criminal) {
    printf("full name: %s\nnickname: %s\nheight: %.1f\nweight: %.1f\n\
special signs: %s\nhair color: %s\ncitizenship: %s\n\
knowledge of languages: %s\ntype of crime: %s\n\
involvement in terrorist organizations: %s\n",
           criminal->fullName,
           criminal->nickname,
           criminal->height,
           criminal->weight,
           criminal->specialSigns,
           criminal->hairColor,
           criminal->citizenship,
           criminal->knowledgeOfLanguages,
           criminal->typeOfCrime,
           criminal->involvementInTerroristOrganizations
    );
    if(criminal->linksToTheListOfCrimes != NULL) {
        puts("crimes ids:\n");
        ElementOfList* current = criminal->linksToTheListOfCrimes->_first;
        while(current != NULL) {
            printf("%ud\n", *((int*) current->data));
            current = current->_next;
        }
    }
}

__attribute__((unused)) void killCriminal(Criminal* criminal) {
    free(criminal->fullName);
    free(criminal->nickname);
    free(criminal->specialSigns);
    free(criminal->hairColor);
    free(criminal->citizenship);
    free(criminal->knowledgeOfLanguages);
    free(criminal->typeOfCrime);
    free(criminal->involvementInTerroristOrganizations);
    free(criminal);
}

#endif //CRIMINAL_H