#include <stdio.h>
#include <string.h>

int main()
{
    // Q-95 Write a program to find longest word

    char string[200];

    printf("\nEnter a string: ");
    fgets(string, sizeof(string), stdin);

    // Remove newline
    int len = strlen(string);
    if (len > 0 && string[len - 1] == '\n')
        string[len - 1] = '\0';

    len = strlen(string);
    int start = 0, max_start = 0, max_len = 0;
    int current_len = 0;

    for (int i = 0; i <= len; i++)
    {
        char ch = string[i];

        // Check if character is a letter
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            current_len++;
        }
        else
        {
            // End of a word (space, punctuation, or null)
            if (current_len > max_len)
            {
                max_len = current_len;
                max_start = start;
            }
            start = i + 1;
            current_len = 0;
        }
    }

    // Print the longest word
    printf("\nThe longest word is: ");
    for (int i = max_start; i < max_start + max_len; i++)
    {
        printf("%c", string[i]);
    }
    printf(" (length: %d)\n", max_len);

    return 0;
}