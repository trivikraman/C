#include <stdio.h>
#include <time.h>
int m[999][999];
int n[9999][999];
int o[999][9999];

void main()

{
    int i, j;
    clock_t start, stop;
    double d = 0.0;

    // Array size is 999 x 999
    start = clock();
    for (i = 0; i < 999; i++)
        for (j = 0; j < 999; j++)
            m[i][j] = m[i][j] + (m[i][j] * m[i][j]);

    stop = clock();
    d = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("The run-time of row major order for m is %lf\n", d);

    start = clock();
    for (j = 0; j < 999; j++)
        for (i = 0; i < 999; i++)
            m[i][j] = m[i][j] + (m[i][j] * m[i][j]);

    stop = clock();
    d = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("The run-time of column major order for m is %lf\n \n", d);

    // Array size is 9999 x 999
    start = clock();
    for (i = 0; i < 9999; i++)
        for (j = 0; j < 999; j++)
            n[i][j] = n[i][j] + (n[i][j] * n[i][j]);

    stop = clock();
    d = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("The run-time of row major order for n is %lf\n", d);

    start = clock();
    for (j = 0; j < 999; j++)
        for (i = 0; i < 9999; i++)
            n[i][j] = n[i][j] + (n[i][j] * n[i][j]);

    stop = clock();
    d = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("The run-time of column major order for n is %lf\n \n", d);

    // Array size is 999 x 9999
    start = clock();
    for (i = 0; i < 999; i++)
        for (j = 0; j < 9999; j++)
            o[i][j] = o[i][j] + (o[i][j] * o[i][j]);

    stop = clock();
    d = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("The run-time of row major order for o is %lf\n", d);

    start = clock();
    for (j = 0; j < 9999; j++)
        for (i = 0; i < 999; i++)
            o[i][j] = o[i][j] + (o[i][j] * o[i][j]);

    stop = clock();
    d = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("The run-time of column major order for o is %lf", d);
}
// Row major is default in C/C++
// In Pascal, Fortran, Matlab,etc. column major is faster and is default layout