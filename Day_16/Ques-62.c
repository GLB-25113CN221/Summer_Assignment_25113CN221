#include <stdio.h>

int main()
{

    // Q-62 Write a program to find maximum frequency element

    int num; // Number od elements to input

    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);

    int arr[num];

    printf("Enter the elements of the array: ");

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int max_freq = 0, freq[num], element = arr[0], freq_element[num];
    /* max_freq = the maximum frequency
    freq = frequency of current element
    element = current element
    freq_element = element with maximum frequency
    */

    // initialize arrays manually
    for (int i = 0; i < num; i++)
    {
        freq[i] = 0;
        freq_element[i] = 0;
    }

    for (int i = 0, j = 0; i < num; i++)
    {

        if (arr[i] == element)
        {
            freq[j]++;
        }
        else
        {
            if (freq[j] >= max_freq)
            {
                max_freq = freq[j];
                freq_element[j] = element;
            }
            j++;
            freq[j] = 1;
            element = arr[i];
        }
    }

    int large = freq[0], i = 0;

    while (freq[i] != 0)
    {
        if (freq[i] > large)
            large = freq[i];
        i++;
    }

    printf("Maximum frequency: %d\n", large);
    printf("Most frequent elements: ");

    i = 0;
    while (freq_element[i] != 0)
    {
        if (freq[i] == large)
            printf("%d\t", freq_element[i]);
        i++;
    }

    return 0;
}