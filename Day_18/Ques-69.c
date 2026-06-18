#include <stdio.h>

int main()
{

    // Q-69 Write a program to Bubble Sort

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

    // Bubble Sort

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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