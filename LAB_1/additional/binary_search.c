//BINARY SEARCH
#include <stdio.h>
#include <stdlib.h>

int binary_search(int a[],int low, int high,int key)
{
    int mid = (low +high)/2;
    if(low>high)
        return -1;
    else if(a[mid]>key)
        return binary_search(a,low,mid-1,key);
    else if(a[mid]<key)
        return binary_search(a,mid+1,high,key);
    else if(a[mid]==key)
        return mid;
}

int binary_search_main()
{
    int list[10];
    int n,key,i;

    //Input the number of elements
    printf("Enter the number of elements");
    scanf("%d",&n);

    //Input the elements
    printf("Enter elements");
    for(i=0; i<n; i++)
    {
        scanf("%d",&list[i]);
    }

    //input search element
    printf("Enter element to be searched");
    scanf("%d",&key);

    int present = binary_search(list,0,n-1,key);
    if (present == -1)
    {
        printf("Element not present");
    }
    else
    {
        printf("Element is present at %d",present);
    }
    return 0;
}
