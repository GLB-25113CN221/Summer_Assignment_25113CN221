#include <stdio.h>

int main()
{
    // Q-51 Write a program to find the largest and smallest element

    int a; // a = number of elements in the array

    printf("Enter the number of elements in the array: ");
    scanf("%d", &a);

    int array[a]; // Declare array of size a (variable length array)

    printf("Enter the elements of the array: ");
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &array[i]);
    }

    // Initialize both large and small with first element
    int large = array[0], small = array[0];

    // Traverse through all array elements
    for (int i = 0; i < a; i++)
    {
        // If current element is greater than large, update large
        if (array[i] > large)
            large = array[i];

        // If current element is smaller than small, update small
        if (array[i] < small)
            small = array[i];
    }
    printf("The largest element of the array is %d. \nThe smallest element of the array is %d.\n\n", large, small);

    return 0;
}