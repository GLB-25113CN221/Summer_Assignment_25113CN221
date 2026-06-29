#include <stdio.h>

#define MAX 100

// Function declaration

int create_arr(int arr[], int n);
int display_arr(int arr[], int n);
int insert_arr(int arr[], int n);
int delete_arr(int arr[], int n);
int search_element(int arr[], int n);
int update_element(int arr[], int n);
void press_enter();

int main()
{

    // Q-114 Write a program to Create menu-driven array operations system.

    int option; // to store the choice of the user
    int arr[MAX];
    int index = 0; // keep track of number of elements in the array

    int (*menu[6])(int arr[], int n) = {create_arr, display_arr, insert_arr, delete_arr, search_element, update_element};

    do
    {
        printf("\n===================================\n");
        printf("*      ARRAY OPERATION SYSTEM       *\n");
        printf("===================================\n\n");

        printf("1. Create Array\n2. Display Array\n3. Insert Array\n4. Delete Element\n5. Search Element\n6. Update Element\n7. Exit\n");
        printf("\n===================================\n");

        printf("Enter choice:_");
        scanf("%d", &option);

        if (option >= 1 && option <= 6)
        {
            index = menu[option - 1](arr, index);
            press_enter();
        }
        else if (option == 7)
        {
            printf("\nExiting Program. Goodbye!\n");
        }
        else
            printf("\nInvalid Input. Please Try Again.\n");
    } while (option != 7);

    return 0;
}

int create_arr(int arr[], int n)
{
    printf("\n----- Create Array -----\n");

    printf("\nEnter size of array: ");
    scanf("%d", &n);

    if (n > MAX || n <= 0)
    {
        printf("\nExceed Limit. Please Try Again.\n");
        return 0;
    }
    printf("\nEnter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array created successfully with %d elements.", n);

    return n;
}

int display_arr(int arr[], int n)
{
    printf("\n---- Display Array -----\n");

    if (n == 0)
    {
        printf("\nArray is empty.\n");
        return n;
    }

    printf("\nArray Elements : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return n;
}

int insert_arr(int arr[], int n)
{
    printf("\n----- Insert Element ------\n");

    if (n == 0)
    {
        printf("\nArray is empty.\n");
        return n;
    }

    int place; // index to input the element

    printf("Enter the position to insert the element (1 to %d): ", n);
    scanf("%d", &place);

    if (place < 1 || place > n + 1)
    {
        printf("\nInvalid Position.\n");
        return n;
    }

    int element; // element to input

    printf("Enter the element to insert at position %d: ", place);
    scanf("%d", &element);

    for (int i = n; i >= place; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[place - 1] = element;

    printf("\nElement inserted successfully at %d position.\n", place);

    return n + 1;
}

int delete_arr(int arr[], int n)
{
    printf("\n----- Delete Element ------\n");

    if (n == 0)
    {
        printf("\nArray is empty.\n");
        return n;
    }

    int place; // index to delete the element

    printf("Enter the position of the element to delete (1 to %d): ", n);
    scanf("%d", &place);

    if (place < 1 || place > n)
    {
        printf("\nInvalid Position.\n");
        return n;
    }

    for (int i = place - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    printf("\nElement deleted successfully from %d position.\n", place);

    return n - 1;
}

int search_element(int arr[], int n)
{
    printf("\n----- Search Element -----\n");

    if (n == 0)
    {
        printf("\nArray is empty.\n");
        return n;
    }

    int search;    // element to search
    int found = 0; // to determine if found the element or not

    printf("\nEnter the element: ");
    scanf("%d", &search);

    for (int i = 0; i < n; i++)
    {
        if (search == arr[i])
        {
            printf("\nElement found at %d index.\n", i);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\n%d not found.\n", search);
    }

    return n;
}

int update_element(int arr[], int n)
{
    printf("\n----- Update Element -----\n");

    if (n == 0)
    {
        printf("\nArray is empty.\n");
        return n;
    }

    int place; // index to replace value of

    printf("\nEnter the position to replace element (1 to %d): ", n);
    scanf("%d", &place);

    if (place < 1 || place > n)
    {
        printf("\nInvalid Position.\n");
        return n;
    }

    printf("\nEnter the new value: ");
    scanf("%d", &arr[place - 1]);

    printf("\nArray Updated Successfully!\n");

    return n;
}

void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}
