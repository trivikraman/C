#include <stdio.h>

int sum(int n) //Recursive
{
    if (n == 0)
        return 0;
    return sum(n - 1) + n;
}

int Isum(int n) //Iterative
{
    int s = 0;
    int i;
    for (i = 1; i <= n; i++)
        s = s + i;
    return s;
}

int main()
{
    int r, x;
    x = sum(5);
    r = Isum(5);
    printf("%d, %d", x, r);
    return 0;
}