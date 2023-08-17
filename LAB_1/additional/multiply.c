//REPEATED ADDITION
#include <stdio.h>
#include <stdlib.h>

int addition(int a,int b,int multiply)
{
    if(b==0)
        return multiply;
    else
        return addition(a,b-1,multiply+a);
}

int addition_main()
{
    int num1,num2;
    printf("Enter two numbers");
    scanf("%d%d",&num1,&num2);
    printf("%d",addition(num1,num2,0));
    return 0;
}

