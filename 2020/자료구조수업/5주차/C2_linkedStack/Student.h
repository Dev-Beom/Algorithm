#pragma once
#include <stdio.h>
#include <string.h>
#define MAX_STRING 100

class Student
{
    int id;
    char name[MAX_STRING];
    char dept[MAX_STRING];

public:
    Student(int i = 0, char *nam = "", char *dep = "")
    {
        set(i, nam, dep);
    }
    void set(int i, char *nam = "", char *dep = "")
    {
        id = i;
        strcpy(name, nam);
        strcpy(dept, dep);
    }
    void display()
    {
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
    }
};