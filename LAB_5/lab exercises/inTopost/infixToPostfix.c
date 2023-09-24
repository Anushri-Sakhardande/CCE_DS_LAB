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
    int ilen = strlen(infix);
    char *postfix = (char*)malloc(ilen);
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
            postfix[pIndex++] = cc;
        }
        //push opening bracket
        else if(cc == '(')
        {
            ce.key = cc;
            Push(ce);
        }
        //pop till we peek opening bracket and then pop the opening bracket
        else if(cc == ')')
        {
            while(!isEmpty() && Peek().key!='(')
            {
                postfix[pIndex++] = Pop().key;
            }
            if(isEmpty())
            {
                printf("Invalid");
                free(postfix);
                return;
            }
            else if(Peek().key == '(')
            {
                Pop();
            }
        }
        //append previous operators if they are of higher preceedence and then push current operator onto stack
        else
        {
          while(!isEmpty() && precedence(Peek().key)>=precedence(cc))
          {
              postfix[pIndex++] = Pop().key;
          }
          ce.key = cc;
          Push(ce);
        }
    }
    //pop all remaining operators from the stack
    while(!isEmpty())
    {
        postfix[pIndex++] = Pop().key;
    }
    postfix[pIndex] = '\0';
    printf("%s",postfix);
}

int main()
{
    char infix[50];
    printf("Enter infix expression\n");
    scanf("%s",infix);
    printf("Postfix expression:\n");
    convert(infix);
}
