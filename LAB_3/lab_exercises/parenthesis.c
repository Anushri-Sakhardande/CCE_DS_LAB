#include "stack_attempt.h"

int main()
{
    enum bracket={flw,par,sqr,ang};
    enum bracket bkt;
    char str[40];
    element e;
    printf("Enter expression");
    scanf("%[^\n]s",str);
    for(i=0;str[i]='\0';i++)
    {
        if(str[i]=='(')
        {
            e.key = -1 ;
            bkt = par;
            e.key =bkt;
            Push(e);
        }
    }
}



