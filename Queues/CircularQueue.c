#include <stdio.h>
#include <stdlib.h>
struct Node
{
 struct Node *lchild;
 int data;
 int height;
 struct Node *rchild;
}*root=NULL;

int Height(struct Node *p,struct Node *q)
{
 int x,y;
 x=p?p->height:-1;
 y=q?q->height:-1;
 return x>y?x+1:y+1;
}