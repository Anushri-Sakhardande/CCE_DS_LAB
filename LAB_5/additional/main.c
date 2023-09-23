#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
stacks s1;
stacks s2;

//to insert element into queue
void insertq(element e)
{
    while(!isEmpty(&s1))
    {
        //push existing elemnts onto new stack
        Push(&s2,s1.s[s1.top]);
        //pop from previous stack
        Pop(&s1);
    }
    //finally push new element
    Push(&s1,e);

    //now push from the new stack back to the original stack and from the new stack
    while(!isEmpty(&s2))
    {
        Push(&s1,s2.s[s2.top]);
        Pop(&s2);
    }

}

//to delete from queue
element deleteq()
{
    element ret;
    ret.key =-1;
    if(isEmpty(&s1))
    {
        return ret;
    }

    //simply return the top element
    ret= s1.s[s1.top];
    Pop(&s1);
    return ret;
}

int main()
{
    element e;
    initialize(&s1);
    initialize(&s2);
    e.key = 10;
    insertq(e);
    e.key = 13;
    insertq(e);
    e=deleteq();
    printf("%d",e.key);
    e=deleteq();
    printf("%d",e.key);
}
