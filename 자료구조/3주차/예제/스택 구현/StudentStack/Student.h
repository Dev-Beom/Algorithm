#include <string.h>
#include <stdio.h>

const int MAX_STRING = 80;

class Student
{
private:
    int id;
    char name[MAX_STRING];
    char dept[MAX_STRING];

public:
    Student(int i = 0, char *n = "", char *d = "") { set(i, n, d); }

    void set(int i, char *n, char *d);
    void display();
};

void Student::set(int i, char *n, char *d)
{
    id = i;
    strcpy(name, n);
    strcpy(dept, d);
}

void Student::display()
{
    printf("  학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
}