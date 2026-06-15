#include <stdio.h>

int main()
{

    // Q-59 Write a program to Rotate array right

    // An array of 10 integers
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int rotate; // Number of positions to rotate

    printf("Enter the number of positions to rotate the array: ");
    scanf("%d", &rotate);

    // Display the original array
    printf("Original array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    if (rotate >= 1)
    {

        // Normalize the number of rotation
        rotate = rotate % 10;

        for (int i = 1; i <= rotate; i++)
        {

            int temp = arr[9];

            for (int j = 9; j > 0; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[0] = temp;
        }

        // Display the resultant array after rotation
        printf("Resultant array: ");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
    else if (rotate == 0)
    {
        printf("The array remains unchanged: ");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
    else
    {
        printf("Invalid input. Please enter a number greater than or equal to zero.\n");
    }
    return 0;
}