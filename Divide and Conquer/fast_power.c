int fastpower(int a, int n)
{
    if(n == 1)
        return a;
    else
    {
        int x = fastpower(a, n/2);
        if(n % 2 == 0)
            return x*x;
        else
            return x*x*a;
    }
}
