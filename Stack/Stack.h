#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct node
{
    int key;
    struct node *next;
} NodeT;

void push(NodeT** stack, int key);
int pop(NodeT** stack);
void print_stack_contents(NodeT* stack);
#endif // STACK_H_INCLUDED
