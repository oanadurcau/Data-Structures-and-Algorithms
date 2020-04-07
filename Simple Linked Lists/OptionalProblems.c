#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"

void InsertOrderedListAsc(NodeT **head, NodeT **tail, int givenKey)
{
    NodeT *search = *head;


    if((*head)->key >= givenKey)
        insert_first(head, tail, givenKey);
    else if((*tail)->key <= givenKey)
        insert_last(head, tail,  givenKey);
    else
    {
        while(search->next->key <= givenKey)
            search = search->next;

        insert_after_key(head, tail,  search->key, givenKey);
    }
}
void InsertOrderedListDesc(NodeT **head, NodeT **tail, int givenKey)
{
    NodeT *search = *head;


    if((*head)->key <= givenKey)
        insert_first(head, tail, givenKey);
    else if((*tail)->key >= givenKey)
        insert_last(head, tail,  givenKey);
    else
    {
        while(search->next->key >= givenKey)
            search = search->next;

        insert_after_key(head, tail,  search->key, givenKey);
    }
}

int Count(NodeT** head)
{
    int count = 0;
    NodeT* current = *head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

NodeT *reverseList(NodeT* head)
{
    NodeT* prev = NULL;
    NodeT* current = head;
    NodeT* next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
    return prev;


}
int FindElem(NodeT **head, NodeT **tail, int k)   ///find element from position length-k
{
    NodeT* search = *head;
    int length = Count(head);

    for(int i=0; i < length - k; i++)
    {
        search = search->next;
    }
    return search->key;
}

