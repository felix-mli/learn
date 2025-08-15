#ifndef PERSON_H
#define PERSON_H

struct PersonFunc;

typedef struct {
    char name[50];
    int age;

    struct PersonFunc* func;
} Person;

struct PersonFunc {
    Person*     (*CreatePerson)(const char* name, int age);
    void        (*SetName)(Person* person, const char* name);
    const char* (*GetName)(Person* person);
    void        (*SetAge)(Person* person, int age);
    int         (*GetAge)(Person* person);
    void        (*DeletePerson)(Person* person);
};

Person* CreatePerson(const char* name, int age);
void SetName(Person* person, const char* name);
const char* GetName(Person* person);
void SetAge(Person* person, int age);
int GetAge(Person* person);
void DeletePerson(Person* person);

#endif