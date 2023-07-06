#include <stdio.h>
#include <string.h>
#include "./student.h"

#define Max_Students 117
#define Max_Attendance 117

struct student students[Max_Students];
struct Attendance attendance[Max_Attendance];
int studentCount = 1;
int attendanceCount = 1;

int main()
{
    int choice;
    int rollNo, day, month, year, status;
    char name[50];
    int startDay, startMonth, startyear;

    while (1)
    {
        printf("\n*** Student Attendendance Portal ***\n");
        printf("[1] Add Student\n");
        printf("[2] Add Attendance\n");
        printf("[3] Check Attendance by Date\n");
        printf("[4] Check Weekly Attendance\n");
        printf("[5] Added Student List\n");
        printf("[6] Update Attendance\n");
        printf("[7] Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter Roll Number: ");
            scanf("%d", &rollNo);
            printf("Enter Name: ");
            scanf(" %[^\n]", name);
            addStudent(rollNo, name);
            break;
        case 2:
            printf("Enter Date (dd mm yyyy): ");
            scanf("%d %d %d", &day, &month, &year);
            int dayCount = 1;

          while (dayCount <8)
          {
              for (int i = 1; i < studentCount; i++)
            {
                printf("Enter 1 for Present & 0 for Absent: ");
                status = getIntegerInput();
                if (status != 0 && status != 1)
                {
                    printf("\n\t\t\tInvalid status. Please enter 1 for Present or 0 for Absent.\n");
                    break;
                }

                addAttendance(students[i].rollNo, day, month, year, status);
            }
            day++;
            dayCount++;
          }
          

            break;
        case 3:
            printf("Enter Roll Number: ");
            rollNo = getIntegerInput();
            if (rollNo == -1)
            {
                printf("\n\t\t\t*** Invalid Input For Roll Number ***\n");
            }

            printf("Enter Date (dd mm yyyy): ");
            scanf("%d %d %d", &day, &month, &year);
            checkAttendanceByDate(rollNo, day, month, year);
            break;

        case 4:
            printf("Enter Roll Number: ");
            rollNo = getIntegerInput();
            if (rollNo == -1)
            {
                printf("\n\t\t\t*** Invalid Input For Roll Number ***\n");
                break;
            }
            printf("Enter Date (dd mm yyyy): ");
            scanf("%d %d %d", &startDay, &startMonth, &startyear);
            checkWeeklyAttendance(rollNo, startDay, startMonth, startyear);
            break;
        case 5:
            addStudentList(studentCount);
            break;

        case 6:
            printf("Enter Roll Number: ");
            rollNo = getIntegerInput();
            if (rollNo == -1)
            {
                printf("\n\t\t\t*** Invalid Input For Roll Number ***\n");
            }
            printf("Enter Date (dd mm yyyy): ");
            scanf("%d %d %d", &day, &month, &year);
            printf("Enter 1 for present 0 for Absent: ");
            status = getIntegerInput();
            if (status == -1)
            {
                printf("\n\t\t\t *** Invalid Input for Attendance ***\n");
                break;
            }

            updateAttendance(rollNo, day, month, year, status);
            break;

        case 7:
            return 0;
            break;

        default:
            printf("Selected Option is Invalid!");
            break;
        }
    }
}
