#include <stdlib.h>
#include <stdio.h>
#include "DLL.h"

void print_forward(struct list_header L)
{
    //TODO insert code her
    NodeDL* p;
    for(p = L.first; p != NULL; p = p->next)
        printf("%d ", p->key);

}

void print_backward(struct list_header L)
{
    //TODO insert code here
    NodeDL* p;
    for(p = L.last; p != NULL; p = p->prev)
        printf("%d ", p->key);

}

NodeDL *search(struct list_header L, int givenKey)
{
    //TODO insert code here
    NodeDL* p = L.first;

    while(p != NULL && p->key != givenKey)
        p=p->next;

    if(p == NULL)
        return NULL;

    return p;
}

void insert_first(struct list_header *L, int givenKey)
{
    //TODO insert code here
    NodeDL* p = malloc(sizeof(NodeDL));

    p->key = givenKey;
    p->next = NULL;
    p->prev = NULL;

    if(L->first == NULL) ///the list is empty
    {
        L->first = L->last = p;
    }
    else
    {
        p-> next = L ->first;
        L->first->prev = p;
        L->first = p;
    }
}


void insert_last(struct list_header *L, int givenKey)
{
    //TODO insert code here
    NodeDL* p = malloc(sizeof(NodeDL));

    p->key = givenKey;
    p->next = NULL;
    p->prev = NULL;

    if(L->last == NULL) ///the list is empty
    {
        L->first = L->last = p;
    }
    else
    {
        p-> prev = L->last;
        L->last->next = p;
        L->last = p;
    }
}

void insert_after_key(struct list_header *L, int afterKey, int givenKey)
{
    //TODO insert code here
    NodeDL* p = search(*L, afterKey);

    if(p != NULL)
    {
        if(p->next == NULL)
            insert_last(L, givenKey);
        else
        {

            NodeDL* q = p->next;
            NodeDL* newn = malloc(sizeof(NodeDL));

            newn->key = givenKey;
            newn->next = q;
            newn->prev = p;
            p->next = newn;
            q->prev = newn;
        }

    }

}

void delete_first(struct list_header *L)
{
    //TODO insert code here

    NodeDL* p = L->first;
    if(p != NULL)
    {
        if(p == L->last)
        {
            L->first = L->last = NULL;

        }
        else
        {
            L->first = L->first->next;
            L->first->prev = NULL;

        }
        free(p);
    }

}

void delete_last(struct list_header *L)
{
    //TODO insert code here
    NodeDL* p =L->last;

    if(p != NULL)
    {


        if( p == L->first)
        {
            L->first = L->last = NULL;
        }
        else
        {
            L->last = L->last->prev;
            L->last->next = NULL;
        }

        free(p);
    }

}

void delete_key(struct list_header *L, int givenKey)
{
    //TODO insert code here
    NodeDL* q = search(*L, givenKey);

    if(q != NULL)
    {
        NodeDL* p = q->prev;
        NodeDL* n = q->next;

        if(p == NULL)
            delete_first(L);
        else if(n == NULL)
            delete_last(L);
        else
        {
            p->next = n;
            n->prev = p;

        }
        free(q);
    }

}
