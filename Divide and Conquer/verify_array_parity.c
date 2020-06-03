#include <stdio.h>
#include <stdlib.h>
int par(int a)
{
    int cont = 0;
    while(a > 0)
    {
        cont++;
        a = a/10;
    }
    if(cont%2 == 0 || cont == 0)
        return 1;
    else
        return 0;
}
int search(int *a, int p, int q)
{
    int d = 0, v1, v2;
    if(p == q)
    {
        printf("%d ", a[p]);
        if(!par(a[p]))
            return -1;
    }
    else if(p < q)
    {
        int m = (p + q) / 2;

        int v1 = search(a, p, m);
        int v2 = search(a, m + 1, q);

        if(v1 == -1 || v2 == -1)
            d = -1;

        return d;
    }

}
int main()
{
    int numbers[] = {10,20, 50, 710, 99};

    int n = (int) (sizeof(numbers) / sizeof(int));

    if(search(numbers, 0, n-1) == -1)
        printf("impar");
    else
        printf("par");




    return 0;
}
