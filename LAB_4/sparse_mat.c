#include<stdio.h>
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
void init()
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
void mdisplay(term X[])
{
    CI =1;
    for(i=0; i<X[0].row; i++)
    {
        for(j=0; j<X[0].col; j++)
        {
            if(X[CI].row==i && X[CI].col==j)
            {
                printf("%d ",X[CI].val);
                CI++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

//To find transpose of matrix
void transpose(term T[])
{
    CI = 1;
    T[0].row = S[0].col;
    T[0].col = S[0].row;
    T[0].val = S[0].val;
    for(i=0;i<S[0].row;i++)
    {
        for(j=1;j<=S[0].val;j++)
        {
            if(S[j].col == i)
            {
                T[CI].row = i;
                T[CI].col = S[j].row;
                T[CI].val = S[j].val;
                CI++;
            }
        }
    }
}

int main()
{
    term T[MAX_SIZE];
    init();
    printf("Entered matrix is:\n");
    mdisplay(S);
    printf("Transposed matrix is:\n");
    transpose(T);
    mdisplay(T);
    return 0;
}
