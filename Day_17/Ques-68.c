#include <stdio.h>

int main()
{

    // Q-68 Write a program to find common elements

    int n1, n2; // n1 = no. of elements in array1 and n2 = no. of elements in array 2

    printf("Enter the number of elements in array 1 and array 2 respectively: ");
    scanf("%d%d", &n1, &n2);

    int arr_1[n1], arr_2[n2];
    /* arr_1[n1] = array 1 with n1 elements
       arr_2[n2] = array 2 with n2 elements  */

    // Input array 1 elements

    printf("Enter the elements of array 1: ");

    for (int i = 0; i < n1; i++)
        scanf("%d", &arr_1[i]);

    // Input array 2 elements

    printf("Enter the elements of array 2: ");

    for (int i = 0; i < n2; i++)
        scanf("%d", &arr_2[i]);

    // The common elements of two arrays

    printf("The common elements of array 1 and array 2 are: \n");

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr_1[i] == arr_2[j])
            {

                printf("%d  ", arr_1[i]);

                arr_2[j] = -1;
                break;
            }
        }
    }

    return 0;
}
