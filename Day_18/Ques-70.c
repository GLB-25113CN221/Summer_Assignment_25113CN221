#include <stdio.h>

int main()
{

    // Q-70 Write a program to Selection Sort

    int num; // no. of elements in the array

    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);

    int arr[num];

    // Input the elements of the array
    printf("Enter the elements of array: ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Selection Sort

    for (int i = 0; i < num; i++)
    {

        int min_idx = i;

        for (int j = i + 1; j < num; j++)
        {

            if (arr[min_idx] > arr[j])
                min_idx = j;
        }

        if (min_idx != i)
        {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    // Print the sorted array

    printf("The sorted array is: \n");

    for (int i = 0; i < num; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}