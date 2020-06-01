void print(node *stack)
{
    printf("\nThe stack is: \n");
    node *p = stack;

    while(p != NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}
