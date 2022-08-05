#include <stdio.h>

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("\n (%d, %d) ", A, C);
        TOH(n - 1, B, C, A);
    }
}

int main()
{
    int n;
    printf("\n Enter Number of disks: ");
    scanf("%d", &n);
    TOH(n, 1, 2, 3);
    return 0;
}