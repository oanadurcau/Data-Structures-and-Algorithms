#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"


int main()
{
    NodeT *first = NULL;
    NodeT *last  = NULL;

    //perform several insertions
    insert_first(&first, &last, 4);
    insert_first(&first, &last, 4);
    insert_first(&first, &last, 5);
    insert_first(&first, &last, 6);
    insert_first(&first, &last, 8);
    insert_first(&first, &last, 11);
    printf("The element from the position lenght-k is %d\n", FindElem(&first, &last,3));


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






    //InsertOrderedListDesc(&first, &last, 3);
    // InsertOrderedListDesc(&first, &last, 7);
    //InsertOrderedListDesc(&first, &last, 12);
    //print list contents
    print_list(first);

    printf("Reversed list is:\n");
    NodeT *newFirst = reverseList(first);
    print_list(newFirst);


    return 0;
}

