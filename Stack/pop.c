int pop(node **stack)
{
    node *p;
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
