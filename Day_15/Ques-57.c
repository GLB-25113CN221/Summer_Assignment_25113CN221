#include <stdio.h>

int main()
{
    // Q-57 Write a program to reverse array

    int num;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);

    int array[num];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < num / 2; i++)
    {
        int temp = array[i];
        array[i] = array[num - i - 1];
        array[num - i - 1] = temp;
    }

    // reverse array
    printf("The reverse array is : \n");
    for (int i = 0; i < num; i++)
        printf("%d ", array[i]);

    return 0;
}