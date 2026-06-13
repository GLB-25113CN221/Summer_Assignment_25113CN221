#include <stdio.h>

int main()
{
    // Q-50 Write a program to find sum and average of array.

    int a;         // a = number of elements in the array
    int sum = 0;   // sum = stores sum of all array elements
    float average; // average = stores average of array elements

    printf("Enter the number of elements in the array: ");
    scanf("%d", &a);

    int array[a]; // Declare array of size a (variable length array)

    printf("Enter the elements of the array: ");
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &array[i]);
    }

    // Loop to calculate sum of all elements
    for (int i = 0; i < a; i++)
        sum += array[i];

    // Cast sum to float for accurate division
    average = (float)sum / a;

    // %.2f prints average with 2 decimal places
    printf("\n\nThe sum of the given array is %d.\nThe average of the array is %.2f\n\n", sum, average);

    return 0;
}