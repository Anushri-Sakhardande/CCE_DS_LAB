//MATRIX MULTIPLICATION

#include <stdio.h>
#include <stdlib.h>

int matrix_multi_main()
{
    int A[10][10],B[10][10],C[10][10];
    int rowA,rowB,colA,colB,i,j,k;

    //Inputting required values
    printf("Enter the number of rows and columns of first matrix");
    scanf("%d%d",&rowA,&colA);
    printf("Enter first matrix");
    for(i=0;i<rowA;i++)
    {
        for(j=0;j<colA;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the number of rows and columns of second matrix");
    scanf("%d%d",&rowB,&colB);
    printf("Enter second matrix");
    for(i=0;i<rowB;i++)
    {
        for(j=0;j<colB;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }

    //Check condition
    if(colA!=rowB)
    {
        printf("Multiplication not possible");
        return 0;
    }

    //multiply matrices
    for(i=0;i<rowA;i++)
    {
        for(j=0;j<colB;j++)
        {
            C[i][j]=0;
            for(k=0;k<colA;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    printf("multiplied matrix is:\n");
    for(i=0;i<rowA;i++)
    {
        for(j=0;j<colB;j++)
        {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
