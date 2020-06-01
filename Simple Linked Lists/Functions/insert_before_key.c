void insert_before_key(node **first, node **last, int search_key, int key)
{
    node *p = (node*) malloc (sizeof(node));
    p -> key = key;
    p -> next = NULL;
    node *search = *first;
    node *prev = NULL;

    while(search != NULL)
    {
        if(search->key == search_key)
            break;
        prev = search;
        search = search->next;
    }

    if(search != NULL)
    {
        if(search == first)
        {
            p->next = first;
            first = p;
        }
        else
        {
            prev->next = p;
            p->next = search;
        }
    }
}
