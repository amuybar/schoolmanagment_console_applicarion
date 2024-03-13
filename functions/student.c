#include <stdio.h>
#include "student.h"

void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        printf("Database is full. Cannot add more students.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &students[*numStudents].id);
    printf("Enter student name: ");
    scanf("%s", students[*numStudents].name);
    printf("Enter student age: ");
    scanf("%d", &students[*numStudents].age);

    (*numStudents)++;
    printf("Student added successfully.\n");
}

// Function to display all students
void displayStudents(struct Student students[], int numStudents) {
    if (numStudents == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("Student Information:\n");
    printf("ID\tName\tAge\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s\t%d\n", students[i].id, students[i].name, students[i].age);
    }
}
// Function to search for a student by ID
void searchStudent(struct Student students[], int numStudents, int id) {
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            printf("Student found:\n");
            printf("ID\tName\tAge\n");
            printf("%d\t%s\t%d\n", students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void studentManagement(struct Student students[], int *numStudents) {
    int choice;
    int studentId;

    while (1) {
        printf("\nStudent Management:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, numStudents);
                break;
            case 2:
                displayStudents(students, *numStudents);
                break;
            case 3:
                printf("Enter student ID to search: ");
                scanf("%d", &studentId);
                searchStudent(students, *numStudents, studentId);
                break;
            case 4:
                printf("Returning to main menu.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}