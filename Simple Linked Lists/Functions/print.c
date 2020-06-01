void print(node *first)
{

    node *p = first;
    if(first == NULL)
        printf("The list is empty");
    else
        while(p != NULL)
        {
            printf("%d ", p->key);
            p = p-> next;
        }
    printf("\n");
}
