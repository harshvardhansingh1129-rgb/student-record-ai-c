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

void clearBuffer()
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void readLine(char text[], int size)
{
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

void addStudent()
{
    if (studentCount >= MAX_STUDENTS)
    {
        printf("\nStudent storage is full.\n");
        return;
    }

    Student *s = &students[studentCount];

    printf("\nEnter SAP ID: ");
    scanf("%lld", &s->sapId);

    printf("Enter Roll No.: ");
    scanf("%d", &s->rollNo);

    clearBuffer();

    printf("Enter Name: ");
    readLine(s->name, sizeof(s->name));

    printf("Enter Phone No.: ");
    readLine(s->phone, sizeof(s->phone));

    printf("Enter Email ID: ");
    readLine(s->email, sizeof(s->email));

    printf("Enter Year (1-4): ");
    scanf("%d", &s->year);

    printf("Enter Current Semester (1-8): ");
    scanf("%d", &s->semester);

    for (int i = 0; i < SEMESTERS; i++)
    {
        s->sgpa[i] = 0;
    }

    for (int i = 0; i < s->semester && i < 8; i++)
    {
        printf("Enter SGPA for Semester %d: ", i + 1);
        scanf("%f", &s->sgpa[i]);
    }

    studentCount++;

    printf("\nStudent added successfully.\n");
}

void displayStudent(Student *s)
{
    printf("\n-----------------------------------\n");
    printf("SAP ID      : %lld\n", s->sapId);
    printf("Roll No.    : %d\n", s->rollNo);
    printf("Name        : %s\n", s->name);
    printf("Phone       : %s\n", s->phone);
    printf("Email       : %s\n", s->email);
    printf("Year        : %d\n", s->year);
    printf("Semester    : %d\n", s->semester);

    printf("SGPA        : ");

    for (int i = 0; i < SEMESTERS; i++)
    {
        if (s->sgpa[i] > 0)
        {
            printf("%.2f ", s->sgpa[i]);
        }
    }

    printf("\n-----------------------------------\n");
}

void searchStudent()
{
    long long id;

    printf("\nEnter SAP ID to search: ");
    scanf("%lld", &id);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].sapId == id)
        {
            printf("\nStudent found.\n");
            displayStudent(&students[i]);
            return;
        }
    }

    printf("\nStudent not found.\n");
}

void displayAllStudents()
{
    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++)
    {
        displayStudent(&students[i]);
    }
}

void deleteStudent()
{
    long long id;

    printf("\nEnter SAP ID to delete: ");
    scanf("%lld", &id);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].sapId == id)
        {
            for (int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }

            studentCount--;

            printf("\nStudent deleted successfully.\n");
            return;
        }
    }

    printf("\nStudent not found.\n");
}
float calculateCGPA(Student *s)
{
    float total = 0;
    int count = 0;

    for (int i = 0; i < SEMESTERS; i++)
    {
        if (s->sgpa[i] > 0)
        {
            total = total + s->sgpa[i];
            count++;
        }
    }

    if (count == 0)
        return 0;

    return total / count;
}
void displayCGPA()
{
    if (studentCount == 0)
    {
        printf("\nNo students available.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++)
    {
        printf("\nSAP ID: %lld", students[i].sapId);
        printf("\nName: %s", students[i].name);
        printf("\nCGPA: %.2f\n", calculateCGPA(&students[i]));
    }
}
void yearWiseAverage()
{
    for (int year = 1; year <= 4; year++)
    {
        float total = 0;
        int count = 0;

        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].year == year)
            {
                total += calculateCGPA(&students[i]);
                count++;
            }
        }

        if (count > 0)
        {
            printf("\nYear %d Average CGPA = %.2f",
                   year, total / count);
        }
        else
        {
            printf("\nYear %d: No students", year);
        }
    }

    printf("\n");
}
void sortBySAP()
{
    Student temp[MAX_STUDENTS];

    for (int i = 0; i < studentCount; i++)
    {
        temp[i] = students[i];
    }

    for (int i = 0; i < studentCount - 1; i++)
    {
        for (int j = 0; j < studentCount - i - 1; j++)
        {
            if (temp[j].sapId > temp[j + 1].sapId)
            {
                Student t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    printf("\nStudents sorted by SAP ID:\n");

    for (int i = 0; i < studentCount; i++)
    {
        displayStudent(&temp[i]);
    }
}
void sortByName()
{
    Student temp[MAX_STUDENTS];

    for (int i = 0; i < studentCount; i++)
    {
        temp[i] = students[i];
    }

    for (int i = 0; i < studentCount - 1; i++)
    {
        for (int j = 0; j < studentCount - i - 1; j++)
        {
            if (strcmp(temp[j].name, temp[j + 1].name) > 0)
            {
                Student t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    printf("\nStudents sorted by Name:\n");

    for (int i = 0; i < studentCount; i++)
    {
        displayStudent(&temp[i]);
    }
}
int main()
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf(" STUDENT RECORD & RESULT MANAGEMENT\n");
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

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            searchStudent();
            break;

        case 3:
            displayAllStudents();
            break;

        case 4:
            deleteStudent();
            break;
            case 5:
    displayCGPA();
    break;

case 6:
    yearWiseAverage();
    break;

case 7:
    sortBySAP();
    break;

case 8:
    sortByName();
    break;

        case 0:
            printf("\nProgram closed.\n");
            break;

        default:
            printf("\nThis feature will be added in next commit.\n");
        }

    } while (choice != 0);

    return 0;
}