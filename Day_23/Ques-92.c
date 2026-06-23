#include <stdio.h>
#include <string.h>

// function to remove space
void remove_space(char str[])
{

    int i = 0, j = 0;

    while (str[i] != '\0')
    {

        if (str[i] == '\n')
        {
            str[i] = '\0';
        }

        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }

        i++;
    }
}

int main()
{

    // Q-92 Write a program to find max occurring character

    char string[50];

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    remove_space(string);

    int len = strlen(string);

    if (len > 0 && string[len - 1] == '\n')
        string[len - 1] = '\0';

    len = strlen(string);

    int freq[256] = {0}; // to store frequency of character

    // find frequency of each character
    for (int i = 0; i < len; i++)
    {

        int ascii = (unsigned char)string[i];

        freq[ascii]++;
    }

    int max = 0;

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > freq[max])
            max = i;
    }

    printf("The character with max frequency is %c with frequency %d.", max, freq[max]);

    return 0;
}