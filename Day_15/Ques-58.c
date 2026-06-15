#include <stdio.h>

int main()
{
    // Q-58 Write a program to Rotate array left.

    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int times; // number of times you need to rotate it

    printf("Enter the number of times you want to rotate the array: ");
    scanf("%d", &times);

    // Display the original array
    printf("The original array is: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    if (times >= 1)
    {
        times = times % 10;

        for (int i = 1; i <= times; i++)
        {

            int temp = arr[0];

            for (int j = 0; j < 9; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[9] = temp;
        }

        // Display the resultant array after rotation
        printf("The rotated array is: ");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
    else if (times == 0)
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
        printf("Invalid input. Please enter a number greater than or equal to zero.");
    }
    return 0;
}