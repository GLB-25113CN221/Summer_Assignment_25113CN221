#include <stdio.h>

int main()
{
    // Q-54 Write a program to frequency of an element

    // Predefined array of 20 integers
    int number[20] = {2, 5, 6, 4, 3, 6, 7, 8, 6, 5,
                      4, 3, 2, 6, 7, 5, 3, 3, 2, 9};

    int element;  // value to count
    int freq = 0; // frequency counter

    printf("Enter an element to find it's frequency in the given array: ");
    scanf("%d", &element);

    // Traverse entire array to count occurrences
    for (int i = 0; i < 20; i++)
    {
        // If element matches, increment counter
        if (number[i] == element)
            freq++;
    }

    printf("The frequency of %d in the given array is %d\n\n", element, freq);

    return 0;
}