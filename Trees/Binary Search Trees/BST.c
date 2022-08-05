#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key == t->data)
        {
            printf("\nDuplicate entered");
            return;
        }
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else
    {
        r->rchild = p;
    }
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

struct Node *Search(int key)
{
    struct Node *t = root;
    while (t)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;

    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    return p;
}

int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *InPre(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct Node *RDelete(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL && p->data == key)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->lchild = RDelete(p->lchild, key);
    else if (key > p->data)
        p->rchild = RDelete(p->rchild, key);
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = RDelete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = RDelete(p->rchild, q->data);
        }
    }
}

// Iterative Function to delete
// 'key' from the BST.
struct Node *deleteIterative(struct Node *root, int key)
{
    struct Node *curr = root;
    struct Node *prev = NULL;

    // Check if the key is actually
    // present in the BST.
    // the variable prev points to
    // the parent of the key to be deleted.
    while (curr != NULL && curr->data != key)
    {
        prev = curr;
        if (key < curr->data)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }

    if (curr == NULL)
    {
        printf("\n Key not found in this BST");
        return root;
    }

    // Check if the node to be
    // deleted has atmost one child.
    if (curr->lchild == NULL || curr->rchild == NULL)
    {

        // newCurr will replace
        // the node to be deleted.
        struct Node *newCurr;

        // if the left child does not exist.
        if (curr->lchild == NULL)
            newCurr = curr->rchild;
        else
            newCurr = curr->lchild;

        // check if the node to
        // be deleted is the root.
        if (prev == NULL)
            return newCurr;

        // check if the node to be deleted
        // is prev's left or right child
        // and then replace this with newCurr
        if (curr == prev->lchild)
            prev->lchild = newCurr;
        else
            prev->rchild = newCurr;

        // free memory of the
        // node to be deleted.
        free(curr);
    }

    // node to be deleted has
    // two children.
    else
    {
        struct Node *p = NULL;
        struct Node *temp;

        // Compute the inorder successor
        temp = curr->rchild;
        while (temp->lchild != NULL)
        {
            p = temp;
            temp = temp->lchild;
        }

        // check if the parent of the inorder
        // successor is the root or not.
        // if it isn't, then make the
        // left child of its parent equal to the
        // inorder successor's right child.
        if (p != NULL)
            p->lchild = temp->rchild;

        // if the inorder successor was the
        // root, then make the right child
        // of the node to be deleted equal
        // to the right child of the inorder
        // successor.
        else
            curr->lchild = temp->rchild;

        curr->data = temp->data;
        free(temp);
    }
    return root;
}

int main()
{
    Insert(50);
    Inorder(root);
    printf("\n");
    Insert(10);
    Insert(40);
    Insert(20);
    Insert(30);
    RDelete(root, 50);

    Inorder(root);
    printf("\n");

    struct Node *temp;
    temp = Search(20);
    if (temp)
        printf("element %d is found\n", temp->data);
    else
        printf("element is not found");

    return 0;
}