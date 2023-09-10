#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 3

typedef struct
{
    int key;
} element;

element Q[MAX_SIZE];
int f=0,r=0;

//check if queue is full
bool isFull()
{
    return ((r+1)%MAX_SIZE == f);
}

//check if queue is empty
bool isEmpty()
{
    return (f == r);
}

//to delete element
element deleteq()
{
    element e;
    e.key = -1;
    if(!isEmpty())
    {
        f = (f+1)%MAX_SIZE;
        e = Q[f];
    }
    else
    {
        printf("Empty queue\n");
    }
    return e;
}

//to insert element
void insertq(element e)
{
    if(!isFull())
    {
        r = (r+1)%MAX_SIZE;
        Q[r]= e;
    }
    else
    {
        printf("Full queue\n");
    }
}

//display elements in circular queue
void display()
{
    int i;
    if(!isEmpty())
    {
        for(i = (f+1)%MAX_SIZE ; i != r ; i = (i+1)%MAX_SIZE)
        {
            printf("%d\n",Q[i].key);
        }
        printf("%d\n",Q[i].key);
    }
}

int main()
{
    int i;
    element e;
    printf("Enter elements to be inserted\n");
    for(i=1;i<=3;i++)
    {
        fflush(stdin);
        scanf("%d",&e.key);
        insertq(e);
    }
    display();
    printf("Deleting all elements\n");
    for(i=1;i<=3;i++)
    {
        deleteq(e);
    }
    display();
}
