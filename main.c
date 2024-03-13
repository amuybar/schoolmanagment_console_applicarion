#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "course.h"

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    struct Course courses[MAX_COURSES];
    int numCourses = 0;

    int choice;
    int id;

    while (1) {
        printf("\n1. Student Management\n");
        printf("2. Course Management\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                studentManagement(students, &numStudents); // Assuming this function exists in student.c
                break;
            case 2:
                courseManagement(students, numStudents, courses, &numCourses); // Assuming this function exists in course.c
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
