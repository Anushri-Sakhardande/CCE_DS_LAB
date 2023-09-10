#ifndef STACK_ATTEMPT_H_INCLUDED
#define STACK_ATTEMPT_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

typedef struct
{
    int key[MAX_SIZE];
    int top=-1;
}stacks;

int i;

//check if stack is empty
bool isEmpty(stacks* s)
{
    return s->top==-1;
}

//check if stack is full
bool isFull(stacks* s)
{
    return s->top==MAX_SIZE -1;
}

//push element onto stack
void Push(stacks* s,int e)
{
    if(isFull(s))
    {
        printf("Stack is full");
        return;
    }
    s->top++;
    s->key[s->top]=e;
}

//pop element from stack
int Pop(stacks* s)
{
    int popped = -1;
    if(isEmpty(s))
    {
        printf("Stack is empty");
    }
    else
    {
        popped=s->key[s->top];
        s->top--;
    }
    return popped;
}

//display the elements
void display()
{
    for(i=top;i>=0;i--)
    {
        printf("%d",s->key[i]);
    }
}


#endif // STACK_ATTEMPT_H_INCLUDED
