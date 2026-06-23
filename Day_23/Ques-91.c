#include <stdio.h>
#include <string.h>

int main()
{

    // Q-91 Write a program to check anagram strings

    char str1[50], str2[50];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("\nEnter second string: ");
    scanf("%s", str2);

    int size1, size2;

    size1 = strlen(str1);
    size2 = strlen(str2);

    if (size1 != size2)
    {
        printf("\nIt is not anagram string\n");
        return 0;
    }
    int check = 0;
    for (int i = 0; i < size1; i++)
    {

        int freq1 = 1, freq2 = 0;

        for (int j = 0; j < size1; j++)
        {
            if (str1[i] == str1[j] && i != j)
            {
                freq1++;
            }
        }

        for (int j = 0; j < size2; j++)
        {
            if (str1[i] == str2[j])
            {
                freq2++;
            }
        }

        if (freq1 != freq2)
        {
            check = 1;
            break;
        }
    }

    if (check == 1)
    {
        printf("\nIt is not anagram string.\n");
    }
    else
    {
        printf("\nIt is a anagram string.\n");
    }

    return 0;
}