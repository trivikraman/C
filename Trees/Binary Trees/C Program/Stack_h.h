#include <stdio.h>
#include <stdlib.h>
#include "Queue_h.h"
struct Stack
{
    int size;
    int top;
    struct Node **s;
};
void Stackcreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->s = (struct Node **)malloc(st->size * sizeof(struct Node *));
}
void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
        printf("\nStack Overflow");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
        printf("\nStack Underflow");
    else
        x = st->s[st->top--];
    return x;
}

int isEmptyStack(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
