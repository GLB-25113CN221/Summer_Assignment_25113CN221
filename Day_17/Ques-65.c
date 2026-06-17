#include <stdio.h>

int main()
{

    // Q-65 Write a program to Merge arrays

    int num1, num2; // num1 = Number of elements in array 1, num2 = No. of elements in array 2

    printf("Enter the number of elements in array 1 and array 2 respectively: ");
    scanf("%d%d", &num1, &num2);

    int arr_1[num1 + num2], arr_2[num2];
    /* arr_1[num1] = array 1 with num1 elements
       arr_2[num2] = array 2 with num2 elements  */

    // Enter the elements of arr_1

    printf("Enter the array 1 : ");
    for (int i = 0; i < num1; i++)
    {
        scanf("%d", &arr_1[i]);
    }

    // Enter the elements of arr_2

    printf("Enter the array 2: ");
    for (int i = 0; i < num2; i++)
    {
        scanf("%d", &arr_2[i]);
    }

    for (int i = 0; i < num2; i++)
    {
        arr_1[num1 + i] = arr_2[i];
    }

    // Print the merged array

    printf("The final array after merging: \n");
    for (int i = 0; i < (num1 + num2); i++)
    {
        printf("%d ", arr_1[i]);
    }

    return 0;
}