#include <stdio.h>
// #include "Factorial.c" if it did not have any main fn

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int C(int n, int r)
{
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n - r);
    return t1 / (t2 * t3);
}

int nCr(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    return nCr(n - 1, r - 1) + nCr(n - 1, r );
}

int main()
{
    printf("%d", nCr(5, 3));
    return 0;
}