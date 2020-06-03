#include <stdio.h>
#include <stdlib.h>

int n;
int* aux;

void bubble_sort(int*a)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i] < a[j])
            {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
}
void merge(int* a,int nn, int*b, int m, int* c) ///a, lung_b, b, lung_c, c
{
    int i = 0, j = 0, k = 0;

    while(i < nn && j < m)
    {
        if(b[i] < c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    if(i == nn)
    {
        while(j < m)
        {
            a[k] = c[j];
            j++;
            k++;
        }
    }
    if(j == m)
    {
        while(i < nn)
        {
            a[k] = b[i];
            i++;
            k++;
        }
    }

}


void merge_sort(int *a, int l, int r)
{
    int* aux = (int*)calloc(100,sizeof(int));

    if(l < r)
    {
        int m = (r+l)/2;
        
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(aux, m - l + 1, a + l, r - m, a + m + 1); ///a, lung_b, b, lung_c, c

        for(int i = l; i <= r; i++)
            a[i] = aux[i-l];

    }
    return;
}


int main()
{

    n = 10;
    int* sir = (int*)malloc(100*sizeof(int));
    int* sir1 = (int*)malloc(100*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        sir[i] = rand();
        sir1[i] = sir[i];
    }




    bubble_sort(sir);
    merge_sort(sir1, 0, n-1);
    for(int i = 0; i < n; i++)
        printf("%d ", sir[i]);
    printf("\n");

    for(int i = 0; i < n; i++)
        printf("%d ", sir1[i]);


    return 0;
}
