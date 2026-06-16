#include <stdio.h>

int main()
{
    // Q-64 Write a program to remove the duplicates from the array

    // Predefined array with duplicate elements
    int arr[20] = {3, 18, 3, 2, 5, 3, 4, 2, 9, 10, 12, 14, 15, 9, 6, 2, 3, 14, 8, 7};
    int unique[20]; // Array to store unique elements

    // Initialize unique array with zeros
    for (int i = 0; i < 20; i++)
    {
        unique[i] = 0;
    }

    // First element is always unique
    int k = 1;      // k = index for unique array
    int repeat = 0; // duplicate flag (0 = not found, 1 = found)
    unique[0] = arr[0];

    // Traverse remaining elements
    for (int i = 1; i < 20; i++)
    {
        // Check if arr[i] already exists in the array
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j]) // Duplicate found
            {
                repeat = 1; // Set flag and exit loop
                break;
            }
        }

        // If no duplicate found, add to unique array
        if (repeat == 0)
        {
            unique[k] = arr[i];
            k++; // Increment unique array index
        }
        else
        {
            repeat = 0; // Reset duplicate flag for next element
        }
    }

    // Print all unique elements
    k = 0;
    while (unique[k] != 0)
    {
        printf("%d  ", unique[k]);
        k++;
    }

    return 0;
}