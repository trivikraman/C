#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = head;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

void RDisplay(struct Node *h)
{
    static int flag = 0;
    if (h != head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

int count(struct Node *p)
{
    int l = 0;
    if (p)
    {
        do
        {
            l++;
            p = p->next;

        } while (p != head);
    }
    return l;
}

void Insert(struct Node *p, int pos, int x)
{
    struct Node *t;
    int i;

    if (pos < 0 || pos > count(head))
        return;

    if (pos == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            p = head;
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        p = head;
        for (i = 0; i < pos - 1; i++)
            p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(int pos)
{
    struct Node *p, *q;
    int i, x;

    if (pos == 1)
    {
        p = head;
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (p == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }

    else
    {
        p = head;
        for (i = 1; i < pos - 1; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    Insert(head, 0, 1);

    Display(head);
    printf("\n\n");

    Delete(3);

    RDisplay(head);

    //Clearing
    struct Node *temp, *p = head;

    do
    {
        temp = p;
        p = p->next;
        free(temp);
    } while (p != head);

    return 0;
}