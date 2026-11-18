#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define SEMESTERS 8

typedef struct
{
    long long sapId;
    int rollNo;
    char name[50];
    char phone[20];
    char email[60];
    int year;
    int semester;
    float sgpa[SEMESTERS];
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

int main()
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf(" STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("========================================\n");

        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Delete Student\n");
        printf("5. Display CGPA\n");
        printf("6. Year-wise Average CGPA\n");
        printf("7. Sort by SAP ID\n");
        printf("8. Sort by Name\n");
        printf("9. AI-Assisted Academic Advisor\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("\nProgram closed successfully.\n");
        }
        else
        {
            printf("\nFeature will be implemented in next commits.\n");
        }

    } while (choice != 0);

    return 0;
}