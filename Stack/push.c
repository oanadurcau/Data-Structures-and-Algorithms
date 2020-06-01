void push(node **stack, int key)
{
    node *p = (node*)malloc(sizeof(node));
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
