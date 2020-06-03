#include <stdio.h>
typedef struct
{
    int s, f; //timpii de start si final
    char nume[100]; //denumire
} activitate;
activitate activitati[100];
int n;


void select_activitati(int x[], int* nr_activitati)
{
    ///se selecteaza activitatile conform strategiei greedy
    ///x[i] contine numere 0:n-1
    ///x[i] = k, inseamna ca am selectat activitatea k
    ///nr_activitati se modifica

    x[0] = 0;
    *nr_activitati = 1;
    int final_time = activitati[0].f, k = 1;


    while(activitati[k].s != 0)
    {
        if(activitati[k].s == final_time)
        {
            x[(*nr_activitati)] = k;
            // printf(" %d %s ",x[(*nr_activitati)], activitati[x[(*nr_activitati)]].nume);
            (*nr_activitati)++;
            final_time = activitati[k].f;
        }
        k++;
    }

}

void afisare(int x[], int nr)
{
    printf("Am selectat %d activitati\n", nr);
    for (int i = 0; i < nr; i++)
    {
        printf("(%2d) %2d : %2d %s", x[i], activitati[x[i]].s, activitati[x[i]].f, activitati[x[i]].nume);
    }
}

void sort()
{
    activitate aux;
    int i,j;

    for(i = 0; i < n; i++)   ///sort activitati
        for(j = i + 1; j < n; j++)
            if(activitati[i].f >= activitati[j].f)
            {
                aux = activitati[i];
                activitati[i] = activitati[j];
                activitati[j] = aux;
            }
}
int main()
{
    FILE* f = fopen("date.txt", "r");
    int n;
    fscanf(f,"%d", &n);

    for (int i = 0; i < n; i++)
    {
        fscanf(f,"%d%d", &activitati[i].s, &activitati[i].f);
        fgets(activitati[i].nume, 100, f);
    }
    fclose(f);


    //for(int i = 0; i < n; i++)
    //  printf(" %d %s ",i, activitati[i].nume);

    activitate aux;
    int i,j;

    for(i = 0; i < n; i++)   ///sort activitati
        for(j = i + 1; j < n; j++)
            if(activitati[i].f >= activitati[j].f)
            {
                aux = activitati[i];
                activitati[i] = activitati[j];
                activitati[j] = aux;
            }
    int x[100]= {};

    int nr_activitati = 0;
    select_activitati(x, &nr_activitati);
    afisare(x, nr_activitati);
    return 0;
}
