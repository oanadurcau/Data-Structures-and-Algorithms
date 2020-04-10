#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


int main()
{
    NodeT *stack = NULL; //this is the top of the stack (the reference to ...)

    push(&stack, 8);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 6);

    print_stack_contents(stack); //6 3 4 8

    printf(" -> %d<- ", pop(&stack));
    printf(" -> %d<- ", pop(&stack));

    print_stack_contents(stack); //4 8

    push(&stack, 2);
    push(&stack, 6);

    print_stack_contents(stack); //6 2 4 8

    printf(" -> %d<- ", pop(&stack));
    printf(" -> %d<- ", pop(&stack));
    printf(" -> %d<- ", pop(&stack));

    print_stack_contents(stack); //8

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    print_stack_contents(stack); //

    return 0;
}
