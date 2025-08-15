#include "felix_base.h"
#include "student.h"

Student* CreateStudent(const char* name, int age, double sources) {
    if (name == NULL || age < 0 || sources < 0) {
        printf("Invalid parameters for creating student\n");
        return NULL;
    }
    Student* student = (Student*)malloc(sizeof(Student));
    if (student == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    memset(student, 0, sizeof(Student));
    student->person = CreatePerson(name, age);
    if (student->person == NULL) {
        free(student);
        return NULL;
    }
    student->sources = sources;
    return student;
}

void SetSources(Student* student, double sources) {
    if (student == NULL || sources < 0) {
        printf("Invalid student or sources\n");
        return;
    }
    student->sources = sources;
}

double GetSources(Student* student) {
    if (student == NULL) {
        printf("Invalid student\n");
        return -1; // or some other error value
    }
    return student->sources;
}

void DeleteStudent(Student* student) {
    if (student == NULL) {
        printf("Invalid student\n");
        return;
    }
    if (student->person != NULL) {
        DeletePerson(student->person);
    }
    free(student);
}