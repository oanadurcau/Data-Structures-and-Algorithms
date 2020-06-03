int binary_search(int *a, int p, int q, int k)  ///array, first_element, last_element, nr_to_be_found
{

    if(p > q)
        return -1;

    int m = (p + q) / 2;
    if(a[m] == k)
        return m;
    else if(a[m] > k)
        return binary_search(a, p, m - 1, k);
    else
        return binary_search(a, m + 1, q, k);

}
