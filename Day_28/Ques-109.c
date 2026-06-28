#include <stdio.h>
#include <string.h>

#define MAX 100

struct book
{
    int book_id;
    char title[50];
    char author[50];
};

int add_book(struct book books[], int n);
int display_all(struct book books[], int n);
int search_book(struct book books[], int n);
void press_enter();
void Bubble_sort(struct book books[], int num);

int main()
{

    // Q-109 Write a program to create library management system

    int option;  // to store the choice of the user
    int num = 0; // to keep count of number of books

    struct book books[MAX];

    printf("===============================================\n");
    printf("           LIBRARY MANAGEMENT SYSTEM\n");
    printf("===============================================\n\n");

    int (*menu[3])(struct book books[], int) = {add_book, display_all, search_book};

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Add Book\n2. Display All Books\n3. Search Book\n4. Exit\n\n");

        printf("Enter your choice:_");
        scanf("%d", &option);

        if (option >= 1 && option <= 3)
        {
            num = menu[option - 1](books, num);
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

int add_book(struct book books[], int n)
{
    int n_b; // no. of books to add
    printf("\n----- Add Book -----\n\n");

    printf("Enter the number of books to add:_");
    scanf("%d", &n_b);

    if (n_b > MAX - n)
    {
        printf("\nLimit Exceed! Please Try Again!\n");
        press_enter();
        return n;
    }

    for (int i = 0; i < n_b; i++, n++)
    {
        printf("\n---- Book %d ----", i + 1);

        int found = 0; // to find if ID is unique or not

        do
        {
            printf("\nBook ID:_");
            scanf("%d", &books[n].book_id);
            found = 0;
            if (n > 0)
            {

                for (int j = 0; j < n; j++)
                {

                    if (books[n].book_id == books[j].book_id)
                    {
                        printf("\nID already exists. Please Try Again!\n");
                        found = 1;
                    }
                }
            }
        } while (found != 0);

        printf("Title:_");
        getchar();

        fgets(books[n].title, sizeof(books[n].title), stdin);

        // Remove Newline
        int len = strlen(books[n].title);

        if (len > 0 && books[n].title[len - 1] == '\n')
            books[n].title[len - 1] = '\0';

        printf("Author:_");
        fgets(books[n].author, sizeof(books[n].author), stdin);

        len = strlen(books[n].author);
        if (len > 0 && books[n].author[len - 1] == '\n')
            books[n].author[len - 1] = '\0';

        printf("\nBook Added Successfully!\n");
    }

    return n;
}
int display_all(struct book books[], int n)
{
    if (n == 0)
    {
        printf("\nNo book Found! Please Try Again.\n");
        return n;
    }

    printf("\n==============================================================\n");
    printf("                        BOOK LIST\n");
    printf("==============================================================\n");
    printf("ID      | Title                   |Author     \n");
    printf("----------------------------------------------------------------\n");

    Bubble_sort(books, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d", books[i].book_id);

        int digit = 1, temp = books[i].book_id;

        while (temp > 9)
        {
            digit++;
            temp /= 10;
        }

        for (int j = 1; j <= 8 - digit; j++)
        {
            printf(" ");
        }

        printf("| %s", books[i].title);

        digit = strlen(books[i].title);

        for (int j = 1; j <= 24 - digit; j++)
        {
            printf(" ");
        }

        printf("| %s", books[i].author);

        printf("\n");
    }
    printf("----------------------------------------------------------------\n");
    printf("Total Books: %d", n);

    return n;
}

int search_book(struct book books[], int n)
{
    printf("\n----- Search Book -----\n");

    int search;    // to input the id of book need to be searched
    int found = 0; // flag to determine whether found the element or not

    printf("\nEnter the ID of the book to search:_");
    scanf("%d", &search);

    for (int i = 0; i < n; i++)
    {
        if (search == books[i].book_id)
        {
            printf("\nBook Found!\n");
            printf("\nBook ID: %d", books[i].book_id);
            printf("\nTitle: %s", books[i].title);
            printf("\nAuthor: %s", books[i].author);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nSorry, Book Not Found!\n");
    }

    return n;
}

void Bubble_sort(struct book books[], int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            int flag = 0; // flag to tell if the elements should be swapped or not

            if (books[j].book_id > books[j + 1].book_id)
                flag = 1;

            if (flag == 1)
            {
                struct book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}
