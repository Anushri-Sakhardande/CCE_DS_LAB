#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct node *nptr;
nptr head = NULL;

// create node in the linked list
nptr createNode(int value)
{
    nptr temp = (nptr)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Heap is full");
        free(temp);
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

//recursively insert to the end of the list
nptr insertAfter(nptr current,int data)
{
    if(current == NULL)
    {
        return createNode(data);
    }
    else
    {
        current->next = insertAfter(current->next,data);
    }
    return head;
}

//traverse through linked list
nptr traverse(nptr current)
{
    if(current == NULL)
    {
        return;
    }
    else
    print("%d ",current->data);
    traverse(current->next);
}

