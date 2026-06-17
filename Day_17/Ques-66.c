#include <stdio.h>

int main()
{

    // Q-66 Write a program to union of arrays

    int n1, n2; // n1= number of elements in array1 , n2= number of elements in array2

    printf("Enter the number of elements in Set 1 and Set 2 respectively: ");
    scanf("%d%d", &n1, &n2);

    int arr_1[n1 + n2], arr_2[n2];
    /* arr_1[n1] = array 1 with (n1 + n2) elements
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

    // Make rest of the elements of arr_1 = zero

    for (int i = n1; i < (n1 + n2); i++)
    {
        arr_1[i] = 0;
    }

    // Union the two arrays

    int k = 0;
    for (int i = 0; i < n2; i++)
    {
        int same = 0;
        for (int j = 0; j < n1; j++)
        {
            if (arr_2[i] == arr_1[j])
                same = 1;
        }

        if (same == 0)
        {
            arr_1[n1 + k] = arr_2[i];
            k++;
        }
    }

    // print the union of two array

    printf("The union of Set 1 and Set 2 is: \n");

    for (int i = 0; i < (n1 + k - 1); i++)
        printf("%d ", arr_1[i]);

    return 0;
}
