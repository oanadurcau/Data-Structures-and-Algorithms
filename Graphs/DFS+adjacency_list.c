#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod {
    int key;
    struct nod* next;
} NodeT;


typedef struct graff{
    int n;
    NodeT** list;
} Graf;

enum {VIZITAT, NEVIZITAT};

void dfs(int poz_curenta, int* viz, Graf g)
{

    viz[poz_curenta] = 1;
    for(NodeT* vecin = g.list[poz_curenta]; vecin != NULL; vecin = vecin->next)
      if(viz[vecin->key] == 0)
        dfs(vecin->key, viz, g);

}

void formare_graf(Graf* g, char *s)
{
    int lung = strlen(s);

    g->list =(NodeT**)calloc(g->n, sizeof(NodeT*));

        for(int i=0; i<g->n; i++)
           g->list[i] = NULL;

    for(int i = 0; i < lung - 2; i = i + 4)
    {
        int vf1 = s[i]-'a';
        int vf2 = s[i+2]-'a';

        NodeT* p = malloc(sizeof(NodeT));
        p->key = vf2;
        p->next = NULL;

        if(g->list[vf1] == NULL)
            g->list[vf1]=p;

        else
        {
             p->next = g->list[vf1];
             g->list[vf1] = p;

        }

        NodeT* q = malloc(sizeof(NodeT));
        q->key = vf1;
        q->next = NULL;

        if(g->list[vf2] == NULL)
            g->list[vf2]=q;

        else
        {
             q->next = g->list[vf2];
             g->list[vf2] = q;

        }

    }

}

void printgr (Graf g)
{
    int v;
    for(int v = 0; v < g.n; v++)
    {
        NodeT* lista = g.list[v];
        printf("%c :", v +'a');
        while(lista != NULL)
        {
            printf("%c ", lista->key+'a');
            lista = lista->next;
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;
    int m = 4;
    char s[] ="a=c c=d d=a b=e";
    Graf g;
    g.n = n;
    formare_graf(&g, s);
    printgr(g);

    int *viz = calloc(g.n, sizeof(int));
    int cont = 0;

    for(int i = 0; i < n; i++)
    {
        if(viz[i] == 0)
        {
           cont++;
           dfs(i, viz,g);
        }
    }
    printf("%d" , cont);

    return 0;
}
