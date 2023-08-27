#ifndef CHARSTACK_ATTEMPT_H_INCLUDED
#define CHARSTACK_ATTEMPT_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

typedef struct
{
    char key;
} element;

element stack[MAX_SIZE];
int ctop=-1;
int i;

//check if stack is empty
bool ischarEmpty()
{
    return ctop==-1;
}

//check if stack is full
bool ischarFull()
{
    return ctop==MAX_SIZE -1;
}

//push element onto stack
void charPush(element e)
{
    if(ischarFull())
    {
        printf("Stack is full");
        return;
    }
    stack[++ctop]=e;
}

//pop element from stack
element charPop()
{
    element popped;
    popped.key = -1;
    if(ischarEmpty())
    {
        printf("Stack is empty");
    }
    else
    {
        popped=stack[ctop--];
    }
    return popped;
}

//display the elements
void charDisplay()
{
    for(i=ctop;i>=0;i--)
    {
        printf("%c",stack[i].key);
    }
}


#endif // CHARSTACK_ATTEMPT_H_INCLUDED
