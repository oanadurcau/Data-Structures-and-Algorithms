#include <stdio.h>
#include <stdlib.h>
#define dim 7

typedef struct node
{
    int val;
    struct node *next;
}NodeT;

int hFunction(int key)
{
    if(key < 0)
        return (key % dim + dim) % dim;
    else
        return key % dim;
}


void insert( NodeT* hTable[dim], int key)
{
    int pos = hFunction(key);

    NodeT* p = (NodeT*) malloc(sizeof(NodeT));
    p->val = key;

    if(hTable[pos]!=NULL)
    {
        p->next = hTable[pos];
        hTable[pos] = p;
    }
    else
    {
        p->next = NULL;
        hTable[pos] = p;
    }
}

void deleteKey(NodeT* hTable[dim], int key)
{
    int pos = hFunction(key);

    NodeT *q, *q1;

    q1 = NULL;
    q  = hTable[pos];

    if(q == NULL)
    {
        printf("Nu am gasit cheia %d\n", key);
        return;
    }

    if( hTable[pos] != NULL && hTable[pos]->val == key) ///delete first node
    {
        hTable[pos] = hTable[pos]->next;
        free(q);
        return;
    }
    else
    {
        while(q->next != NULL)
        {
            if(q->next->val == key)
            {
                q1 = q->next;
                q->next = q1->next;
                free(q1);
                return;
            }
            q = q->next;
        }
    }

    printf("Nu am gasit cheia %d\n", key);

}



NodeT* search(NodeT* hTable[dim], int key)
{
    int pos = hFunction(key);

    NodeT* p = hTable[pos];

    while(p != NULL)
    {
        if(p->val == key)
            return p;
        else
            p = p->next;
    }

    return NULL;
}

void showAll( NodeT* hTable[dim])
{
    int i;
    for(int i = 0; i < dim; i++)
    {
        printf("%d :", i);
        ///verif daca la slotul i am adaugat ceva
        if(hTable[i] != NULL)
        {
            NodeT* p;
            p = hTable[i];
            while (p != NULL)
            {
                printf(" %d ", p->val);
                p = p->next;
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    ///initializare
    NodeT* hTable[dim];

    for(int i = 0; i < dim; i++)
        hTable[i] = NULL;

    ///test inserare
    int vals[] = {36, 18, 6, 43, 72, 10, 5, 15};

    for(int i = 0; i < sizeof(vals)/sizeof(int); i++)
        insert(hTable, vals[i]);
    showAll(hTable);

    // 0:
    // 1: 15 43 36
    // 2: 72
    // 3: 10
    // 4: 18
    // 5: 5
    // 6: 6

    ///test stergere
    int todel[] = {43, 36, 10, 61, -5};
    for(int i=0; i<sizeof(todel)/sizeof(int); i++)
        deleteKey(hTable, todel[i]);
    showAll(hTable);

        // 0:
    // 1: 15
    // 2: 72
    // 3:
    // 4: 18
    // 5: 5
    // 6: 6


    int key = 4;
    if( search(hTable, key) != NULL)
    printf("cheia a fost gasita la poz %p",search(hTable, key));
    else
        printf("cheia nu a fost gasita" );



    return 0;
}
