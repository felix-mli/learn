#include "felix_base.h"
#include "teacher.h"

Teacher* CreateTeacher(const char* name, int age, double salary) {
    if (name == NULL || age < 0 || salary < 0) {
        printf("Invalid parameters for creating teacher\n");
        return NULL;
    }
    Teacher* teacher = (Teacher*)malloc(sizeof(Teacher));
    if (teacher == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    memset(teacher, 0, sizeof(Teacher));
    teacher->person = CreatePerson(name, age);
    if (teacher->person == NULL) {
        free(teacher);
        return NULL;
    }
    teacher->salary = salary;
    return teacher;
}

void SetSalary(Teacher* teacher, double salary) {
    if (teacher == NULL || salary < 0) {
        printf("Invalid teacher or salary\n");
        return;
    }
    teacher->salary = salary;
}

double GetSalary(Teacher* teacher) {
    if (teacher == NULL) {
        printf("Invalid teacher\n");
        return -1; // or some other error value
    }
    return teacher->salary;
}

void DeleteTeacher(Teacher* teacher) {
    if (teacher == NULL) {
        printf("Invalid teacher\n");
        return;
    }
    if (teacher->person != NULL) {
        DeletePerson(teacher->person);
    }
    free(teacher);
}