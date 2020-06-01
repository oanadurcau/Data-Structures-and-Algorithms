node* search_key(int *first, int key)
{
    node *search = first;

    while(search != NULL)
    {
        if(search->key == key)
            return search;
        else search = search->next;
    }

    return NULL;
}
