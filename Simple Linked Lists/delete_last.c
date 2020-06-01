void delete_last(node **first, node **last)
{
    node *search, *prev;
    search = *first;
    prev = NULL;

    if(search != NULL)
    {
        while(search != *last)
        {
            prev = search;
            search = search->next;
        }

    if(search == *first)
    {
        *first = NULL;
        *last = NULL;
    }
    else
    {
        prev->next = NULL;
        *last = prev;
    }

    free(search);
    }

}
