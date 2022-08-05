#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int col;
    int val;
    struct Node *next;
};

void display(struct Node *A[], int m, int n)
{
    int i, j;
    struct Node *p;
    for (i = 0; i < m; i++)
    {

        p = A[i];
        for (j = 0; j < n; j++)
        {
            if (p != NULL)
            {
                if (j == p->col)
                {
                    printf("%d ", p->val);
                    while (p->next != NULL)
                        p = p->next;
                }
                else
                    printf("0 ");
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void create(struct Node *A[], int r, int c)
{
    int i, j, m, n, rn, cd, vd;
    m = r;
    n = c;
    for (i = 0; i < m; i++)
        A[i] = NULL;

    for (i = 0; i < m; i++)
    {
        printf("\nEnter number of non-zero elements in row %d: ", i);
        scanf("%d", &rn);
        if (rn > 0)
        {
            printf("\nEnter elements(col,val) in row %d:\n", i);

            for (j = 0; j < rn; j++)
            {

                if (A[i] == NULL)
                {
                    struct Node *t;
                    t = (struct Node *)malloc(sizeof(struct Node));
                    scanf("%d %d", &cd, &vd);
                    t->col = cd;
                    t->val = vd;
                    t->next = NULL;
                    A[i] = t;
                }
                else
                {
                    struct Node *p, *t;
                    t = (struct Node *)malloc(sizeof(struct Node));
                    scanf("%d %d", &cd, &vd);
                    p = A[i];
                    while (p->next != NULL)
                        p = p->next;
                    t->col = cd;
                    t->val = vd;
                    t->next = NULL;
                    p->next = t;
                }
            }
        }
    }
    display(A, m, n);
}

void add(struct Node *A[], struct Node *B[], int m, int n)
{
    struct Node *C[5];
    if (sizeof(A) != sizeof(B))
        return;
    else
    {
        int i, j;
        for (i = 0; i < m; i++)
            C[i] = NULL;
        struct Node *p, *q;
        for (i = 0; i < m; i++)
        {
            struct Node *t, *h;
            p = A[i];
            q = B[i];
            while (p != NULL && q != NULL)
            {
                t = (struct Node *)malloc(sizeof(struct Node));
                if (p->col < q->col)
                {
                    t->col = p->col;
                    t->val = p->val;
                    p = p->next;
                }
                else
                {
                    if (p->col > q->col)
                    {
                        t->col = q->col;
                        t->val = q->val;
                        q = q->next;
                    }
                    else
                    {
                        t = (struct Node *)malloc(sizeof(struct Node));
                        t->col = q->col;
                        t->val = p->val + q->val;

                        p = p->next;
                        q = q->next;
                    }
                }

                if (C[i] == NULL)
                {
                    C[i] = t;
                    t->next = NULL;
                }
                else
                {
                    h = C[i];
                    while (h->next != NULL)
                        h = h->next;
                    h->next = t;
                    t->next = NULL;
                }
            }

            if (p)
            {
                if (C[i] == NULL)

                    C[i] = p;

                else
                {
                    h = C[i];
                    while (h->next != NULL)
                        h = h->next;
                    h->next = p;
                }
            }
            if (q)
            {
                if (C[i] == NULL)

                    C[i] = q;

                else
                {

                    h = C[i];
                    while (h->next != NULL)
                        h = h->next;
                    h->next = q;
                }
            }
        }
    }
    display(C, m, n);
}

int main()
{

    int m, n, num, i, j, rn;
    struct Node *A1[5];
    struct Node *A2[5];

    printf("\nEnter dimensions: ");
    scanf("%d %d", &m, &n);
    create(A1, m, n);
    printf("\n");
    create(A2, m, n);
    printf("\n\n");
    add(A1, A2, m, n);
    return 0;
}