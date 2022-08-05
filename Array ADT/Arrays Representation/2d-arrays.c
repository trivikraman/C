#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;

    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 6, 7}}; //2-D array in stack

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\n");

    int *B[3]; // Partially in stack and partially in heap
    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));
    B[3] = (int *)malloc(4 * sizeof(int));

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
    printf("\n");

    int **C; //Entire 2-D array in heap
    C = (int **)malloc(3 * sizeof(int *));
    C[0] = (int *)malloc(4 * sizeof(int));
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));
    C[3] = (int *)malloc(4 * sizeof(int));
    C[1][2] = 15;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < 4; i++)
        free(B[i]);

    for (i = 0; i < 3; i++)
        free(C[i]);

    free(C);

    return 0;
}