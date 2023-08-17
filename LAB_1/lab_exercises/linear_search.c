//LINEAR SEARCH

#include <stdio.h>
#include <stdlib.h>

int linear_search_main()
{
    int list[10];
    int n,i,searchKey,found=0;

    //Input the number of elements
    printf("Enter the number of elements");
    scanf("%d",&n);

    //Input the elements
    printf("Enter elements");
    for(i=0; i<n; i++)
    {
        scanf("%d",&list[i]);
    }

    //Input the search element
    printf("Enter element to be found");
    scanf("%d",&searchKey);

    //Linear search
    for(i=0; i<n; i++)
    {
        if(list[i]==searchKey)
          {
              found=1;
              printf("Found at index %d",i);
              break;
          }
    }
    if(found==0)
        printf("Key not present");
    return 0;
}
