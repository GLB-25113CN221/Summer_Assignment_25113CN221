#include <stdio.h>

int main()
{
    // Q-53 Write a program to Linear Search

    // Predefined array of 10 integers
    int array[10] = {13, 25, 43, 65, 72, 17, 9, 21, 34, 1};

    int search;     // element to find
    int found = -1; // found = index

    printf("Enter a number to search in the array: ");
    scanf("%d", &search);

    // Traverse array to find matching element
    for (int i = 0; i < 10; i++)
    {
        // If current element equals search value
        if (array[i] == search)
        {
            found = i;
            break;
        }
    }

    // If found != -1, element was found
    if (found != -1)
        printf("The number is present in array at index %d", found);
    else
        printf("%d is not found in the array.\n\n", search);

    return 0;
}