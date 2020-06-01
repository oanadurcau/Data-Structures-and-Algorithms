void insert_last(node **first, node **last, int key)
{
    node *p = (node*) malloc (sizeof(node));
    p -> key = key;
    p -> next = NULL;

    if(*first == NULL) ///lista vida
    {
        *first = p;
        *last  = p;
    }
    else
    {
        (*last)->next = p;
         *last = p;
    }
}
