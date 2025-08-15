#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"

struct TeacherFunc;

typedef struct {
    Person *person;
    double salary;
    struct TeacherFunc *func;
} Teacher;

struct TeacherFunc {
    Teacher* (*CreateTeacher)(const char* name, int age, double salary);
    void (*SetSalary)(Teacher* teacher, double salary);
    double (*GetSalary)(Teacher* teacher);
    void (*DeleteTeacher)(Teacher* teacher);
};

Teacher* CreateTeacher(const char* name, int age, double salary);
void SetSalary(Teacher* teacher, double salary);
double GetSalary(Teacher* teacher);
void DeleteTeacher(Teacher* teacher);

#endif