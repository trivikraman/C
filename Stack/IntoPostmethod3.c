#include <stdio.h>

#include <stdlib.h>

#include <string.h>

struct Stack

{

    int size;

    int top;

    char *S;
};

void push(struct Stack *st, char x)

{

    if (st->top == st->size - 1)

        printf("Stack overflow\n");

    else

    {

        st->top++;

        st->S[st->top] = x;
    }
}

char pop(struct Stack *st)

{

    char x = -1;

    if (st->top == -1)
    {

        printf("Stack underflow");

        printf("\n");
    }

    else

    {

        x = st->S[st->top];

        st->top--;
    }

    return x;
}

int isOperand(char x)

{

    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')

        return 0;

    else

        return 1;
}

int inpre(char x)

{

    if (x == '#')

        return 0;

    else if (x == '+' || x == '-')

        return 2;

    else if (x == '*' || x == '/')

        return 4;

    else if (x == '^')

        return 5;

    else if (x == '(')

        return 0;
}

int outpre(char x)

{

    if (x == '+' || x == '-')

        return 1;

    else if (x == '*' || x == '/')

        return 3;

    else if (x == '6')

        return 5;

    else if (x == '(')

        return 7;

    else if (x == ')')

        return 0;
}

char *InToPost(char *infix)

{

    int i = 0, j = 0;

    int len = strlen(infix);

    char *postfix;

    struct Stack st;

    st.top = -1;

    st.size = strlen(infix);

    st.S = (char *)malloc(st.size * sizeof(char));

    push(&st, '#');

    postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0')

    {

        if (isOperand(infix[i]))

        {

            postfix[j] = infix[i];

            j++;

            i++;
        }

        else

        {

            if (outpre(infix[i]) > inpre(st.S[st.top]))

            {

                push(&st, infix[i]);

                i++;
            }

            else if (outpre(infix[i]) < inpre(st.S[st.top]))

            {

                char y = pop(&st);

                postfix[j] = y;

                j++;
            }

            else if (outpre(infix[i]) == inpre(st.S[st.top]))

            {

                pop(&st);

                i++;
            }
        }
    }

    while (st.top)

    {

        postfix[j] = pop(&st);

        j++;
    }

    postfix[j] = '\0';

    return postfix;
}

int main()

{

    char *postfix;

    char *infix = "a+b*c-d/e";

    postfix = InToPost(infix);

    printf("Postfix expression is %s", postfix);

    return 0;
}