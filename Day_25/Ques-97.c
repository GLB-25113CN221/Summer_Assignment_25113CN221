#include <stdio.h>

int main()
{
    // Q97: Merge two sorted arrays

    int n1, n2;

    printf("Enter size of first sorted array: ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter elements of first sorted array: ");
    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter size of second sorted array: ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("Enter elements of second sorted array: ");
    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    int merged[n1 + n2];
    int i = 0, j = 0, k = 0;

    // Merge the two sorted arrays
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    // Copy remaining elements of arr1
    while (i < n1)
        merged[k++] = arr1[i++];

    // Copy remaining elements of arr2
    while (j < n2)
        merged[k++] = arr2[j++];

    printf("\nMerged sorted array: ");
    for (int i = 0; i < n1 + n2; i++)
        printf("%d ", merged[i]);

    return 0;
}