#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 4

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

int cmain()
{
    element e;
    e.key = 10;
    insertq(e);
    e.key = 9;
    insertq(e);
    e.key = 4;
    insertq(e);
    e.key = 3;
    insertq(e);
    display();
    deleteq();
    deleteq();
    display();
}
