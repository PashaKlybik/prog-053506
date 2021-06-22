#include "main.h"
#include <assert.h>

int test_compare()
{
    double buffer;
    assert(compare(1,0.001, &buffer) == 3);
    assert(compare(123,0.001, &buffer) == -1);
    assert(compare(50,0.1, &buffer) == -1);


    printf("All tests are successful\n");
    system("pause");
}

#undef main
int main()
{
    test_compare();
}