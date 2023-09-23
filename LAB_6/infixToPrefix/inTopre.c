#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#include"charStack.h"

//check precedence of operators
int precedence(char ch)
{
    int retVal = -1;
    switch(ch)
    {
    case '^':
        retVal = 3;
        break;
    case '*':
    case '/':
        retVal = 2;
        break;
    case '+':
    case '-':
        retVal = 1;
        break;
    }
    return retVal;
}

//to convert the expression
void convert(char infix[])
{
    //reverse the expression
    strrev(infix);
    int ilen = strlen(infix);
    char *prefix = (char*)malloc(ilen);
    element ce;
    char cc;
    int iIndex,pIndex=0;

    //iterate through the infix expression
    for(iIndex=0; iIndex<ilen ; iIndex++)
    {
        cc = infix[iIndex];
        //append operands to expression
        if(isalpha(cc))
        {
            prefix[pIndex++] = cc;
        }
        //push closing bracket
        else if(cc == ')')
        {
            ce.key = cc;
            Push(ce);
        }
        //pop till we peek closing bracket and then pop the closing bracket
        else if(cc == '(')
        {
            while(!isEmpty() && Peek().key!=')')
            {
                prefix[pIndex++] = Pop().key;
            }
            if(isEmpty())
            {
                printf("Invalid");
                free(prefix);
                return;
            }
            else if(Peek().key == ')')
            {
                Pop();
            }
        }
        //append previous operators if they are of higher preceedence and then push current operator onto stack
        else
        {
            while(!isEmpty() && precedence(Peek().key) > precedence(cc))
            {
                prefix[pIndex++] = Pop().key;
            }
            ce.key = cc;
            Push(ce);
        }
    }
    //pop all remaining operators from the stack
    while(!isEmpty())
    {
        prefix[pIndex++] = Pop().key;
    }
    prefix[pIndex] = '\0';
    //answer must be reversed as well
    strcpy(prefix,strrev(prefix));
    printf("%s",prefix);
}

int main()
{
    char infix[50];
    printf("Enter infix expression\n");
    scanf("%s",infix);
    printf("Prefix expression:\n");
    convert(infix);
}
