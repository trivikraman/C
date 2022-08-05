#include <stdio.h>
#include <stdlib.h>
struct Stack_2

{

    int size;
    int top;
    long long int *S;
};

void Stackcreate_2(struct Stack_2 *st, int size)

{

    st->size = size;

    st->top = -1;

    st->S = (long long int *)malloc(st->size * sizeof(long long int));
}

void push_2(struct Stack_2 *st, long long int x)

{

    if (st->top == st->size - 1)

        printf("Stack Overflow\n");

    else

    {

        st->top++;

        st->S[st->top] = x;
    }
}

long long int pop_2(struct Stack_2 *st)

{

    unsigned long int x = -1;

    if (st->top == -1)

        printf("Stack Underflow\n");

    else

    {

        x = st->S[st->top--];
    }

    return x;
}

int isEmptyStack_2(struct Stack_2 st)

{

    if (st.top == -1)

        return 1;

    return 0;
}

int isFullStack2(struct Stack_2 st)

{

    return st.top == st.size - 1;
}