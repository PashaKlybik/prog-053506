/** @file stdlib.h
 *  This is a YuraIz stack header.
 */

#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

typedef struct ElementOfStack {
        struct ElementOfStack* prev;
        char* data;
} ElementOfStack;

typedef struct Stack {
        ElementOfStack* top;
} Stack;

void init(Stack* stack) {
        stack->top = NULL;
}

void push(Stack* stack, char* string) {
        ElementOfStack* el = (ElementOfStack*)malloc(sizeof(ElementOfStack));
        el->prev = stack->top;
        el->data = string;
        stack->top = el;
}

char* pop(Stack* stack) {
        ElementOfStack* temp = stack->top;
        stack->top = temp->prev;
        char* data = temp->data;
        free(temp);
        return data;
}

#endif