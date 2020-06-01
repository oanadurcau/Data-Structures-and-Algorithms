void insert_after_key(node **first, node **last, int search_key, int key)
{
    node *p = (node*) malloc (sizeof(node));
    p -> key = key;
    p -> next = NULL;

    node *search = *first;

    while(search != NULL)
    {
        if(search->key == search_key)
            break;
        search = search->next;
    }

    if(search != NULL)
    {
        p->next = search->next;
        search->next = p;

        if(search == *last)
            *last = p;
    }

}
