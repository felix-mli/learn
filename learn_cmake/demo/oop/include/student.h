#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

struct StudentFunc;

typedef struct{
    Person *person;
    double sources;
    struct StudentFunc *func;
} Student;

struct StudentFunc {
    Student* (*CreateStudent)(const char* name, int age, double sources);
    void (*SetSources)(Student* student, double sources);
    double (*GetSources)(Student* student);
    void (*DeleteStudent)(Student* student);
};

Student* CreateStudent(const char* name, int age, double sources);
void SetSources(Student* student, double sources);
double GetSources(Student* student);
void DeleteStudent(Student* student);

#endif