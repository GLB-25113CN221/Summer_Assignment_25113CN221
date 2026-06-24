#include <stdio.h>
#include <string.h>

int main()
{
    // Q-96 Write a program to remove duplicate characters

    char string[200];

    printf("\nEnter a string: ");
    scanf("%s", string);

    int len = strlen(string);
    int freq[256] = {0}; // Track which characters have been seen

    int result_index = 0;

    for (int i = 0; i < len; i++)
    {
        char ch = string[i];

        // If character is not seen before
        if (freq[(unsigned char)ch] == 0)
        {
            freq[(unsigned char)ch] = 1; // Mark as seen
            string[result_index] = ch;   // Keep it in the string
            result_index++;
        }
        // Else: character is already seen → skip it
    }

    // Add null terminator at the end
    string[result_index] = '\0';

    printf("\nString after removing duplicates: %s\n", string);

    return 0;
}