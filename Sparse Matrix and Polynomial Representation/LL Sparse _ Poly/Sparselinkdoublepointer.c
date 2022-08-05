#include <stdio.h>
#include <stdlib.h>
struct Sparse
{
    int m;
    int n;
    int z;
    struct Node **A; //double pointer
};
struct Node
{
    int col;
    int x;
    struct Node *next;
};
void create(struct Sparse *s)
{
    int i, row;
    struct Node *t, *q;
    printf("\nenter the dimensions");
    scanf("%d%d", &s->m, &s->n);
    printf("\nenter the no of non zero elements");
    scanf("%d", &s->z);
    s->A = (struct Node **)malloc((s->m) * sizeof(struct Node *));
    for (i = 0; i < s->m; i++)
        s->A[i] = NULL;
    for (i = 0; i < s->m; i++)
        printf("%p ", s->A[i]);

    printf("\nenter the non zero elements");
    for (i = 0; i < s->z; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("\nenter the element %d", i + 1);
        scanf("%d %d %d", &row, &t->col, &t->x);
        t->next = NULL;
        if (s->A[row] == NULL)
        {
            s->A[row] = t;
        }
        else
        {
            q = s->A[row];
            while (q)
            {
                q = q->next;
            }
            q->next = t;
        }
    }
}
void display(struct Sparse s)
{
    struct Node *q;
    int i, j;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            q = s.A[i];
            while (q)
            {
                if (j == q->col)
                    printf("%d", q->x);
                else
                    printf("0");
                q = q->next;
            }
        }
        printf("\n");
    }
}
struct Sparse add(struct Sparse s1, struct Sparse s2)
{
    struct Node *t, *q, *p, *r;
    struct Sparse s3;
    int i, count = 0;
    s3.A = (struct Node **)malloc((s1.m) * sizeof(struct Node *));
    for (i = 0; i < s1.m; i++)
        s3.A[i] = NULL;
    for (i = 0; i < s1.m; i++)
    {
        q = s1.A[i];
        p = s2.A[i];
        r = s3.A[i];
        while (p && q)
        {
            if (s3.A[i] == NULL)
            {
                t = (struct Node *)malloc(sizeof(struct Node));
                s3.A[i] = t;
                r = s3.A[i];
            }
            else if (p->col == q->col)
            {
                r->next = p;
                r->next->x = p->x + q->x;
                r = r->next;
                p = p->next;
                q = q->next;
                count++;
            }
            else if (p->col > q->col)
            {
                r->next = q;
                r = r->next;
                q = q->next;
                count++;
            }
            else if (p->col < q->col)
            {
                r->next = p;
                r = r->next;
                p = p->next;
                count++;
            }
        }
        while (p != NULL)
        {
            r->next = p;
            r = r->next;
            p = p->next;
            count++;
        }
        while (q)
        {
            r->next = q;
            r = r->next;
            q = q->next;
            count++;
        }
        s3.A[i] = s3.A[i]->next;
        free(t);
    }
    s3.m = s1.m;
    s3.n = s1.n;
    s3.z = count;
    return s3;
}
int main()
{
    struct Sparse s1, s2, s3;
    create(&s1);
    create(&s2);
    s3 = add(s1, s2);
    display(s3);
}
