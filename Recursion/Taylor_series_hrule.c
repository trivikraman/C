#include <stdio.h>

double e(double x, int n) //Recursive (Tail)
{
    static double s = 1;
    if (n == 0)
        return s;
    s = 1 + x / n * s;
    return e(x, n - 1);
}

double Ie(double x, int n) //Iterative
{
    double s = 1;
    for (; n > 0; n--)
    {
        s = 1 + x / n * s;
    }
    return s;
}

int main()
{
    double a, b;
    a = e(4, 10);
    b = Ie(5, 20);
    printf("%lf, %lf", a, b);
}