#include <stdio.h>
void swap(int xp, int yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
int main()
{
    int a[10], n, i, j, c = 0, prime[100], t = 0;
    bool primez[100];
    printf("/How Many Numbers You Want\nTo Add in Array/\n\nEnter Limit : ");
    scanf("%d", &n);
    printf("\nEnter %d Numbers in Array:\n\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        c = 0;
        for (j = 2; j < a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                c = 1;
                break;
            }
        }
        if (c == 0)
        {
            prime[t] = a[i];
            t++;
        }
    }
    printf("\nPrime Numbers in Above Array:\n\n");
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (prime[j] > prime[j + 1])
                swap(prime[j],prime[j + 1]);
    for (i = 0; i < t; i++)
    {
        printf(" %d ", prime[i]);
    }
    return 0;
}