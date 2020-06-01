void delete_first(node **first, node **last)
{
    node*p;

    if(*first != NULL)
    {
        p = *first;
        *first = (*first)->next;
        free(p);

        if(*first == NULL)
            *last = NULL;

    }

}
