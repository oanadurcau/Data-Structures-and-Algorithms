#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"


void fatalError(const char *msg)
{
    printf( msg );
    printf( "\n" );
    exit ( 1 );
}

void postorder(NodeT *p)
{
//scrieti codul pentru parcurgerea in postordine
    if(p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d \n", p->id);
    }
    else
        return NULL;
}

void inorder(NodeT *p)
{
//scrieti codul pentru parcurgerea in inordine
    if(p != NULL)
    {
        inorder(p->left);
        printf("%d \n", p->id);
        inorder(p->right);
    }
    else
        return NULL;
}

int leaf_node(NodeT *node)
{
    //scrieti codul pentru calcularea numarului de frunze ale unui arbore
    if(node == NULL)
        return 0;
    else if((node->left == NULL) && (node->right == NULL))
    {
        ///printf("%d ", node -> id);
        return 1;
    }
    else
        return leaf_node(node->left) + leaf_node(node->right);

}

int intern_nodes(NodeT *node)
{
    //scrieti codul pentru calcularea numarului de noduri interne ale unui arbore
    if(node == NULL)
        return 0;
    else if(node->left != NULL || node->right != NULL)
    {
        ///printf("%d ", node -> id);
        return 1 + intern_nodes(node->left) + intern_nodes(node->right);
    }
    else
        return 0;

}

int maxim(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int height(NodeT *node)
{
    //scrieti codul pentru calcularea inaltimii unui arbore
    if(node == NULL)
        return -1;
    else
        return 1 + maxim(height(node->left), height(node->right));

}

NodeT* search(NodeT *p, int key)
{
    if(p == NULL)
        return NULL;
    if(p->id == key)
    {
        printf("%d", p->id);
        return p;
    }
    else
    {
        NodeT* aux = search(p->left, key);
        if(aux)
            return aux;
        else
        {
            aux = search(p->right, key);
            if(aux)
                return aux;
        }
    }
    return NULL;

}


int diameter(NodeT *p)
{
    if (p == NULL)
        return 0;

    /* get the height of left and right sub-trees */
    int lheight = height(p->left);
    int rheight = height(p->right);

    /* get the diameter of left and right sub-trees */
    int ldiameter = diameter(p->left);
    int rdiameter = diameter(p->right);

    /* Return max of following three
     1) Diameter of left subtree
     2) Diameter of right subtree
     3) Height of left subtree + height of right subtree + 1 */
    return maxim(lheight + rheight + 1, maxim(ldiameter, rdiameter));

}

void preorder(NodeT *p)
/*
 * p = nodul curent;
*/
{
    if ( p != NULL )
    {
        printf( "%d \n", p->id);
        preorder(p->left);
        preorder(p->right);
    }
}
//creaza un arbore binar prin citirea de la tastatura
NodeT *createBinTree( int branch, NodeT *parent )
{
    NodeT *p;
    int id;

    /* read node id */
    if ( branch == 0 )
        printf( "Valoarea pentru radacina [0 pt null] =" );
    else if ( branch == 1 )
        printf( "Fiul stang al nodului cu valoarea %d [0 pt null] =",
                parent->id );
    else
        printf( "Fiul drept al nodului cu valoarea %d [0 pt null] =",
                parent->id );
    scanf("%d", &id);
    if ( id == 0 )
        return NULL;
    else
    {
        /* construim nodul la care pointeaza p */
        p = ( NodeT *)malloc(sizeof( NodeT ));
        if ( p == NULL )
        {
            printf( "Nu mai avem memorie in createBinTree" );
            exit(1);
        }
        /* fill in node */
        p->id = id;
        p->left = createBinTree( 1, p );
        p->right = createBinTree( 2, p );
    }
    return p;
}
NodeT *createBinTreeFromFile(FILE* f)
{
    NodeT *p;
    int c;

    /* se citeste id-ul nodului */
    fscanf(f, "%d", &c);
    if ( c == 0 )
        return NULL; /* arbore vid, nu facem nimic */
    else /* else inclus pentru claritate */
    {
        /* construim nodul la care pointeaza p */
        p = ( NodeT *) malloc( sizeof( NodeT ));
        if ( p == NULL )
            fatalError( "Nu mai avem memorie in createBinTree" );
        /* se populeaza nodul */
        p->id = c;
        p->left = createBinTreeFromFile(f);
        p->right = createBinTreeFromFile(f);
    }
    return p;
}

