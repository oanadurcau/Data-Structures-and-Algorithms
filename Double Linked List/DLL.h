#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

typedef struct node
{
    int key;
    struct node *next;
    struct node *prev;
} NodeDL;


/* define a List structure, consisting of the addresses
 * (pointers) of the first and last elements
 * */
struct list_header
{
    NodeDL *first;
    NodeDL *last;
};
void print_forward(struct list_header L);
void print_backward(struct list_header L);
NodeDL *search(struct list_header L, int givenKey);
void insert_first(struct list_header *L, int givenKey);
void insert_last(struct list_header *L, int givenKey);
void insert_after_key(struct list_header *L, int afterKey, int givenKey);
void delete_first(struct list_header *L);
void delete_last(struct list_header *L);
void delete_key(struct list_header *L, int givenKey);
#endif // DLL_H_INCLUDED
