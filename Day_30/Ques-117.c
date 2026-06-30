#include <stdio.h>
#include <string.h>

#define MAX 100

// global variables

int roll_no[MAX];
int class[MAX];
char sec[MAX];
float percentage[MAX];
char name[MAX][50];
char grade[MAX];
float sub_marks[MAX][5];
int num = 0; // to keep the track of number of students

// Function declaration

void add_std();
void display_all();
void search_std();
void update_std();
void delete_std();
void std_stat();
void press_enter();
void bubble_sort(int *arr);
void grad_per(int num);
void display_student(int index);

int main()
{

    // Q-117 Write a program to Create student record system using arrays and strings.

    int option; // to store the choice of the user
    void (*menu[6])() = {add_std, display_all, search_std, update_std, delete_std, std_stat};

    do
    {
        printf("\n=================================================\n");
        printf("               STUDENT RECORD SYSTEM");
        printf("\n=================================================\n");

        printf("\n1. Add Student\n2. Display All Student\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Student Statistics\n7. Exit\n");

        printf("\nEnter your choice:_");
        scanf("%d", &option);

        if (option >= 1 && option <= 6)
        {
            menu[option - 1]();
            press_enter();
        }

        else if (option == 7)
        {
            printf("\nExiting Program! Good Bye.\n");
        }

        else
            printf("\nInvalid Input. Please Try Again.\n");

    } while (option != 7);

    return 0;
}

// Function definition

// function to add student
void add_std()
{

    printf("\n--- Add Student ---\n\n");

    int temp; // no of students the user needs to add

    printf("Enter the number of students to add:_");
    scanf("%d", &temp);

    if (temp + num > MAX)
    {
        printf("\nLimit Exceed. No more than %d students can be added.\n", MAX - num);
        return;
    }

    if (temp < 0)
    {
        printf("\nInvalid Input. Please Input a positive number.\n");
        return;
    }

    for (int j = 0; j < temp; j++)
    {

        printf("\nEnter the details of student %d.", j + 1);

        int found = 0; // to check if the roll number already exists or not

        do
        {
            found = 0;

            printf("Roll Number: ");
            scanf("%d", &roll_no[num]);

            for (int i = 0; i < num; i++)
            {
                if (roll_no[num] == roll_no[i])
                {
                    printf("\nRoll Number already exists. Please Try Again.\n");
                    found = 1;
                }
            }
        } while (found == 0);

        printf("\nName: ");
        getchar();
        fgets(name[num], sizeof(name[num]), stdin);

        int len = strlen(name[num]);

        if (len > 0 && name[num][len - 1] == '\n')
            name[num][len - 1] = '\0';

        printf("Class: ");
        scanf("%d", &class[num]);

        printf("Section: ");
        scanf(" %c", &sec[num]);

        printf("Enter the marks of 5 subjects out of 100: ");
        for (int i = 0; i < 5; i++)
        {
            scanf("%f", &sub_marks[num][i]);
        }

        grad_per(num);

        num++;
    }

    printf("\n%d students added successfully!\n", temp);
    return;
}

// function to all the students in the record

void display_all()
{
    printf("\n==============================================================================================\n");
    printf("                                  STUDENT LIST\n");
    printf("================================================================================================\n");
    printf("\nRoll no. | Name                  | Class  | Sec | Marks (5 Subjects)  | Percentage | Grade\n");
    printf("------------------------------------------------------------------------------------------------\n");

    int sort_roll[MAX]; // string to store roll number for sorting

    for (int i = 0; i < num; i++)
    {
        sort_roll[i] = roll_no[i];
    }

    bubble_sort(sort_roll);

    for (int i = 0; i < num; i++)
    {
        int index;

        for (int j = 0; j < num; j++)
        {
            if (sort_roll[i] == roll_no[j])
            {
                index = j;
                break;
            }
        }

        printf("%9d| %22s| %6d | %c |", roll_no[index], name[index], class[index], sec[index]);

        for (int j = 0; j < 5; j++)
        {
            printf(" %.1f", sub_marks[index][j]);
        }

        printf(" | %.2f       | %c\n", percentage[index], grade[index]);
    }

    printf("------------------------------------------------------------------------------------------------\n");

    printf("Total Students: %d\n", num);
}

// function to search students by roll number
void search_std()
{
    printf("\n----- Search Student -----\n");

    int search;    // roll_number to search
    int found = 0; // to determine if found the student or not

    printf("\nEnter the roll number to search: ");
    scanf("%d", &search);

    if (search < 0)
    {
        printf("\nInvalid Input. Please Enter a positive number.\n");
        return;
    }

    for (int i = 0; i < num; i++)
    {
        if (search == roll_no[i])
        {
            found = 1;
            printf("\nFound Student at %d index.\n");
            display_student(i);
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found in the record.\n");
    }

    return;
}

// function to update the info of any student

void update_std()
{
    printf("\n----- Update Student -----\n");

    int update;    // roll number of the student to update info
    int found = 0; // to determine if found the student for not

    printf("\nEnter the roll number: ");
    scanf("%d", &update);

    if (update < 0)
    {
        printf("\nInvalid Input. Please Enter a positive number.\n");
        return;
    }

    for (int i = 0; i < num; i++)
    {
        if (update == roll_no[i])
        {
            found = 1;
            printf("\nFound Student at %d index.\n");
            display_student(i);

            printf("\nEnter the updated info: ");
            int found1 = 0; // to check if the roll number already exists or not

            do
            {
                found1 = 0;

                printf("Roll Number: ");
                scanf("%d", &roll_no[i]);

                for (int j = 0; j < num; j++)
                {
                    if (roll_no[i] == roll_no[j] && j != i)
                    {
                        printf("\nRoll Number already exists. Please Try Again.\n");
                        found1 = 1;
                    }
                }
            } while (found1 == 0);

            printf("\nName: ");
            getchar();
            fgets(name[i], sizeof(name[i]), stdin);

            int len = strlen(name[i]);

            if (len > 0 && name[i][len - 1] == '\n')
                name[i][len - 1] = '\0';

            printf("Class: ");
            scanf("%d", &class[i]);

            printf("Section: ");
            scanf(" %c", &sec[i]);

            printf("Enter the marks of 5 subjects out of 100: ");
            for (int k = 0; k < 5; k++)
            {
                scanf("%f", &sub_marks[i][k]);
            }

            grad_per(i);

            printf("\nInfo Updated successfully.\n");
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}

// function to delete a student form record
void delete_std()
{
    printf("\n----- Delete Student -----\n");

    int delete;    // roll number of the student to delete
    int found = 0; // to determine whether found the student or not

    printf("\nEnter the roll number:");
    scanf("%d", &delete);

    if (delete < 0)
    {
        printf("\nInvalid Input. Please Enter a positive number.\n");
        return;
    }

    for (int i = 0; i < num; i++)
    {
        if (delete == roll_no[i])
        {
            found = 1;

            printf("\nStudent Found at %d position.\nAre you sure you want to delete %d roll number? (y/n):_");

            char y_n; // to store the choice for deleting

            scanf(" %c", &y_n);

            if (y_n == 'y' || y_n == 'Y')
            {
                for (int j = i; j < num - 1; j++)
                {

                    roll_no[j] = roll_no[j + 1];
                    strcpy(name[j], name[j + 1]);
                    class[j] = class[j + 1];
                    sec[j] = sec[j + 1];

                    for (int k = 0; k < 5; k++)
                    {
                        sub_marks[j][k] = sub_marks[j + 1][k];
                    }

                    percentage[j] = percentage[j + 1];
                    grade[j] = grade[j + 1];
                }
                printf("\nStudent deleted successfully from the record.\n");
                num--;
            }
            else
            {
                printf("\nDeletion Cancelled.\n");
                break;
            }
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent Not Found.\n");
    }

    return;
}

// function to display student statistics
void std_stat()
{
    printf("\n----- Student Statistics -----\n");
    printf("\nTotal number of students = %d", num);

    float avg_prct, sum = 0;

    for (int i = 0; i < num; i++)
    {
        sum += percentage[i];
    }

    avg_prct = sum / num;

    printf("\nAverage class percentage = %.2f", avg_prct);

    return;
}

// function to add the enter feature for continuation

void press_enter()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

// function to sort the array in order of roll number

void bubble_sort(int *arr)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap roll number
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// function to calculate percentage and grade

void grad_per(int index)
{

    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += sub_marks[index][i];
    }

    percentage[index] = (sum * 100.0) / (5 * 100);

    if (percentage <= 100 && percentage >= 90)
    {
        grade[index] = 'A';
    }
    else if (percentage < 90 && percentage >= 80)
    {
        grade[index] = 'B';
    }
    else if (percentage < 80 && percentage >= 60)
    {
        grade[index] = 'C';
    }
    else if (percentage < 60 && percentage >= 30)
    {
        grade[index] = 'D';
    }
    else
        grade[index] = 'F';
}

// function to display students
void display_student(int index)
{

    printf("Name: %s\n", name[index]);
    printf("Roll Number: %d\n", roll_no[index]);
    printf("Class: %d\n", class[index]);
    printf("Section: %c\n", sec[index]);
    printf("Marks: ");
    for (int j = 0; j < 5; j++)
    {
        printf("%.1f ", sub_marks[index][j]);
    }
    printf("\nPercentage: %.2f", percentage[index]);
    printf("\nGrade: %c", grade[index]);
}