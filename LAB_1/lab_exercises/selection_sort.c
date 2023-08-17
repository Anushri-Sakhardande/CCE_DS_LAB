//SELECTION SORT

#include <stdio.h>
#include <stdlib.h>

int selection_sort_main()
{

    int list[10];
    int n, i, j, temp, selected;

    // Input the number of elements
    printf("Enter the number of elements");
    scanf("%d", &n);

    // Input the elements
    printf("Enter elements");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }

    // selection sort
    for (i = 0; i < n - 1; i++)
    {
        selected = i;
        for (j = i + 1; j < n; j++)
        {
            if (list[selected] > list[j])
            {
                selected = j;
            }
        }
        if (selected != i)
        {
            temp = list[i];
            list[i] = list[selected];
            list[selected] = temp;
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
