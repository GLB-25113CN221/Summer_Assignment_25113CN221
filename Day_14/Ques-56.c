#include <stdio.h>

int main()
{
    // Q-56 Write a program to find duplicates in array

    // Predefined array with duplicates
    int arr_[20] = {5, 2, 8, 5, 3, 5, 9, 2, 4, 7,
                    8, 5, 1, 6, 3, 5, 9, 2, 4, 8};

    // Bubble sort to sort array in ascending order
    for (int i = 0; i < 20; i++)
    {

        for (int j = 0; j < 19 - i; j++)
        {
            // If next element is smaller, swap
            if (arr_[j + 1] < arr_[j])
            {
                int temp = arr_[j + 1];
                arr_[j + 1] = arr_[j];
                arr_[j] = temp;
            }
        }
    }

    printf("The duplicate elements in array are as follows: ");

    int i = 0;
    // Traverse sorted array to find duplicates
    while (i < 20)
    {
        int count = 0; // Counter for occurrences of current element

        // Count how many times current element appears
        for (int j = i; j < 20; j++)
        {
            if (arr_[i] == arr_[j])
                count++;
        }

        // If appears more than once, it's a duplicate
        if (count > 1)
            printf("%d ", arr_[i]);

        // Move i to the next new element (skip counted positions)
        i = i + count;
    }

    return 0;
}