#include <stdio.h>

int main()
{

    // Q-60 Write a program to move zeroes to end

    int arr[] = {0, 5, 0, 3, 0, 4, 9, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Display the original array
    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        int idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[idx] == 0 && arr[j] != 0)
            {
                int temp = arr[idx];
                arr[idx] = arr[j];
                arr[j] = temp;
                break;
            }
        }
    }

    // Display the array after moving zeroes to the end
    printf("Array after moving zeroes to the end: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}