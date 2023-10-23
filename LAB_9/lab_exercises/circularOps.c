#include <stdio.h>
#include <stdlib.h>

typedef struct cnode* cnptr;
typedef struct cnode
{
    int data;
    cnptr previous;
    cnptr next;
} cnode;

cnptr last = NULL;

//create a node
cnptr createnode(int val)
{
    cnptr temp;
    temp = (cnptr)malloc(sizeof(cnode));
    temp->data = val;
    temp->previous = NULL;
    temp->next = NULL;
    return temp;
}

//insert node into the beginning of the circular linked list
void insertNode(int val)
{
    cnptr temp = createnode(val);
    if(last==NULL)
    {
        last = temp;
        last->next = temp;
        last->previous = temp;
    }
    else
    {
        temp ->next = last->next;
        temp ->previous = last;
        last->next->previous = temp;
        last ->next = temp;
    }
}

//delete node from circular linked list
void deleteNode()
{
    if(last==NULL)
    {
        printf("Empty list");
        return;
    }
    cnptr lastprev = last->previous;
    cnptr lastnext = last->next;
    lastprev->next = lastnext;
    lastnext->previous = lastprev;
    free(last);
    last = lastnext;
}

void traverse()
{
    cnptr current = last->next;
    while(current!=last)
    {
        printf("%d->",current->data);
        current = current->next;
    }
    printf("%d\n",last->data);
}

void revTraverse()
{
    cnptr current = last->previous;
    while(current!=last)
    {
        printf("%d->",current->data);
        current = current->previous;
    }
    printf("%d\n",last->data);
}


int main()
{
    int choice;
    int val;
    do
    {
        printf("Enter:\n 0)Exit\n 1)Insert node\n 2)Delete node\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            printf("Enter value");
            scanf("%d",&val);
            insertNode(val);
            traverse();
            break;
        case 2:
            deleteNode();
            traverse();
            break;
        }
    }
    while(choice);
    return 0;
}
