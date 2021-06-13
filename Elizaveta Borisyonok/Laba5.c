// lab_5(30)

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int value;
    struct node_t* next;
}
TNode;


TNode* PushBack(TNode** stack, int value)
{
    TNode* node = (TNode*)malloc(sizeof(TNode));
    node->value = value;
    node->next = *stack;
    *stack = node;

    return *stack;
}

int Include(TNode** stack)
{
    TNode* node = *stack;
    *stack = node->next;
    int value = node->value;
    free(node);

    return value;
}

int Emp(const TNode* stack)
{
    return (stack == NULL);
}

int main()
{
    TNode* stack = NULL;
    int n;
    printf("Enter size of stack: ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++)
    {
        PushBack(&stack, i + 1);
    }

    while (!Emp(stack))
    {
        printf("%d ", Include(&stack));
    }
    printf("\n");

    system("pause");
    return 0;
}
