#include <stdio.h>

int main()
{
    // Q-52 Write a program to count even and odd elements

    int a;                 // a = number of elements in the array
    int even = 0, odd = 0; // even = count of even numbers, odd = count of odd numbers

    printf("Enter the number of elements in the array: ");
    scanf("%d", &a);

    int array[a]; // Declare array of size a (variable length array)

    printf("Enter the elements of the array: ");

    for (int i = 0; i < a; i++)
    {
        scanf("%d", &array[i]);
    }

    // Traverse through all array elements
    for (int i = 0; i < a; i++)
    {
        // If element is divisible by 2, it's even
        if (array[i] % 2 == 0)
            even++; // Increment even counter
        else
            odd++; // Increment odd counter
    }

    printf("The number of even elements is %d.\nThe number of odd elements is %d.", even, odd);

    return 0;
}