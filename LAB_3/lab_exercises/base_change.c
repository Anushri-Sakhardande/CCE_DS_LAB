#include "stack_attempt.h"

int bmain()
{
    int decimal,base=0,changed;
    element digit;
    printf("Enter the decimal number");
    scanf("%d",&decimal);
    printf("Enter base to convert to");
    scanf("%d",&base);
    while(decimal!=0)
    {
        digit.key = decimal%base;
        Push(digit);
        decimal = decimal/base;
    }
    while(isEmpty()==false)
    {
        element popped = Pop();
        changed = changed*10 + popped.key;
    }
    printf("%d",changed);
    return 0;
}


