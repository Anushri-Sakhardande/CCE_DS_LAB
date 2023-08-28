#ifndef STACK_ATTEMPT_H_INCLUDED
#define STACK_ATTEMPT_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

typedef struct
{
    int key;
} element;

element stack[MAX_SIZE];
int top=-1;
int i;

//check if stack is empty
bool isEmpty()
{
    return top==-1;
}

//check if stack is full
bool isFull()
{
    return top==MAX_SIZE -1;
}

//push element onto stack
void Push(element e)
{
    if(isFull())
    {
        printf("Stack is full");
        return;
    }
    stack[++top]=e;
}

//pop element from stack
element Pop()
{
    element popped;
    popped.key = -1;
    if(isEmpty())
    {
        printf("Stack is empty");
    }
    else
    {
        popped=stack[top--];
    }
    return popped;
}

//display the elements
void display()
{
    for(i=top;i>=0;i--)
    {
        printf("%d",stack[i].key);
    }
}


#endif // STACK_ATTEMPT_H_INCLUDED