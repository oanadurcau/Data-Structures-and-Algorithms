void insert_first(node **first, node **last, int key)
{
    node *p = (node*) malloc (sizeof(node));
    p -> key = key;
    p -> next = NULL;

    if(*first == NULL) ///the list is empty
    {
        *first = p;
        *last  = p;
    }
    else
    {
        p->next = *first;
        *first = p;
    }
}
