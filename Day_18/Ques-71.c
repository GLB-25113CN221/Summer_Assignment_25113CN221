#include <stdio.h>

int main()
{

    // Q-71 Write a program to Binary search

    int num; // no. of elements in the array

    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &num);

    int arr[num];

    // Input the elements of the array
    printf("\nEnter the elements of array: ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    int search, low, mid, high, found = 0;
    /* search = the element to search
       low = low index
       high = high index
       mid = (low + high)/2
       found = flag to determine if we found the element or not
    */

    printf("\nEnter the element to search: ");
    scanf("%d", &search);

    // Binary Search

    low = 0, high = num - 1;

    while (high >= low)
    {

        mid = (low + high) / 2;

        if (search == arr[mid])
        {
            printf("\nFound the element at position %d in array!", mid);
            found = 1;
            break;
        }
        else if (arr[mid] > search)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (found == 0)
    {
        printf("\n%d not found in the given array.", search);
    }

    return 0;
}