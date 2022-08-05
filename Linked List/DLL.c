#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        t->prev = last;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

void Insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > count(p)) //checking validity
        return;
    int i;
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {

        first->prev = t;
        t->next = first;
        t->prev = NULL;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if (p->next)
            t->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i;

    if (index < 1 || index > count(p))
        return -1;

    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        first->prev = NULL;
        free(q);
        return x;
    }
    else
    {

        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        p->next->prev = q;
        free(p);
        return x;
    }
}

void Reverse(struct Node *p)
{
    struct Node *temp;
    p = first;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}

int main()
{

    int A[] = {10, 20, 40, 50, 60};
    create(A, 5);

    Reverse(first);
    Display(first);

    //Clearing
    struct Node *temp;

    while (first != NULL)
    {
        temp = first;
        first = first->next;
        free(temp);
    }

    return 0;
}
 