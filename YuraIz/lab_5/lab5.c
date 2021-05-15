#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//Task 5.1 (11)

int main() {
        Stack stack;
        init(&stack);
        push(&stack, "Hello world!\n");
        printf("%s", pop(&stack));
}
