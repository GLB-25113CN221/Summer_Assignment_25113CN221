#include <stdio.h>

int main()
{

    // Q-61 Write a program to find missing number in array

    int num;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);

    int arr[num], sum = 0;

    printf("Enter the elements of the array: ");

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int total_sum = (num + 2) * (num + 1) / 2;

    printf("The missing number is: %d", total_sum - sum);

    return 0;
}