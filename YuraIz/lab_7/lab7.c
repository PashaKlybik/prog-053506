//Task 6.2(27)
#include <stdio.h>
#include "doubly_linked_list.h"
#include "criminal_list.h"
#include "crime_list.h"

void (* screenByIndex(int index))(void) {
    switch(index) {
        case 1: return newCriminalScreen;
        case 2: return removeCriminalScreen;
        case 3: return printNamesScreen;
        case 4: return printCriminalScreen;
        case 5: return newCrimeScreen;
        case 6: return removeCrimeScreen;
        case 7: return printIdsScreen;
        case 8: return printCrimeScreen;
        case 9:

        default:
            return NULL;
    }
}

void showScreen(void (* screen)()) {
    fgetc(stdin);
    screen();
}

void screenSelection() {
    int index = 0;
    while(1) {
        printf("select\n\
                \r1. Add new criminal\n\
                \r2. Remove criminal\n\
                \r3. Print names\n\
                \r4. Print criminal\n\
                \r5. Add new arime;\n\
                \r6. Remove crime\n\
                \r7. Print IDs\n\
                \r8. Print crime\n");
        scanf("%d", &index);
        void (* screen)() = screenByIndex(index);
        if(screen != 0) {
            showScreen(screen);
        } else {
            return;
        }
    }
}

int main() {
    criminalList = initList();
    crimeList = initList();

    //newCriminalScreen();
    screenSelection();

    printf("\n");
}