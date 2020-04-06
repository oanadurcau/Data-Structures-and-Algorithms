#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
} NodeT;

NodeT *search(NodeT *head, int givenKey)
{
    //TODO: search the given key and return the first node containing it or NULL
    NodeT *p = head;

    while(p != NULL)
    {
        if(p->key == givenKey)
            return p;
        else
            p = p->next;
    }

    return NULL;
}

void print_list(NodeT *head)
{
    //TODO: print list keys
    NodeT* p = head;

    while(p != NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

void insert_first(NodeT **head, NodeT **tail, int givenKey)
{
    //TODO: insert the given key in the first position of the list given by head and tail;
    NodeT *p = malloc(sizeof(NodeT));

    p->key = givenKey;
    p->next = NULL;

    if(*head == NULL) /// the list is empty
    {
        *head = p;
        *tail = p;
    }
    else   ///the list is not empty, insert before first node
    {
        p->next = *head;
        *head = p;
    }
}

void insert_last(NodeT **head, NodeT **tail, int givenKey)
{
    //TODO: insert the given key in the last position of the list given by head and tail;
    NodeT *p = malloc(sizeof(NodeT));

    p->key = givenKey;
    p->next = NULL;

    if(*head == NULL) /// the list is empty
    {
        *head = p;
        *tail = p;
    }
    else   ///the list is not empty, insert after last node
    {
        (*tail)->next = p;
        *tail = p;
    }

}

void insert_after_key(NodeT** head, NodeT** tail, int afterKey, int givenKey)
{
    //TODO: insert the given key after afterKey, in list given by head and tail;
    NodeT *p = malloc(sizeof(NodeT));
    NodeT *search = malloc(sizeof(NodeT));

    p->key = givenKey;
    p->next = NULL;

    search = *head;

    while(search != NULL)
    {
        if(search->key == afterKey)
            break;  ///searching for the node with the key - afterKey
        search = search->next;
    }

    /* node with key afterKey has address search */
    if (search != NULL) ///we found the node
    {
        p->next = search->next;
        search->next = p;
        if (search == *tail)
            *tail = p;
    }

}

void delete_first(NodeT** head, NodeT** tail)
{
    //TODO: delete first list element
    NodeT* p;

    if(*head != NULL)
    {
        p = *head;
        *head = (*head)->next;
        free(p);
    }
    if(*head == NULL)
        *tail == NULL;


}

void delete_last(NodeT** head, NodeT** tail)
{
    //TODO: delete last list element
    NodeT* search2 = NULL;
    NodeT* search = *head;

    if(search != NULL)
    {
        while(search != *tail)
        {
            search2 = search;
            search = search->next;
        }

        if(search == *head)  ///only one node
        {
            *head = NULL;
            *tail = NULL;
            free(search);
        }
    }
    else ///more than one node
    {
        search2->next = NULL;
        * tail = search2;
        free(search);
    }


}

void delete_key(NodeT** first, NodeT** last, int givenKey)
{
    //TODO: delete element having given key
    NodeT *search = *first;
    NodeT *search2 = NULL;

    while(search != NULL)
    {
        if(search->key == givenKey)
            break;
        search2 = search;
        search = search->next;
    }
    if(search != NULL) ///found the node with given key
    {
        if(search == *first)///only one node
        {
            *first = (*first)->next;

            if(*first == NULL)
                *last == NULL;
            free(search);
        }
        else
        {
            search2->next = search->next;
            if(search == *last)
                *last = search2;

            free(search);
        }



    }
}

int main()
{
    NodeT *first = NULL;
    NodeT *last  = NULL;

    //perform several insertions
    insert_first(&first, &last, 1);
    insert_first(&first, &last, 2);
    insert_last(&first, &last, 3);
    insert_last(&first, &last, 4);
    //search for two distinct keys...
    int toSearch = 2;
    NodeT *foundNode = search(first, toSearch);
    if (foundNode == NULL)
    {
        printf("Node %d not found!\n", toSearch);
    }
    else
    {
        printf("%d found!\n", foundNode->key);
    }

    toSearch = 3;
    foundNode = search(first, toSearch);
    if (foundNode == NULL)
    {
        printf("Node %d not found!\n", toSearch);
    }
    else
    {
        printf("%d found!\n", foundNode->key);
    }

    //perform some insertions
    insert_after_key(&first, &last, 4, 22);
    insert_after_key(&first, &last, 3, 25);

    //print list contents
    print_list(first);

    //perform some deletions
    delete_first(&first,&last);
    delete_last(&first, &last);
    delete_key(&first, &last, 3);
    delete_key(&first, &last, 25);

    //print list contents
    print_list(first);



    //TODO: place here code to delete all list
    delete_first(&first,&last);
    delete_first(&first,&last);
    delete_last(&first, &last);




    //print list contents
    print_list(first);

    return 0;
}
