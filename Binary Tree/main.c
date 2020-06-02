#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main()
{
    NodeT *root;
    FILE *f = fopen("ArboreBinar.txt", "r");
    if (!f)
    {
        printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
        return -1;
    }
    root = createBinTreeFromFile(f);
    fclose(f);


    printf( "\nParcurgere in preordine\n" );
    preorder( root );

    //TODO
    printf( "\nParcurgere in postordine\n" );
    postorder(root);

    printf( "\nParcurgere in ordine\n" );
    inorder(root);

    int nr_frunze = leaf_node(root);
    printf("Numarul de frunze este %d\n", nr_frunze);//3

    printf("Noduri interne = %d \n", intern_nodes(root));//5

    printf("Inaltimea arborelui = %d \n", height(root)); //3

    printf("nod = %d \n", search(root, 6));

    printf("Diametrul arborelui = %d \n", diameter(root));


    return 0;
}
