#include <stdio.h>
#include <string.h>

#define MAX 100

struct contact
{
    char name[50];
    long int phone;
    char email[50];
};

void press_enter();
int add_contact(struct contact contacts[], int n);
int display_all(struct contact contacts[], int n);
int search_contact(struct contact contacts[], int n);

int main()
{

    // Q-112 Write a program to create contact management system

    int option;  // to store the choice of the user
    int num = 0; // to keep count of number of contacts

    struct contact contacts[MAX];

    printf("===============================================\n");
    printf("           CONTACT MANAGEMENT SYSTEM\n");
    printf("===============================================\n\n");

    int (*menu[3])(struct contact contacts[], int) = {add_contact, display_all, search_contact};

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Add Contact\n2. Display All Contacts\n3. Search Contact\n4. Exit\n\n");

        printf("Enter your choice:_");
        scanf("%d", &option);

        if (option >= 1 && option <= 3)
        {
            num = menu[option - 1](contacts, num);
            press_enter();
        }
        else if (option == 4)
        {
            printf("\nExiting Program. Goodbye!\n\n");
            break;
        }
        else
        {
            printf("\nInvalid Input. Please Try Again.\n\n");
            press_enter();
        }
    } while (option != 4);
}

void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

int add_contact(struct contact contacts[], int n)
{
    int n_b; // no. of contacts to add
    printf("\n----- Add Contact -----\n\n");

    printf("Enter the number of contacts to add:_");
    scanf("%d", &n_b);

    if (n_b > MAX - n)
    {
        printf("\nLimit Exceed! Please Try Again!\n");
        press_enter();
        return n;
    }

    for (int i = 0; i < n_b; i++, n++)
    {
        printf("\n---- Contact %d ----", i + 1);

        int found = 0; // to find if ID is unique or not

        do
        {
            printf("\nPhone Number:_");
            scanf("%ld", &contacts[n].phone);
            found = 0;
            if (n > 0)
            {

                for (int j = 0; j < n; j++)
                {

                    if (contacts[n].phone == contacts[j].phone)
                    {
                        printf("\nPhone Number already exists. Please Try Again!\n");
                        found = 1;
                    }
                }
            }
        } while (found != 0);

        printf("Name:_");
        getchar();

        fgets(contacts[n].name, sizeof(contacts[n].name), stdin);

        // Remove Newline
        int len = strlen(contacts[n].name);

        if (len > 0 && contacts[n].name[len - 1] == '\n')
            contacts[n].name[len - 1] = '\0';

        printf("Email:_");
        scanf("%s", contacts[n].email);

        printf("\nContact Added Successfully!\n");
    }

    return n;
}
int display_all(struct contact contacts[], int n)
{
    if (n == 0)
    {
        printf("\nNo contact Found! Please Try Again.\n");
        return n;
    }

    printf("\n==============================================================\n");
    printf("                      CONTACT LIST\n");
    printf("==============================================================\n");
    printf("Name                   | Phone      |\n");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {

        printf("%s", contacts[i].name);

        int digit = strlen(contacts[i].name);

        for (int j = 1; j <= 24 - digit; j++)
        {
            printf(" ");
        }

        printf("| %ld | %s", contacts[i].phone, contacts[i].email);

        printf("\n");
    }
    printf("----------------------------------------------------------------\n");
    printf("Total Contacts: %d", n);

    return n;
}

int search_contact(struct contact contacts[], int n)
{
    printf("\n----- Search Contact -----\n");

    int search;    // to input the phone no. need to be searched
    int found = 0; // flag to determine whether found the contact or not

    printf("\nEnter the phone Number of the contact:_");
    scanf("%d", &search);

    for (int i = 0; i < n; i++)
    {
        if (search == contacts[i].phone)
        {
            printf("\nContact Found!\n");
            printf("\nPhone Number: %ld", contacts[i].phone);
            printf("\nName: %s", contacts[i].name);
            printf("\nEmail: %s", contacts[i].email);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nSorry, Contact Not Found!\n");
    }

    return n;
}
