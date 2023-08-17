//MATRIX ADDITION

#include <stdio.h>
#include <stdlib.h>

int add_matrix_main()
{
    int A[10][10],B[10][10],C[10][10];
    int r,c,i,j;

    //Inputting required values
    printf("Enter the number of rows and columns");
    scanf("%d%d",&r,&c);
    printf("Enter first matrix");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter second matrix");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }

    //Finding addition
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            C[i][j] = A[i][j]+B[i][j];
        }
    }


    //Print the values
    printf("Resultant matrix is:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
