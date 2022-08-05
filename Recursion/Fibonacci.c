#include <stdio.h>
int F[10];

int fib(int n) //iterative
{
    if (n <= 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int Ifib(int n) //Recursive
{
    int t0 = 0, t1 = 1, s, i;
    for (i = 0; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t0 = s;
    }
    return s;
}

int fib_opt(int n) //Memoization
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 1] == -1)
            F[n - 1] = fib_opt(n - 1);
        if (F[n - 2] == -1)
            F[n - 2] = fib_opt(n - 2);

        return F[n - 1] + F[n - 2];
    }
}

int main()
{
    int i;
    for (i = 0; i < 10; i++)
        F[i] = -1;
    printf("%d \n", fib_opt(5));
    return 0;
}