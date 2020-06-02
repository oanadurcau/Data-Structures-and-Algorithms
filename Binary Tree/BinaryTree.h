#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
typedef struct node_type
{
    int id; /* numele nodului */
    /* alte informatii  utile */
    struct node_type *left, *right;
} NodeT;

void fatalError(const char *msg);
void postorder(NodeT *p);
void inorder(NodeT *p);
int leaf_node(NodeT *node);
int intern_nodes(NodeT *node);
int maxim(int a,int b);
int height(NodeT *node);
NodeT* search(NodeT *p, int key);
int diameter(NodeT *p);
void preorder(NodeT *p);
NodeT *createBinTree( int branch, NodeT *parent );
NodeT *createBinTreeFromFile(FILE* f);
#endif // BINARYTREE_H_INCLUDED
