//RECURSIVE SELECTION SORT

#include <stdio.h>
#include <stdlib.h>

void selection_sort(int list[],int i,int n)
{
    int min = i;
    int j,temp;
    for(j=i+1;j<n;j++)
    {
        if(list[j]<list[min])
        {
            min = j;
        }
    }
    if(list[i]!=min)
    {
        temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
    if(i+1<n)
    selection_sort(list,i+1,n);
}

int selection_sort_main()
{
    int list[10];
    int n,i;

    //Input the number of elements
    printf("Enter the number of elements");
    scanf("%d",&n);

    //Input the elements
    printf("Enter elements");
    for(i=0; i<n; i++)
    {
        scanf("%d",&list[i]);
    }

    selection_sort(list,0,n);

    //print elements
    printf("sorted elements:");
    for(i=0; i<n; i++)
    {
        printf("%d",list[i]);
    }
    return 0;
}
