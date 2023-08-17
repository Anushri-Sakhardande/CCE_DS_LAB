//INSERTION SORT

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int list[10];
    int n, i, Insert, Prev;

    // Input the number of elements
    printf("Enter the number of elements");
    scanf("%d", &n);

    // Input the elements
    printf("Enter elements");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }

    // insertion sort
    for (i = 1; i < n; i++)
    {
        Insert = list[i];
        for (Prev = i - 1; Prev >= 0 && list[Prev] > Insert; Prev--)
        {
            list[Prev + 1] = list[Prev];
        }
        list[Prev + 1] = Insert;
    }
    // Print the elements
    printf("Sorted list:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", list[i]);
    }
    return 0;
}
