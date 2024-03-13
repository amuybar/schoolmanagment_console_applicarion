#include <stdio.h>
#include "course.h"
#include "student.h"

void addCourse(struct Course courses[], int *numCourses) {
    if (*numCourses >= MAX_COURSES) {
        printf("Maximum number of courses reached. Cannot add more courses.\n");
        return;
    }

    printf("Enter course ID: ");
    scanf("%d", &courses[*numCourses].id);
    printf("Enter course name: ");
    scanf("%s", courses[*numCourses].name);

    (*numCourses)++;
    printf("Course added successfully.\n");
}

void deleteCourse(struct Course courses[], int *numCourses, int courseId) {
    int found = 0;
    for (int i = 0; i < *numCourses; i++) {
        if (courses[i].id == courseId) {
            // Shift elements to fill the gap
            for (int j = i; j < *numCourses - 1; j++) {
                courses[j] = courses[j + 1];
            }
            (*numCourses)--;
            printf("Course with ID %d deleted successfully.\n", courseId);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Course with ID %d not found.\n", courseId);
    }
}

void searchCourse(struct Course courses[], int numCourses, int courseId) {
    int found = 0;
    for (int i = 0; i < numCourses; i++) {
        if (courses[i].id == courseId) {
            printf("Course found:\n");
            printf("ID\tName\n");
            printf("%d\t%s\n", courses[i].id, courses[i].name);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Course with ID %d not found.\n", courseId);
    }
}

void editCourse(struct Course courses[], int numCourses, int courseId) {
    int found = 0;
    for (int i = 0; i < numCourses; i++) {
        if (courses[i].id == courseId) {
            printf("Enter new course name: ");
            scanf("%s", courses[i].name);
            printf("Course information updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Course with ID %d not found.\n", courseId);
    }
}

void assignCourse(struct Student students[], int numStudents, int studentId, struct Course courses[], int numCourses, int courseId) {
    // Find the student with the given ID
    int studentIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == studentId) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex != -1) {
        // Check if the student can enroll in more courses
        if (students[studentIndex].numEnrolledCourses >= MAX_COURSES_PER_STUDENT) {
            printf("Student with ID %d cannot enroll in more courses.\n", studentId);
            return;
        }

        // Find the course with the given ID
        int courseIndex = -1;
        for (int i = 0; i < numCourses; i++) {
            if (courses[i].id == courseId) {
                courseIndex = i;
                break;
            }
        }

        if (courseIndex != -1) {
            // Check if the student is already enrolled in the course
            for (int i = 0; i < students[studentIndex].numEnrolledCourses; i++) {
                if (students[studentIndex].enrolledCourses[i] == courseId) {
                    printf("Student with ID %d is already enrolled in course with ID %d.\n", studentId, courseId);
                    return;
                }
            }

            // Enroll the student in the course
            students[studentIndex].enrolledCourses[students[studentIndex].numEnrolledCourses] = courseId;
            students[studentIndex].numEnrolledCourses++;
            printf("Student with ID %d enrolled in course with ID %d successfully.\n", studentId, courseId);
        } else {
            printf("Course with ID %d not found.\n", courseId);
        }
    } else {
        printf("Student with ID %d not found.\n", studentId);
    }
}

void courseManagement(struct Student students[], int numStudents, struct Course courses[], int *numCourses) {
    int choice;
    int courseId;
    int studentId;

    while (1) {
        printf("\nCourse Management:\n");
        printf("1. Add Course\n");
        printf("2. Delete Course\n");
        printf("3. Search Course by ID\n");
        printf("4. Edit Course\n");
        printf("5. Assign Course to Student\n");
        printf("6. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCourse(courses, numCourses);
                break;
            case 2:
                printf("Enter course ID to delete: ");
                scanf("%d", &courseId);
                deleteCourse(courses, numCourses, courseId);
                break;
            case 3:
                printf("Enter course ID to search: ");
                scanf("%d", &courseId);
                searchCourse(courses, *numCourses, courseId);
                break;
            case 4:
                printf("Enter course ID to edit: ");
                scanf("%d", &courseId);
                editCourse(courses, *numCourses, courseId);
                break;
            case 5:
                printf("Enter student ID: ");
                scanf("%d", &studentId);
                // Assuming you also input the course ID here
                int courseId;
                printf("Enter course ID to assign: ");
                scanf("%d", &courseId);
                assignCourse(students, numStudents, studentId, courses, *numCourses, courseId);
                break;
            case 6:
                printf("Returning to main menu.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}