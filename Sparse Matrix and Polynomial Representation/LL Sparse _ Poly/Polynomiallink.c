#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

void Display(struct Node *p)
{
    struct Node *t;
    t = p;
    while (t != NULL)
    {
        printf("%dx^%d+ ", t->coeff, t->exp);
        t = t->next;
    }
    printf("\n");
}

void create(struct Node **p)
{
    struct Node *t, *q;
    int n, i;
    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    printf("\nEnter terms(coeff,exp):");
    for (i = 0; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d %d", &t->coeff, &t->exp);
        if (*p == NULL)
        {
            *p = t;
            t->next = NULL;
        }
        else
        {
            q = *p;
            while (q->next != NULL)
                q = q->next;
            q->next = t;
            t->next = NULL;
        }
    }
}

void Add(struct Node *p, struct Node *q)
{
    struct Node *z, *t, *r = NULL;
    int c, e;
    while (p && q)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        if (p->exp > q->exp)
        {
            t = p;
            p = p->next;
            t->next = NULL;
        }
        else
        {
            if (p->exp < q->exp)
            {
                t = q;
                q = q->next;
                t->next = NULL;
            }
            else
            {
                t->coeff = p->coeff + q->coeff;
                t->exp = p->exp;
                p = p->next;
                q = q->next;
                t->next=NULL;
            }
        }
        if (r == NULL)
        {
            r = t;
            t->next = NULL;
        }
        else
        {
            z = r;
            while (z->next != NULL)
                z = z->next;
            z->next = t;
            t->next = NULL;
        }
    }
    if (p)
    {
        z = r;
        while (z->next != NULL)
            z = z->next;
        z->next = p;
        
    }
    if (q)
    {
        z = r;
        while (z->next != NULL)
            z = z->next;
        z->next = q;
        
    }
    Display(r);
}

int main()
{
    struct Node *first = NULL, *second = NULL;
    create(&first);
    Display(first);
    create(&second);
    Display(second);
    Add(first, second);
}