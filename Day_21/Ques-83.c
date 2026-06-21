#include <stdio.h>

int count_vowel_consonant(char str[], int choice);

int main()
{

    // Q-83 Write a program to count vowels and consonants

    char string[500];
    int count_vowel, count_consonant;
    /* count_vowel = to store the value returned by function (the number of vowels),
       count_consonant = to store the value returned by function (the number of consonants)*/

    // Input the string
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    count_vowel = count_vowel_consonant(string, 0);

    count_consonant = count_vowel_consonant(string, 1);

    // Print the output
    printf("\nThe vowel count in the given text is %d.\nThe consonant count in the given text is %d.\n\n", count_vowel, count_consonant);

    return 0;
}

int count_vowel_consonant(char str[], int choice)
{

    int ch, i = 0, vow = 0, cons = 0;
    /* vow = counts the number of vowel,
       cons = counts the number of consonants
       i = to calculate the index*/

    while (str[i] != '\n')
    {

        ch = str[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                vow++;
            }
            else
            {
                cons++;
            }
        }
        i++;
    }

    if (choice == 0)
    {
        return vow;
    }
    if (choice == 1)
    {
        return cons;
    }
}
