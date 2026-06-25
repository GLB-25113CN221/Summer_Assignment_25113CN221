#include <stdio.h>
#include <string.h>

int main()
{
    // Q98: Find common characters in strings

    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int freq1[256] = {0}, freq2[256] = {0};

    // Count frequency of characters in str1
    for (int i = 0; str1[i] != '\0'; i++)
        freq1[(unsigned char)str1[i]]++;

    // Count frequency of characters in str2
    for (int i = 0; str2[i] != '\0'; i++)
        freq2[(unsigned char)str2[i]]++;

    printf("\nCommon characters: ");
    int found = 0;

    for (int i = 0; i < 256; i++)
    {
        if (freq1[i] > 0 && freq2[i] > 0)
        {
            printf("%c ", (char)i);
            found = 1;
        }
    }

    if (!found)
        printf("None");

    return 0;
}