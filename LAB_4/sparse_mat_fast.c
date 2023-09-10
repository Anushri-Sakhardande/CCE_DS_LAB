#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 30


typedef struct
{
    int row;
    int col;
    int val;
} term;

int i,j,CI;

term S[MAX_SIZE];

//input the matrix
void finit()
{
    int r,c;
    CI=1;
    printf("Enter the number of rows and columns\n");
    scanf("%d",&r);
    scanf("%d",&c);
    printf("Enter values in the matrix\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            int e;
            scanf("%d",&e);
            if(e!=0)
            {
                S[CI].row=i;
                S[CI].col=j;
                S[CI].val=e;
                CI++;
            }
        }
    }
    S[0].row=r;
    S[0].col=c;
    S[0].val=CI-1;
}

//display matrix
void fdisplay(term X[])
{
    CI =1;
    for(i=0; i<X[0].row; i++)
    {
        for(j=0; j<X[0].col; j++)
        {
            if(X[CI].row==i && X[CI].col==j)
            {
                printf("%d",X[CI].val);
                CI++;
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
}

//To find transpose of matrix
void ftranspose(term T[])
{
    int NZT = S[0].val,column = S[0].col;
    int* SP=(int*)malloc(column*sizeof(int));
    int* RT=(int*)calloc(column,sizeof(int));
    if(NZT>0)
    {
        T[0].row=column;
        T[0].col=S[0].row;
        T[0].val=S[0].val;

        //count the number of terms in each row
        for(i=1;i<=NZT;i++)
        {
            RT[S[i].col]++;
        }

        //locate the start position for entry into transpose matrix
        SP[0]=1;
        for(i=1;i<column;i++)
        {
            SP[i] = SP[i-1] + RT[i-1];
        }

        //take the transpose
        for(i=1;i<=NZT;i++)
        {
            j=SP[S[i].col]++;
            T[j].row = S[i].col;
            T[j].col = S[i].row;
            T[j].val = S[i].val;
        }
    }
}

int main()
{
    term T[MAX_SIZE];
    finit();
    printf("Entered matrix is:\n");
    fdisplay(S);
    printf("Transposed matrix is:\n");
    ftranspose(T);
    fdisplay(T);
    return 0;
}

