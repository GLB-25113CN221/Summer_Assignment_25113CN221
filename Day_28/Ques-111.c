#include <stdio.h>
#include <string.h>

#define MAX 100

// struct variable store info of bank accounts
struct event
{
    int event_id;
    char name[50];  // event name
    char venue[50]; // venue name
    int seat;       // total seat
    int avail;      // available seats
};

// Function Declaration

void press_enter();
int add_event(struct event events[], int n);
int display_event(struct event events[], int n);
int book_ticket(struct event events[], int n);
int cancel_ticket(struct event events[], int n);
void Bubble_sort(struct event events[], int n);

int main()
{

    // Q-111 Write a program to create ticket booking system

    printf("\n=======================================================\n");
    printf("                 | TICKET BOOKING SYSTEM |\n");
    printf("=======================================================\n\n");

    struct event events[MAX];
    int option;  // to store the choice of user to navigate menu
    int num = 0; // to store the number of events
    int (*menu[4])(struct event events[], int num) = {add_event, display_event, book_ticket, cancel_ticket};

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Add Event\n2. Display Events\n3. Book Ticket\n4. Cancel Ticket\n5. Exit");

        printf("\n\nEnter your choice:_");
        scanf("%d", &option);

        if (option >= 1 && option <= 4)
        {
            num = menu[option - 1](events, num);
            press_enter();
        }
        else if (option == 5)
        {
            printf("\nExiting Program! Thank you.\n");
        }
        else
            printf("\nInvalid Input! Please Try Again.");

    } while (option != 5);

    return 0;
}

void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

// Function to add event on the platform
int add_event(struct event events[], int n)
{
    printf("\n----- Add Event -----\n");

    int temp; // no. of accounts to create
    printf("\nEnter the number of events to add:_");
    scanf("%d", &temp);

    if (temp + n > MAX)
    {
        printf("\nLimit Exceed. Please Try Again.\n");
        return n;
    }

    // Input the account info

    for (int i = 0; i < temp; i++, n++)
    {
        printf("\n----- Event %d -----\n", i + 1);
        printf("Event ID: ");
        scanf("%d", &events[n].event_id);
        printf("Event Name: ");
        getchar();
        fgets(events[n].name, sizeof(events[n].name), stdin);

        int len = strlen(events[n].name);
        if (len > 0 && events[n].name[len - 1] == '\n')
            events[n].name[len - 1] = '\0';

        printf("Venue: ");
        fgets(events[n].venue, sizeof(events[n].venue), stdin);

        len = strlen(events[n].venue);
        if (len > 0 && events[n].venue[len - 1] == '\n')
            events[n].venue[len - 1] = '\0';

        printf("Total Seats: ");
        scanf("%d", &events[n].seat);

        events[n].avail = events[n].seat;

        printf("\nEvent added successfully!\n");
    }

    return n;
}
int display_event(struct event events[], int n)
{
    if (n == 0)
    {
        printf("\nNo account Found! Please Try Again.\n");
        return n;
    }

    printf("\n===========================================================================\n");
    printf("                              EVENT LIST\n");
    printf("=============================================================================\n");
    printf("ID     | Name                   | Venue                   | Total  | Available\n");
    printf("------------------------------------------------------------------------------\n");

    Bubble_sort(events, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d", events[i].event_id);

        int digit = 1, temp = events[i].event_id;

        while (temp > 9)
        {
            digit++;
            temp /= 10;
        }

        for (int j = 1; j <= 7 - digit; j++)
        {
            printf(" ");
        }

        printf("| %s", events[i].name);

        digit = strlen(events[i].name);

        for (int j = 1; j <= 23 - digit; j++)
        {
            printf(" ");
        }

        printf("| %s", events[i].venue);

        digit = strlen(events[i].venue);

        for (int j = 1; j <= 24 - digit; j++)
        {
            printf(" ");
        }

        printf("| %d", events[i].seat);

        digit = 1, temp = events[i].seat;

        while (temp > 9)
        {
            digit++;
            temp /= 10;
        }

        for (int j = 1; j <= 7 - digit; j++)
        {
            printf(" ");
        }

        printf("| %d", events[i].avail);
        printf("\n");
    }
    printf("------------------------------------------------------------------------------\n");

    return n;
}

// Function to book ticket
int book_ticket(struct event events[], int n)
{
    printf("\n----- BOOK TICKET -----\n");

    int id;        // to enter the event id to book ticket
    int num;       // number of seats to book in the event
    int found = 0; // to determine if event found or not

    printf("\nEnter Event ID:");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (id == events[i].event_id)
        {
            if (events[i].avail == 0)
            {
                printf("\nTicket not available in this event.\n");
                return n;
            }
            printf("Enter the number of tickets: ");
            scanf("%d", &num);

            if (events[i].avail - num < 0)
            {
                printf("\n%d tickets not available for this event.\n", num);
                return n;
            }
            events[i].avail -= num;
            printf("\n%d tickets booked successfully!\n", num);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEvent Not Found!\n");
    }
    return n;
}
int cancel_ticket(struct event events[], int n)
{
    int id;        // to enter the event id to cancel ticket
    int num;       // number of seats to cancel in the event
    int found = 0; // to determine if event found or not

    printf("\nEnter Event ID:");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (id == events[i].event_id)
        {
            printf("Enter the number of tickets: ");
            scanf("%d", &num);

            if (events[i].avail + num > events[i].seat)
            {
                printf("\n%d tickets can not be cancelled in this event.\n", num);
                return n;
            }
            events[i].avail += num;
            printf("\n%d tickets cancelled successfully!\n", num);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEvent Not Found!\n");
    }
    return n;
}
void Bubble_sort(struct event events[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            int flag = 0; // flag to tell if the elements should be swapped or not

            if (events[j].event_id > events[j + 1].event_id)
                flag = 1;

            if (flag == 1)
            {
                struct event temp = events[j];
                events[j] = events[j + 1];
                events[j + 1] = temp;
            }
        }
    }
}
