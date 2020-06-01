void delete_key(node** first, node** last, int key)
{
    node *search, *prev;
    search = *first;
    prev = NULL;

    while(search != NULL)
    {
        if(search->key == key)
            break;
        prev = search;
        search = search->next;
    }

    if(search != NULL)
    {
        if(search == *first)
        {
            *first = (*first)->next;
            free(search);
            if(*first == NULL)
                *last = NULL;

        }
        else
        {
            prev->next = search->next;
            if(search == *last)
                *last = prev;
            free(search);
        }
    }
}
