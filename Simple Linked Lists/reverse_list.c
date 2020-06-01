node *reverse_list(node* head)
{
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
    return prev;
}
