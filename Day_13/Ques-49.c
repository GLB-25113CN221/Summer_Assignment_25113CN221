#include <stdio.h>

int main()
{
    // Q-49 Write a program to input and display array.

    int a; // a = number of elements in the array

    printf("Enter the number of elements in the array: ");
    scanf("%d", &a);

    int array[a]; // Declare array of size a (variable length array)

    printf("Enter the elements of the array: ");
    // Loop to take input for each element
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &array[i]);
    }

    // Display
    printf("The array is : ");
    // Loop to print each element
    for (int i = 0; i < a; i++)
    {
        printf("%d\t", array[i]);
    }

    return 0;
}