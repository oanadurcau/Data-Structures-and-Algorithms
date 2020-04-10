#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


void push(NodeT** stack, int key)
{
    //TODO add code here
    NodeT *p = malloc(sizeof(NodeT));
    p->key = key;

    if(*stack == NULL)
    {
        *stack = p;
        p->next = NULL;
    }
    else
    {
        p->next = *stack;
        *stack = p;
    }
}

int pop(NodeT** stack)
{
    //TODO add code here
    //return the key of the first node and deallocate

    NodeT *p;

    int key;

    if(*stack != NULL)
    {
        key = (*stack)->key;
        p = *stack;
        *stack = (*stack)->next;
        free(p);
        return key;
    }

    return -1;
}

void print_stack_contents(NodeT* stack)
{
    printf("\nThe stack is: \n");
    while(stack != NULL)
    {
        printf("%d ", stack->key);
        stack = stack->next;
    }
    printf("\n");
}
