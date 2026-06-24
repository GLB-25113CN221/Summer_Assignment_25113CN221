#include <stdio.h>
#include <string.h>

int main()
{

    // Q-93 Write a program to check string rotation

    char str1[100], str2[100];

    printf("\nEnter the first string: ");
    scanf("%s", str1);

    printf("\nEnter the second string: ");
    scanf("%s", str2);

    int size1, size2;

    size1 = strlen(str1);
    size2 = strlen(str2);

    if (size1 != size2)
    {
        printf("\nIt is not a string rotation.\n");
        return 0;
    }

    char temp[200];

    strcpy(temp, str1);
    strcat(temp, str1);

    if (strstr(temp, str2))
    {
        printf("\nString rotation!\n");
    }
    else
    {
        printf("\nNot a string rotation!\n");
    }

    return 0;
}
