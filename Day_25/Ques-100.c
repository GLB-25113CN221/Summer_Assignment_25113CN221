#include <stdio.h>
#include <string.h>

int main()
{
    // Q100: Sort words by length

    int n;

    printf("Enter number of words: ");
    scanf("%d", &n);

    char words[n][50];
    char temp[50];

    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%s", words[i]);

    // Bubble sort words by length (ascending)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strlen(words[j]) > strlen(words[j + 1]))
            {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++)
        printf("%s (length: %d)\n", words[i], (int)strlen(words[i]));

    return 0;
}