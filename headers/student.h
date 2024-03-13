#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define MAX_COURSES_PER_STUDENT 10  // Maximum number of courses a student can enroll in

struct Student {
    int id;
    char name[50];
    int age;
    int enrolledCourses[MAX_COURSES_PER_STUDENT];  // Array to store enrolled course IDs
    int numEnrolledCourses;  // Number of courses the student is currently enrolled in
};

void addStudent(struct Student students[], int *numStudents);
void displayStudents(struct Student students[], int numStudents);
void searchStudent(struct Student students[], int numStudents, int id);
void studentManagement(struct Student students[], int *numStudents) ;
#endif
