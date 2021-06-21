/*      __  __                   ____
 *     / / / /_  __,___,____    /  _/____
 *    / /_/ / / / / __ / __ \   / / /_  /
 *    \__, / /_/ / /  / /_/ / _/ /   / /_
 *   /____/\____/_/   \___\_\/___/  /___/  https://github.com/YuraIz/
 *
 *   Include file for the stack
 */

#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

typedef struct ElementOfStack {
        struct ElementOfStack* prev;
        long data;
} ElementOfStack;

typedef struct Stack {
        ElementOfStack* top;
} Stack;

void push(Stack* stack, int data) {
        ElementOfStack* el = (ElementOfStack*)malloc(sizeof(ElementOfStack));
        el->prev = stack->top;
        el->data = data;
        stack->top = el;
}

long pop(Stack* stack) {
        if(stack->top == NULL) {
#ifdef _STDIO_H
                printf("Stack is empty\n");
#endif
                exit(1);
        }
        ElementOfStack* temp = stack->top;
        stack->top = temp->prev;
        long data = temp->data;
        free(temp);
        return data;
}

#ifdef _STDIO_H
void printStack(Stack* stack) {
        ElementOfStack* current = stack->top;
        printf("<->");
        while(current != NULL) {
                printf(" %ld", current->data);
                current = current->prev;
        }
        printf(" |\n");
}
#endif

#endif