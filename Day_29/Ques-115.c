#include <stdio.h>
#include <string.h>

#define MAX 100

char str[MAX];
int len = 0;

void input_str(char *str);
void display_str(char *str);
void find_length(char *str);
void reverse_str(char *str);
void press_enter();

int main()
{
    int choice;

    void (*menu[5])(char *str) = {input_str, display_str, find_length, reverse_str};

    do
    {
        printf("\n================================\n");
        printf("     STRING OPERATIONS SYSTEM\n");
        printf("================================\n");
        printf("1. Input String\n2. Display String\n3. Find Length\n4. Reverse String\n5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4)
        {
            menu[choice - 1](str);
            press_enter();
        }
        else if (choice == 5)
        {
            printf("\nExiting Program. GoodBye!\n");
        }
        else
            printf("\nInvalid Input. Please Try Again\n");

    } while (choice != 5);

    return 0;
}

void input_str(char *str)
{
    printf("\n---- Input String -----\n");

    printf("\nEnter a string: ");
    getchar();
    fgets(str, MAX, stdin);

    len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';

    len = strlen(str);

    printf("\nString entered successfully!\n");
}

void display_str(char *str)
{
    if (len == 0)
    {
        printf("\nString is empty! Please input first.\n");
        return;
    }
    printf("\nString: %s\n", str);
}

void find_length(char *str)
{
    if (len == 0)
    {
        printf("\nString is empty! Please input first.\n");
        return;
    }
    printf("\nLength of string: %d\n", len);
}

void reverse_str(char *str)
{
    if (len == 0)
    {
        printf("\nString is empty! Please input first.\n");
        return;
    }

    printf("\nOriginal string: %s\n", str);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    printf("Reversed string: %s\n", str);
}

void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}