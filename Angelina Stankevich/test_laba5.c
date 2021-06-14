#include "list.h"
#include <assert.h>

int test_init(LIST *l)
{
    assert(l->head == NULL);
    assert(l->tail == NULL);
}

int test_push_front(LIST *l)
{
    assert(l->head->value == 3);
}

int test_push_back(LIST *l)
{
    assert(l->head->value == 2);
    assert(l->tail->value == 4);
}

int test_pop_front(LIST *l, int a, int b)
{
    assert(a == 4);
    assert(b == 2);
}

int test_insert(LIST *l, NODE *prev)
{
    assert(l->head->next->value == 5);
}

#undef main
int main()
{
    LIST l;

    init(&l);
    test_init(&l);

    push_back(&l, 2);
    push_back(&l, 4);
    test_push_back(&l);

    test_pop_front(&l, pop_front(&l), pop_front(&l));

    push_front(&l, 3);
    test_push_front(&l);

    insert(&l, l.head, 5);
    test_insert(&l, l.head);

    printf("Passed!$$\n");
    clear(&l);
    return 0;
}