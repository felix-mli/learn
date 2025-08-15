#include "person.h"
#include "student.h"
#include "person.h"
#include "felix_base.h"

int main(int argc, char argv[]) {
    Student *student;
    student = CreateStudent("felix",23, 100.0);
    if (student == NULL) {
        printf("Failed to create student\n");
        return -1;
    }
    printf("Student %s has sources: %.2f\n", student->person->name, GetSources(student));
    SetSources(student, 200.0);
    printf("Student %s has sources: %.2f\n", student->person->name, GetSources(student));
}