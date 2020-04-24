#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int key;
    int status;

}Cell;

enum{FREE, OCUPIED};

void afisare( Cell *T, int dim)
{
   printf("\n\nTabela de dispersie este \n");
   for(int i = 0; i < dim; i++)
   {
       if(T[i].status == OCUPIED)
            printf("T[%d]=%d\n",i,T[i]);
       else
        printf("T[%d]= --\n",i);
   }
}

void insertKey(Cell *T, int dim, int key, int (*hash_func)(int key, int dim, int i))
{
    for(int i = 0; i < dim; i++)
    {
        int h = hash_func(key, dim, i);

        if(T[h].status == FREE)
        {
            T[h].status = OCUPIED;
            T[h].key = key;
            return;
        }

    }
    printf("Tabela este plina\n");
}

int searchKey(Cell *T, int dim, int key, int (*hash_func)(int key, int dim, int i))
{

    for(int i = 0; i < dim; i++)
    {
        int h = hash_func(key,dim,i);

        if(T[h].status == FREE)
            return -1;
        else if(T[h].status == OCUPIED && T[h].key == key)
        return h;

    }
    return -1;
}

int hPrime(int key, int dim)
{
    if(key < 0)
        return (key % dim + dim) % dim;
    else return key % dim;
}

int h2(int key, int dim)
{
    return 5 - (key % dim);
}

int linearProbing(int key, int dim, int i)
{
    return ( hPrime(key,dim) + i) % dim;
}

int quadraticProbing(int key, int dim, int i)
{
    return(hPrime(key, dim) + i + i * i) % dim;
}
int doubleHashing(int key, int dim, int i)
{
    return(hPrime(key, dim) + i * h2(key, dim)) % dim;
}

void setTableFree(Cell *T, int dim)
{
    int i;
    for(int i = 0; i < dim; i++)
        T[i].status = FREE;
}


int main()
{
    int dim = 7;
    Cell *T = (Cell*)malloc(dim * sizeof(Cell));

    setTableFree(T,dim);
    int vals[] = {19, 36, 5, 21, 4, 26, 14, 17};
    for(int i=0; i<sizeof(vals)/sizeof(int); i++)
        insertKey(T,dim,vals[i],linearProbing);
    afisare(T, dim);
    //21, 36, 26, 14, 4, 19, 5

    //test quadratic probing
    setTableFree(T,dim);
    for(int i=0; i<sizeof(vals)/sizeof(int); i++)
       insertKey(T,dim,vals[i],quadraticProbing);
    afisare(T, dim);
    //k + i + i*i mod m: 19, 36, 5, 4, 21, 26, 14

    //test double hashing
    setTableFree(T,dim);
    for(int i=0; i<sizeof(vals)/sizeof(int); i++)
         insertKey(T,dim,vals[i],doubleHashing);
    afisare(T, dim);
    //k + i*2^k mod m: 21, 36, 5, 14, 4, 19, 26


    //test hash function
    insertKey(T,dim,1000,doubleHashing);
    afisare(T, dim);
    insertKey(T,dim,-3,linearProbing);
    afisare(T, dim);
    free(T);
    return 0;

    return 0;
}
