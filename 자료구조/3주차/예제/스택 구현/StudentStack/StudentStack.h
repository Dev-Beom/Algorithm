#include "Student.h"
#include <iostream>

const int MAX_STACK_SIZE = 80;

class StudentStack
{
private:
    int top;
    Student data[MAX_STACK_SIZE];

public:
    StudentStack(/* args */);

    bool isEmpty();
    bool isFull();

    void push(Student e);
    Student pop();
    Student peek();
    void display();

    inline void error(char *message);
};

StudentStack::StudentStack(/* args */)
{
    top = -1;
}

bool StudentStack::isEmpty()
{
    return top == -1;
}
bool StudentStack::isFull()
{
    return top == MAX_STACK_SIZE - 1;
}

inline void StudentStack::error(char *message) //  오류 처리 함수
{
    printf("%s\n", message);
    exit(1);
}

void StudentStack::push(Student e)
{
    if (isFull())
    {
        error("스택 포화 에러");
    }
    data[++top] = e;
}
Student StudentStack::pop()
{
    if (isEmpty())
    {
        error("스택 공백 에러");
    }
    return data[top--];
}
Student StudentStack::peek()
{
    if (isEmpty())
    {
        error("스택 공백 에러");
    }
    return data[top];
}
void StudentStack::display()
{
    printf("[전체 학생의 수 = %2d]\n", top + 1);
    for (int i = 0; i <= top; i++)
    {
        data[i].display();
    }
    printf("\n");
}