#include <stdio.h>
#include <string.h>

#define MAX 100

struct book
{
    int id;
    char title[50];
    char author[50];
    int qty;
};

struct book books[MAX];
int count = 0;

void add_book();
void display_books();
void search_book();
void issue_book();
void return_book();
void press_enter();

int main()
{
    int choice;
    void (*menu[5])() = {add_book, display_books, search_book, issue_book, return_book};

    printf("\n========================================\n");
    printf("        MINI LIBRARY SYSTEM\n");
    printf("========================================\n");

    do
    {
        printf("\n1. Add Book\n2. Display Books\n3. Search Book\n4. Issue Book\n5. Return Book\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5)
        {
            menu[choice - 1]();
            press_enter();
        }
        else if (choice == 6)
            printf("\nExiting... Goodbye!\n");
        else
            printf("\nInvalid choice!\n");

    } while (choice != 6);

    return 0;
}

void add_book()
{
    if (count >= MAX)
    {
        printf("\nLibrary is full!\n");
        return;
    }

    int n;
    printf("\nEnter number of books to add: ");
    scanf("%d", &n);

    for (int i = 0; i < n && count < MAX; i++, count++)
    {
        printf("\nBook %d:\n", count + 1);
        printf("ID: ");
        scanf("%d", &books[count].id);

        for (int j = 0; j < count; j++)
        {
            if (books[j].id == books[count].id)
            {
                printf("\nID already exists!\n");
                count--;
                return;
            }
        }

        printf("Title: ");
        getchar();
        fgets(books[count].title, 50, stdin);
        books[count].title[strcspn(books[count].title, "\n")] = '\0';

        printf("Author: ");
        fgets(books[count].author, 50, stdin);
        books[count].author[strcspn(books[count].author, "\n")] = '\0';

        printf("Quantity: ");
        scanf("%d", &books[count].qty);

        printf("\nBook added!\n");
    }
}

void display_books()
{
    if (count == 0)
    {
        printf("\nNo books available!\n");
        return;
    }

    printf("\n========================================\n");
    printf("              BOOK LIST\n");
    printf("========================================\n");
    printf("ID  | Title                | Author           | Qty\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-4d| %-20s | %-15s | %d\n",
               books[i].id, books[i].title, books[i].author, books[i].qty);
    }
    printf("----------------------------------------\n");
    printf("Total Books: %d\n", count);
}

void search_book()
{
    if (count == 0)
    {
        printf("\nNo books available!\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (books[i].id == id)
        {
            printf("\nBook Found!\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Quantity: %d\n", books[i].qty);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nBook not found!\n");
}

void issue_book()
{
    if (count == 0)
    {
        printf("\nNo books available!\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].qty > 0)
            {
                books[i].qty--;
                printf("\nBook issued successfully!\n");
                printf("Remaining copies: %d\n", books[i].qty);
            }
            else
                printf("\nBook out of stock!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nBook not found!\n");
}

void return_book()
{
    if (count == 0)
    {
        printf("\nNo books available!\n");
        return;
    }

    int id, found = 0;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (books[i].id == id)
        {
            books[i].qty++;
            printf("\nBook returned successfully!\n");
            printf("Total copies: %d\n", books[i].qty);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nBook not found!\n");
}

void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}