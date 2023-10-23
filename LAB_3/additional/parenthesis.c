#include<stdio.h>
#include<stdbool.h>
#include "stack.h"

enum bracket {flw,sqr,prt,ang};
int i;
 int main()
 {
    bool flag=true;
    char exp[40];
    printf("Enter expression\n");
    scanf("%[^\n]s",exp);
    for(i=0;exp[i]!='\0';i++)
    {
        element e;
        e.key = -1;
        if(exp[i]=='{')
        {
            e.key = flw;
            Push(e);
        }
        if(exp[i]=='(')
        {
            e.key = prt;
            Push(e);
        }
        if(exp[i]=='[')
        {
            e.key = sqr;
            Push(e);
        }
        if(exp[i]=='<')
        {
            e.key = ang;
            Push(e);
        }
        if(exp[i]=='}')
        {
            if(Pop().key!=flw || isEmpty())
            {
                printf("Error!!!!");
                break;
            }
        }
        if(exp[i]==')')
        {
            if(Pop().key!=prt || isEmpty())
            {
                printf("Error!!!!");
                break;
            }
        }
        if(exp[i]==']')
        {
            if(Pop().key!=sqr || isEmpty())
            {
                printf("Error!!!!");
                break;
            }
        }
        if(exp[i]=='>')
        {
            if(Pop().key!=ang || isEmpty())
            {
                printf("Error!!!!");
                flag=false;
                break;
            }
        }
    }
    if(!isEmpty())
    {
        flag = false;
    }
    if(flag){
        printf("Correct expression");
    }
    else
    {
        printf("Error!!!!");
    }
 }
