#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct TNode *Tptr;
typedef struct TNode
{
    int data;
    Tptr leftchild;
    Tptr rightchild;
}TNode;

Tptr root;

int top = -1;
Tptr stack[MAX];

//Create nodes in the tree
Tptr createNode(int val)
{
    Tptr temp =(Tptr)malloc(sizeof(TNode));
    temp->data = val;
    temp->leftchild = temp->rightchild = NULL;
    return temp;
}

//create the binary tree
void createTree(int N)
{
    int cData,dIndex;
    char dir[50];
    Tptr previous = NULL,current;

    for(int i=0;i<N;i++)
    {
        printf("Enter data for node %d",i);
        scanf("%d",&cData);
        Tptr temp = createNode(cData);
        //assign root node
        if(!root)
        {
            root = temp;
        }

        else
        {
            printf("Enter direction");
            scanf("%s",dir);
            current = root;
            previous = NULL;
            for(dIndex=0;dir[dIndex]!='\0' && current!=NULL;dIndex++)
            {
                previous = current;
                if(dir[dIndex]=='L'||dir[dIndex]=='l')
                {
                    current = current->leftchild;
                }
                else
                {
                    current = current->rightchild;
                }
            }
            if(current!=NULL||dir[dIndex]!='\0')
            {
                printf("Invalid");
                free(temp);
                return;
            }
            if(dir[dIndex-1]=='L'||dir[dIndex-1]=='l')
            {
                previous->leftchild = temp;
            }
            else
            {
                previous->rightchild = temp;
            }
        }
    }
}

bool isFull()
{
    return top==MAX;
}

bool isEmpty()
{
    return top==-1;
}

//Push nodes onto the stack
void Push(Tptr node)
{
    if(!isFull())
    {
        stack[++top] = node;
    }
}

//Pop node from the  stack
Tptr Pop()
{
    Tptr ret = NULL;
    if(!isEmpty())
    {
        ret = stack[top--];
    }
    return ret;
}

Tptr peek()
{
    return stack[top];
}

#endif // TREE_H_INCLUDED
