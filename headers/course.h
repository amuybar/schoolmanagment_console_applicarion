#ifndef COURSE_H
#define COURSE_H

#include "student.h" // Include student.h for struct Student definition

#define MAX_COURSES 50

struct Course {
    int id;
    char name[50];
    // Additional fields for course information
};

void addCourse(struct Course courses[], int *numCourses);
void deleteCourse(struct Course courses[], int *numCourses, int courseId);
void searchCourse(struct Course courses[], int numCourses, int courseId);
void editCourse(struct Course courses[], int numCourses, int courseId);
void assignCourse(struct Student students[], int numStudents, int studentId, struct Course courses[], int numCourses, int courseId);

// Declare courseManagement function
void courseManagement(struct Student students[], int numStudents, struct Course courses[], int *numCourses);

#endif
