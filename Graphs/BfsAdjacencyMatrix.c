#include <stdio.h>
#include <stdlib.h>

/*****************************************************
  Citirea datelor despre un graf dintr-un fisier
  cu reprezentarea grafului prin matrice de adiacenta.
  In fisier se da numarul n de varfuri ale grafului,
  apoi muchiile sub forma de perechi i j, cu 0<=i,j<n
  (i si j reprezinta indicii varfurilor conectate prin
   arc (sau muchie)).
  Graful se parcurge BFS si se scriu �ntr-un fisier
  nodurile �n ordinea parcurgerii.
******************************************************/

typedef struct
{
    int n; ///numar de varfuri
    int **m ///matricea de adiacenta
} Graf;

typedef struct
{
    int nr_elem;
    int head;
    int tail;
    int array[10];
}queue;


enum{NEVIZITAT, VIZITAT};

void printErr()
{
    printf("Memorie insuficienta!\n");
    exit(1);
}


/// operatiile  enqueue, dequeue
void initializare(queue *C, int n)
{
    C->head = 0;
    C->tail = 0;
    C->nr_elem = 0;

    for(int i = 0; i < n; i++)
        C->array[i] = 0;

    printf("Initializare reusita!\n");
}

int empty(queue *C)
{
    if(C->nr_elem == 0)
        return 1;
    return 0;
}

void enqueue(queue *C, int key)
{
    C->array[C->tail] = key;
    C->nr_elem++;
    C->tail++;
    printf("(E)Coada are %d elemente si este:", C->nr_elem);
    for(int i = 0; i < C->nr_elem; i++)
        printf("%d ", C->array[i]);
    printf("\n");

}

int dequeue(queue *C)
{
    if(!empty(&C))
    {
        int val = C->array[0];
        for(int i = 0; i < C->nr_elem; i++)
            C->array[i] = C->array[i+1];

     C->nr_elem--;
     C->tail--;
     return val;

    }
    return -1;
}
void bfs(Graf G, int nodSursa)
{
    int* vizitate; ///marcam nodurile vizitate
    vizitate = calloc(G.n, sizeof(int));
    if(vizitate == NULL) printErr;

   queue Q;

    int i, v, w;

    initializare(&Q, G.n);

    for(int i = 0; i < G.n; i++)
        vizitate[i] = NEVIZITAT;

    vizitate[nodSursa] = VIZITAT; ///marcam nodul sursa

    enqueue(&Q, nodSursa);

    while(!empty(&Q)) ///coada nu e goala
    {
       v = dequeue(&Q); ///procesam nodul Q
       for(int w = 0; w < G.n; w++)
       {
           if(G.m[v][w] == 1)
           {
               if(vizitate[w] == NEVIZITAT)
               {
                   vizitate[w] = VIZITAT;
                   printf("%d ", w);
                   enqueue(&Q, w);
               }
           }
       }

    }

}

void citireGraf(FILE *f, Graf* pG)
{
    fscanf(f, "%d", &pG->n); ///citim nr de varfuri

    ///alocam dinamic matricea de adiacenta
    pG->m = calloc(pG->n, sizeof(int*));
        if(pG->m == NULL) printErr(); ///alocare esuata

    int i;
    for(int i = 0; i < pG->n; i++)
    {
        ///alocam dinamic linia i a matricii cu n elemente intregi
        pG->m[i] = calloc(pG->n, sizeof(int));
        if (pG->m[i] == NULL) printErr();
    }

    int v, w;
    // citeste pe rand perechi (v, w) si memoreaza arcul/muchia in matricea de adiacenta:
     while(fscanf(f, "%d%d", &v, &w) == 2)
     {
         pG->m[v][w] = 1;
        // pG->m[w][v] = 1; ///graf orientat
        printf("%d %d \n", v, w);
     }
     for(int i = 0; i < pG->n; i++)
      {
          for(int j = 0; j < pG->n; j++)
         printf("%d ", pG->m[i][j]);
        printf("\n");
     }
}



int main()
{
    FILE *f = fopen("graf.txt", "r");
    if(f == NULL)
    {
        perror("graf.txt");
        exit(1);
    }

    Graf G;
    citireGraf(f, &G);
    fclose(f);

    int v;
    printf("Numarul de noduri: %d. \nDati nodul sursa: ", G.n);
    scanf("%d", &v);

    bfs(G, v);
    return 0;
}
