//Task 6.2(27)

#include <stdio.h>
#include "doubly_linked_list.h"
#include "criminal.h"

int main() {
        CriminalList* cl = initCriminalList();

        cl->add(cl);

        //printf("%s", ((Criminal*)cl->data->elementAt(cl->data, 0))->fullName);

        //printf("printing database...\n\n\n");

        //for(int i = 0; i < 3; i++) {
        //        printCriminal(
        //                cl->elementAt(cl, i)
        //        );
        //}

        printf("\n");
}
