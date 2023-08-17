//BINARY SEARCH

#include <stdio.h>
#include <stdlib.h>

int binary_search_main()
{
    int list[10];
    int n, i, searchKey, found = 0;

    // Input the number of elements
    printf("Enter the number of elements");
    scanf("%d", &n);

    // Input the elements
    printf("Enter elements");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }

    // Input the search element
    printf("Enter element to be found");
    scanf("%d", &searchKey);

    // binary search
    int first = 0, last = n - 1, mid;
    while (first <= last && found == 0)
    {
        mid = (first + last) / 2;
        if (searchKey == list[mid])
        {
            printf("Element found at index %d", mid);
            found = 1;
            break;
        }
        else if (searchKey > list[mid])
            first = mid + 1;
        else if (searchKey < list[mid])
            last = mid - 1;
    }
    if (found == 0)
        printf("Element not found");
    return 0;
}
