#include <stdio.h>

int main()
{

    // Q-67 Write a program to Intersection of arrays

    int n1, n2; // n1= number of elements in array1 , n2= number of elements in array2

    printf("Enter the number of elements in Set 1 and Set 2 respectively: ");
    scanf("%d%d", &n1, &n2);

    int arr_1[n1], arr_2[n2];
    /* arr_1[n1] = array 1 with n1 elements
       arr_2[n2] = array 2 with n2 elements */

    // Enter the elements of array1

    printf("Enter the elements of Set 1: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr_1[i]);
    }

    // Enter the elements of array 2

    printf("Enter the elements of Set 2: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr_2[i]);
    }

    // The intersection of two arrays

    printf("The intersection of Set 1 and Set 2 is: \n");

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            int already_printed = 0;
            if (arr_1[i] == arr_2[j])
            {
                for (int k = 0; k < i; k++)
                {

                    if (arr_1[k] == arr_1[i])
                        already_printed = 1;
                }
                if (!already_printed)
                {
                    printf("%d ", arr_1[i]);
                }
                break;
            }
        }
    }

    return 0;
}