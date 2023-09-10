#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

typedef struct
{
    int key;
} element;

typedef struct{
    element s[MAX_SIZE];
    int top;
}stacks;

int i;

void initialize(stacks *st) {
    st->top = -1;
}

//check if stack is empty
bool isEmpty(stacks* st)
{
    return st->top==-1;
}

//check if stack is full
bool isFull(stacks* st)
{
    return st->top==MAX_SIZE -1;
}

//push element onto stack
void Push(stacks* st,element e)
{
    if(isFull(st))
    {
        printf("Stack is full");
        return;
    }
    st->top++;
    st->s[st->top]=e;
}

//pop element from stack
element Pop(stacks* st)
{
    element popped;
    popped.key = -1;
    if(isEmpty(st))
    {
        printf("Stack is empty");
    }
    else
    {
        popped=st->s[st->top];
        st->top--;
    }
    return popped;
}

//peek topmost element
element Peek(stacks* st)
{
    return st->s[st->top];
}

/*display the elements
void display(stacks* st)
{
    for(i=0;i<=top;i++)
    {
        printf("%d ",st->s[i].key);
    }
}
*/
#endif // STACK_H_INCLUDED
