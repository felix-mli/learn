#include "person.h"
#include "felix_base.h"

Person* CreatePerson(const char*name, int age){
    Person* person = (Person*)malloc(sizeof(Person));
    if (person == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    memset(person, 0, sizeof(Person));
    strncpy(person->name, name, sizeof(person->name) - 1);
    person->age = age;
    return person;
}

void SetName(Person* person, const char*name){
    if (person == NULL || name == NULL) {
        printf("Invalid person or name\n");
        return;
    }
    strncpy(person->name, name, sizeof(person->name) - 1);
}

const char *GetName(Person* person){
    if (person == NULL) {
        printf("Invalid person\n");
        return NULL;
    }
    return person->name;
}

void SetAge(Person* person, int age){
    if (person == NULL) {
        printf("Invalid person\n");
        return;
    }
    person->age = age;
}

int GetAge(Person* person){
    if (person == NULL) {
        printf("Invalid person\n");
        return -1; // or some other error value
    }
    return person->age;
}

void DeletePerson(Person* person){
    if (person == NULL) {
        printf("Invalid person\n");
        return;
    }
    free(person);
}