#include <stdio.h>
#include <string.h>

#define MAX 100

struct item
{
    int id;
    char name[50];
    int qty;
    float price;
};

// global variable declaration
struct item items[MAX];
int count = 0; // to keep track of number of items

// Function declaration
void add_item();
void display_items();
void search_item();
void press_enter();

int main()
{
    int choice;
    void (*menu[3])() = {add_item, display_items, search_item};

    do
    {
        printf("\n================================\n");
        printf("     INVENTORY MANAGEMENT SYSTEM\n");
        printf("================================\n");
        printf("1. Add Item\n2. Display All Items\n3. Search Item\n4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3)
        {
            menu[choice - 1]();
            press_enter();
        }
        else if (choice == 4)
        {
            printf("\nExiting Program. GoodBye!\n");
        }
        else
            printf("\nInvalid Input. Please Try Again\n");

    } while (choice != 4);

    return 0;
}

void add_item()
{
    printf("\n----- Add Item -----\n");

    int num; // add number of items to add

    printf("\nEnter the number of items to add: ");
    scanf("%d", &num);

    if (count + num >= MAX)
    {
        printf("\nLimit Exceed! Cannot add %d items.\n", num);
        return;
    }

    for (int i = 0; i < num; i++, count++)
    {

        printf("\n---- Item %d ----\n");

        printf("\nItem ID: ");
        scanf("%d", &items[count].id);

        // Check if ID already exists
        for (int i = 0; i < count; i++)
        {
            if (items[i].id == items[count].id)
            {
                printf("\nID already exists! Please try again.\n");
                return;
            }
        }

        printf("Item Name: ");
        getchar();
        fgets(items[count].name, 50, stdin);

        int len = strlen(items[count].name);
        if (len > 0 && items[count].name[len - 1] == '\n')
            items[count].name[len - 1] = '\0';

        printf("Quantity: ");
        scanf("%d", &items[count].qty);

        printf("Price: ");
        scanf("%f", &items[count].price);

        printf("\nItem added successfully!\n");
    }
}

void display_items()
{
    if (count == 0)
    {
        printf("\nNo items found!\n");
        return;
    }

    printf("\n========================================================\n");
    printf("                    ITEM LIST\n");
    printf("========================================================\n");
    printf("ID    | Name                  | Qty    | Price\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-6d| %-21s | %-6d | %.2f\n", items[i].id, items[i].name, items[i].qty, items[i].price);
    }

    printf("--------------------------------------------------------\n");
    printf("Total Items: %d\n", count);
}

void search_item()
{
    if (count == 0)
    {
        printf("\nNo items found!\n");
        return;
    }

    int id, found = 0;

    printf("\nEnter Item ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (items[i].id == id)
        {
            printf("\nItem Found!\n");
            printf("ID: %d\n", items[i].id);
            printf("Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].qty);
            printf("Price: %.2f\n", items[i].price);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nItem with ID %d not found!\n", id);
}

void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}