#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

typedef struct node
{
    int key;
    struct node *next;
} NodeT;


///BasicFunctions.c
NodeT *search(NodeT *head, int givenKey);
void print_list(NodeT *head);
void insert_first(NodeT **head, NodeT **tail, int givenKey);
void insert_last(NodeT **head, NodeT **tail, int givenKey);
void insert_after_key(NodeT** head, NodeT** tail, int afterKey, int givenKey);
void delete_first(NodeT** head, NodeT** tail);
void delete_last(NodeT** head, NodeT** tail);
void delete_key(NodeT** first, NodeT** last, int givenKey);

///OptionalProblems.c
void InsertOrderedListAsc(NodeT **head, NodeT **tail, int givenKey);
void InsertOrderedListDesc(NodeT **head, NodeT **tail, int givenKey);
NodeT *reverseList(NodeT* head);
int FindElem(NodeT **head, NodeT **tail, int k);


#endif // SLL_H_INCLUDED
