//MAGIC SQUARE

#include <stdio.h>
#include <stdlib.h>

//function for checking magic number
int magicCheck(int list[][10],int n)
{
    int i,j,diagonalSum1=0,diagonalSum2=0,rowSum=0,columnSum=0;

    //check for diagonals
    for(i=0;i<n;i++)
    {
        diagonalSum1 += list[i][i];
        diagonalSum2 += list[i][n-i-1];
    }
    if(diagonalSum1 != diagonalSum2)
    {
        return 0;
    }

    //check for rows and columns
    for(i=0;i<n;i++)
    {
        rowSum = 0;
        columnSum =0;
        for(j=0;j<n;j++)
        {
            rowSum += list[i][j];
            columnSum += list[i][j];
        }
        if(rowSum!=columnSum || rowSum!=diagonalSum2)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    int square[10][10];
    int n,i,j;

    //Inputting required values
    printf("Enter the number of rows and columns");
    scanf("%d",&n);
    printf("Enter first matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&square[i][j]);
        }
    }
    int isMagic = magicCheck(square,n);
    printf("%d",isMagic);
    return 0;
}

