#include <stdio.h>

int main()
{
    // Q-55 Write a program to find second largest element

    // Predefined array of 20 integers
    int arr[20] = {7, 23, 45, 12, 89, 34, 56, 78, 91, 15,
                   42, 67, 31, 84, 53, 26, 99, 18, 73, 41};

    // Bubble sort to sort array in ascending order
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 19 - i; j++)
        {
            // If next element is smaller, swap
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

        printf("The second largest element of the array is %d\n\n", arr[18]);

    return 0;
}