#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.c"

int main()
{
    srand(time(NULL));
    LIST l1;
    init(&l1);

    LIST l2;
    init(&l2);

    LIST list;
    init(&list);

    createRandomCrew(&l1, 8);
    print(&l1);

    createRandomCrew(&l2, 6);
    print(&l2);

    unity(&l1, &l2, &list);
    print(&list);

    clear(&l1);
    clear(&l2);
    clear(&list);

    return 0;
}
