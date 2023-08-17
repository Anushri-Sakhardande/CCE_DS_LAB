//BUBBLE SORT

#include <stdio.h>
#include <stdlib.h>

int bubble_sort_main()
{
    int list[10];
    int n, i, j, temp;

    // Input the number of elements
    printf("Enter the number of elements");
    scanf("%d", &n);

    // Input the elements
    printf("Enter elements");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }

    // bubble sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    // Print the elements
    printf("Sorted list:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", list[i]);
    }
    return 0;
}
